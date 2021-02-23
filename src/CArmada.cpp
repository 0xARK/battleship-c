//
// Created by mateo on 17/02/2021.
//

#include "CArmada.h"

/**
 * Allows to add a ship into this armada
 *
 * @param unBat - ship to add
 */
void CArmada::ajouterBateau(CBateau &unBat) {

    if (&m_listeBateaux == NULL)
        throw range_error("Can't add a ship into a null armada array.");

    m_listeBateaux.push_back(unBat);

}

/**
 * Allows to get a ship from this aramda
 *
 * @param i - index i of ship to get
 * @return the ship at index i
 */
CBateau* CArmada::getBateau(int i) {

    if (i < 0 || i > (int)m_listeBateaux.size())
        throw invalid_argument("Trying to get a ship out of armada array.");

    return &m_listeBateaux[i];

}

/**
 * Allows to get number of ship into this armada
 *
 * @return number of ship into this armada
 */
int CArmada::getEffectifTotal() {

    if (&m_listeBateaux == NULL)
        throw range_error("Can't get ship number of a null armada.");

    return m_listeBateaux.size();

}

/**
 * Allows to get total number of cases used by all ships of this armada
 *
 * @return number of cases used by all ships of this armada
 */
int CArmada::getNbreTotCases() {

    if (&m_listeBateaux == NULL)
        throw range_error("Can't get total number case of a null armada.");

    int nb = 0;

    for (int i = 0; i < (int)m_listeBateaux.size(); i++) {
        nb += m_listeBateaux[i].getTaille();
    }

    return nb;

}

/**
 * Allows to get number of ship not sunk in this armada
 *
 * @return number of ship not sunk in this armada
 */
int CArmada::getEffectif() {

    if (&m_listeBateaux == NULL)
        throw range_error("Can't get number of ship not sunk in a null armada.");

    int nb = 0;

    for (int i = 0; i < (int)m_listeBateaux.size(); i++) {
        if (!m_listeBateaux[i].estCoule()) {
            nb++;
        }
    }

    return nb;

}

/**
 * Allows to fill in armada vector with an armada config file
 */
void CArmada::getArmadaFromFile() {

    string filename = "../data/flotille.txt";

    string line;
    ifstream input;
    input.open ( filename.c_str(), ios::in );

    while (!input.eof()) {

        getline ( input, line, '\n' );
        cout << "[I] " << line << endl;

        if (line.at(0) != '#') {

            istringstream buf(line);
            istream_iterator<std::string> beg(buf), end;
            std::vector<std::string> tokens(beg, end);

            string nom = tokens[0];
            string nbBateau = tokens[1];
            string taille = tokens[2];

            int nbBateauInt = stoi(nbBateau);
            int tailleInt = stoi(taille);

            if (nbBateauInt >= 1) {
                for(int i = 0; i <= nbBateauInt - 1; i++){
                    pair<int, int> p;
                    p.first = 0;
                    p.second = 0;
                    CBateau b(nom, p, tailleInt);
                    this->ajouterBateau(b);
                }
            }

        }

    }

    input.close();

}

/**
 * Allows to randomly place all the ships of this armada on the game grid.
 *
 * @return true if all the boats could be placed, false if not
 */
bool CArmada::placerAleatoirement() {

    srand( (unsigned)time(NULL));
    int borneSup = TAILLE_GRILLE - 2;

    if(this->getNbreTotCases() > borneSup*borneSup){
        return false;
    }

    vector<pair<int, int>> busy_cases;
    int error = 0;

    for(int i = 0; i < (int)m_listeBateaux.size(); i++){

        int x = rand()%(borneSup + 1);
        int y = rand()%(borneSup + 1);

        int j = 0;
        bool found = true;

        if (x + this->m_listeBateaux[i].getTaille() > borneSup) {
            found = false;
        } else if (i > 0) {

            while(found and j <= (int)busy_cases.size()){

                for(int k = 0; k < this->m_listeBateaux[i].getTaille(); k++){

                    if(busy_cases[j].first == x+k and busy_cases[j].second == y){
                        found = false;
                    }

                }

                j++;

            }
        }

        if (found) {

            for(int j = 0; j < this->m_listeBateaux[i].getTaille(); j++){
                busy_cases.push_back(make_pair(x+j,y));
            }

            this->m_listeBateaux[i].setPosition(x,y);

            i++;

        } else {

            error++;

            if (error >= MAXESSAIS) {
                return false;
            }

        }

    }

    return true;

}