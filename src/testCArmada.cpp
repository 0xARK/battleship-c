//
// Created by mateo on 23/02/2021.
//

# include "CArmada.h"

void testAjouterBateau();
void testEffectifTotal();
void testNbrTotCases();
void testEffectif();
void testArmadaFromFile();
void testPlacerAleatoirement();

int main() {

    testAjouterBateau();
    testEffectifTotal();
    testNbrTotCases();
    testEffectif();
    testArmadaFromFile();
    testPlacerAleatoirement();

}

void testAjouterBateau() {

    cout << "\n\n********** Test de la méthode ajouterBateau **********\n\n" << endl;

    CArmada a;
    CBateau b1("b1", make_pair(0, 0), 1);
    CBateau b2("b2", make_pair(0, 1), 1);
    CBateau b3("b3", make_pair(0, 2), 1);

    cout << "Bateaux créés :\n" << endl;
    cout << b1 << endl;
    cout << b2 << endl;
    cout << b3 << endl;

    cout << "On les ajoute à la flotte." << endl;

    a.ajouterBateau(b1);
    a.ajouterBateau(b2);
    a.ajouterBateau(b3);

    if (a.getBateau(0)->getNom() == b1.getNom() && a.getBateau(1)->getNom() == b2.getNom() && a.getBateau(2)->getNom() == b3.getNom()) {
        cout << "OK : Les 3 bateaux ont bien été ajoutés." << endl;
    } else {
        cout << "ERREUR : Les 3 bateaux n'ont pas pu être ajoutés." << endl;
    }

}

void testEffectifTotal() {

    cout << "\n\n********** Test de la méthode getEffectifTotal **********\n\n" << endl;

    CArmada a;
    CBateau b1("b1", make_pair(0, 0), 1);
    CBateau b2("b2", make_pair(0, 1), 1);

    cout << "Bateaux créés :\n" << endl;
    cout << b1 << endl;
    cout << b2 << endl;

    cout << "On les ajoute à la flotte." << endl;

    a.ajouterBateau(b1);
    a.ajouterBateau(b2);

    if (a.getEffectifTotal() == 2) {
        cout << "OK : L'armada compte bien 2 bateaux." << endl;
    } else {
        cout << "ERREUR : L'armada ne compte pas 2 bateaux." << endl;
    }

}

void testNbrTotCases() {

    cout << "\n\n********** Test de la méthode getNbrTotCases **********\n\n" << endl;

    CArmada a;
    CBateau b1("b1", make_pair(0, 0), 1);
    CBateau b2("b2", make_pair(0, 1), 1);

    cout << "Bateaux créés :\n" << endl;
    cout << b1 << endl;
    cout << b2 << endl;

    cout << "On les ajoute à la flotte." << endl;

    a.ajouterBateau(b1);
    a.ajouterBateau(b2);

    if (a.getNbreTotCases() == 2) {
        cout << "OK : Les bateaux de l'armada occupent bien en tout 2 cases." << endl;
    } else {
        cout << "ERREUR : Les bateaux de l'armada n'occupent pas 2 cases en tout." << endl;
    }

}

void testEffectif() {

    cout << "\n\n********** Test de la méthode getEffectif **********\n\n" << endl;

    CArmada a;
    CBateau b1 = CBateau("b1", make_pair(0, 0), 1);
    CBateau b2 = CBateau("b2", make_pair(0, 1), 1);

    cout << "Bateaux créés :\n" << endl;
    cout << b1 << endl;
    cout << b2 << endl;

    cout << "On les ajoute à la flotte." << endl;

    a.ajouterBateau(b1);
    a.ajouterBateau(b2);

    cout << "On en coule un." << endl;
    a.getBateau(0)->tirAdverse(make_pair(0, 0));

    if (a.getEffectif() == 1) {
        cout << "OK : L'armada compte bien un bateau coulé." << endl;
    } else {
        cout << "ERREUR : L'armada compte plus ou moins d'un bateau coulé." << endl;
    }

}

void testArmadaFromFile() {

    cout << "\n\n********** Test de la méthode getArmadaFromFile **********\n\n" << endl;

    cout << "On écrit dans le fichier de configuration." << endl;

    // Write in the file
    // Ecrit dans le fichier
    ofstream flotille;
    flotille.open ("/home/mateo/Documents/cours/2a/M4105C/TP/BatailleNavale/data/flotille.txt");
    flotille << "# Ceci est un commentaire\n";
    flotille << "# This is a comment\n";
    flotille << "sous-marin 2 5\n";
    flotille << "FREMM 1 2\n";
    flotille << "FLF 3 2\n";
    flotille << "FAA 1 2";
    flotille.close();

    cout << "On récupère l'armada." << endl;

    CArmada armada;
    armada.getArmadaFromFile();

    if (armada.getEffectifTotal() == 7) {
        cout << "OK : L'armada compte bien 7 bateaux." << endl;
    } else {
        cout << "ERREUR : L'armada ne compte pas 7 bateaux." << endl;
    }

}

void testPlacerAleatoirement() {

    cout << "\n\n********** Test de la méthode placerAleatoirement **********\n\n" << endl;

    cout << "On crée et on ajoute des bateaux à l'armada." << endl;

    CArmada armada;
    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    cout << "On place les bateaux aléatoirement." << endl;

    bool result = armada.placerAleatoirement();

    if (result) {
        cout << "OK : L'armada a pu être placée aléatoirement." << endl;
    } else {
        cout << "ERREUR : L'armada n'a pas pu être placée aléatoirement." << endl;
    }

}