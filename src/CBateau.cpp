//
// Created by mateo on 10/02/2021.
//

#include "CBateau.h"

/**
 * Allows to create an empty ship
 */
CBateau::CBateau() {

    m_nom = "neant";
    m_position = make_pair(0, 0);
    m_taille = 0;
    m_pDegats = NULL;

}

/**
 * Allows to create a ship
 *
 * @param n - name of ship
 * @param p - placement coordinates of ship
 * @param t - size of ship
 */
CBateau::CBateau(string n, pair<int, int> p, int t) {

    if (p.first < 0 || p.second < 0 || p.first > TAILLE_GRILLE - 2 || p.second > TAILLE_GRILLE - 2)
        throw invalid_argument("Ship coordinates are out of grid.");

    if (t <= 0 || t > TAILLE_GRILLE - 2)
        throw invalid_argument("Ship size is too small or too high.");

    if (t + p.first > TAILLE_GRILLE - 2)
        throw invalid_argument("Ship placement is out of grid.");

    m_nom = n;
    m_position = make_pair(p.first, p.second);
    m_taille = t;
    m_pDegats = new bool[t];
    for (int i = 0; i < t; i++) {
        m_pDegats[i] = false;
    }

}

/**
 * Allows to create a copy of a ship
 *
 * @param bateau - ship to copy
 */
CBateau::CBateau(const CBateau &bateau) {

    if (bateau.m_pDegats != NULL) {
        m_pDegats = new bool[bateau.m_taille];
        for (int i = 0; i < bateau.m_taille; i++) {
            m_pDegats[i] = bateau.m_pDegats[i];
        }
    } else {
        m_pDegats = NULL;
    }

    m_taille = bateau.m_taille;
    m_position = bateau.m_position;
    m_nom = bateau.m_nom;

}

/**
 * Allows to check if a case of this ship is hit
 *
 * @param i - case of ship to check
 * @return true if case is hit or false
 */
bool CBateau::getDegats(int i) {

    if (i < 0 || i > m_taille) throw invalid_argument("Damage of case i is out of bound.");
    if (m_pDegats == NULL) throw range_error("Ship 'degat' array is not initialized.");

    bool degat = false;

    if (i >= 0 && i < m_taille) {
        degat = m_pDegats[i];
    }

    return degat;

}

string CBateau::getNom() {

    return m_nom;

}

int CBateau::getTaille() {

    return m_taille;

}

pair<int, int> CBateau::getPosition() {

    return m_position;

}

/**
 * Allows to change placement coordinates of this ship
 *
 * @param i - x coordinate
 * @param j - y coordinate
 */
void CBateau::setPosition(int i, int j) {

    if (i < 0 || j < 0 || i > TAILLE_GRILLE - 2 || j > TAILLE_GRILLE - 2)
        throw invalid_argument("Ship coordinates are out of grid.");

    if (m_taille + i > TAILLE_GRILLE - 2)
        throw invalid_argument("Ship placement is out of grid.");

    m_position = make_pair(i, j);

}

/**
 * Allows to check if this ship is sunk
 *
 * @return true if this ship is sunk or false
 */
bool CBateau::estCoule() {

    if (m_taille <= 0) throw range_error("Ship size is less than or equal to 0.");
    if (m_pDegats == NULL) throw range_error("Ship 'degat' array is not initialized.");

    bool coule = true;
    int i = 0;

    while (i < m_taille && coule) {
        if (!m_pDegats[i]) {
            coule = false;
        }
        i++;
    }

    return coule;

}

/**
 * Allows to make a shoot and see if this ship is hit
 *
 * @param p - shoot coordinates
 * @return - true if ship is hit or false
 */
bool CBateau::tirAdverse(pair<int, int> p) {

    if (m_taille <= 0) throw range_error("Ship size is less than or equal to 0.");
    if (m_pDegats == NULL) throw range_error("Ship 'degat' array is not initialized.");
    if (p.first < 0 || p.second < 0 || p.first > TAILLE_GRILLE - 2 || p.second > TAILLE_GRILLE - 2)
        throw invalid_argument("Shoot coordinates are out of grid");

    bool touche = false;

    int min_x = m_position.first;
    int max_x = m_position.first + m_taille;
    int min_y = m_position.second;

    // ship are placed horizontally
    if (p.second == min_y && p.first >= min_x && p.first < max_x) {
        int index = p.first - min_x;
        if (!m_pDegats[index]) {
            m_pDegats[index] = true;
            touche = true;
        }
    }

    return touche;

}

/**
 * Allows to display characteristics of a ship
 *
 * @param os - stream to write
 * @param theB - ship whose characteristics are to be displayed
 * @return stream written
 */

ostream& operator<<(ostream& os, CBateau& theB) {

    os << "Ship caracteristics : " << endl;
    os << "Name : " << theB.getNom() << endl;
    os << "Size : " << theB.getTaille() << endl;
    os << "X coordinate : " << theB.getPosition().first << endl;
    os << "Y coordinate : " << theB.getPosition().second << endl;

    return os;

}

/**
 * Allows to copy a ship into another ship with equal operator
 *
 * @param bateau - ship to copy
 */
void CBateau::operator=(const CBateau &bateau) {

    if (bateau.m_pDegats != NULL) {
        m_pDegats = new bool[bateau.m_taille];
        for (int i = 0; i < bateau.m_taille; i++) {
            m_pDegats[i] = bateau.m_pDegats[i];
        }
    } else {
        m_pDegats = NULL;
    }

    m_taille = bateau.m_taille;
    m_position = bateau.m_position;
    m_nom = bateau.m_nom;

}

/**
 * Allows to destroy array of damage for this ship
 */
CBateau::~CBateau() {

    if (m_pDegats != NULL) delete[] m_pDegats;

}