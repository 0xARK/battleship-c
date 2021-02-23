//
// Created by mateo on 10/02/2021.
//

#include "CBateau.h"

void testConstructeurVide();
void testConstructeurNormal();
void testTirAdverse();
void testEstCoule();
void testSetPosition();
void testGetDegats();
void testCopyConstructor();
void testEqualOperator();

int main() {

    testConstructeurVide();
    testConstructeurNormal();
    testTirAdverse();
    testEstCoule();
    testSetPosition();
    testGetDegats();
    testCopyConstructor();
    testEqualOperator();

}

void testConstructeurVide() {

    cout << "\n\n********** Test du constructeur vide **********\n\n" << endl;

    CBateau c1;
    cout << c1;

}

void testConstructeurNormal() {

    cout << "\n\n********** Test du constructeur normal **********" << endl;

    cout << "\n\nTest du constructeur valide : \n\n" << endl;
    CBateau c1("Name", make_pair(2, 3), 3);
    cout << c1;

    cout << "\n\nTest du constructeur avec des coordonnées invalides : \n\n" << endl;
    try {
        CBateau c2("Name", make_pair(12, -1), 1);
    } catch (invalid_argument error) {
        cout << "Error : " << error.what() << endl;
    }

}

void testTirAdverse() {

    cout << "\n\n********** Test de la méthode tirAdverse **********" << endl;

    cout << "\n\nTest avec le constructeur vide : \n\n" << endl;
    CBateau c1;
    cout << "Tir (qui lève une erreur) : " << endl;
    try {
        c1.tirAdverse(make_pair(2,3));
    } catch (range_error error) {
        cout << "Error : " << error.what() << endl;
    }

    cout << "\n\nTest avec le constructeur normal : \n\n" << endl;
    CBateau c2("Name", make_pair(2, 3), 1);
    cout << "Tir (qui touche) : " << c2.tirAdverse(make_pair(2,3)) << endl;
    cout << "Tir (qui ne touche pas) : " << c2.tirAdverse(make_pair(3,3)) << endl;

}

void testEstCoule() {

    cout << "\n\n********** Test de la méthode estCoule **********" << endl;

    cout << "\n\nTest avec le constructeur vide : \n\n" << endl;
    CBateau c1;
    cout << "Est coulé (lève une erreur) : " << endl;
    try {
        c1.estCoule();
    } catch (range_error error) {
        cout << "Error : " << error.what() << endl;
    }

    cout << "\n\nTest avec le constructeur normal : \n\n" << endl;
    CBateau c2("Name", make_pair(2, 3), 1);
    cout << "Est coulé (non) : " << c2.estCoule() << endl;
    cout << "On coule le bateau avec un tir" << endl;
    c2.tirAdverse(make_pair(2, 3));
    cout << "Est coulé (oui) : " << c2.estCoule() << endl;

    CBateau c3("Name", make_pair(4, 5), 1);
    cout << "\n\nEst coulé (non) : " << c3.estCoule() << endl;
    cout << "On coule le bateau avec un tir non valide : " << endl;
    try {
        c2.tirAdverse(make_pair(-1, 3));
    } catch (invalid_argument error) {
        cout << "Error : " << error.what() << endl;
    }
    cout << "Est coulé (non) : " << c3.estCoule() << endl;

}

void testSetPosition() {

    cout << "\n\n********** Test de la méthode setPosition **********" << endl;

    cout << "\n\nTest avec le constructeur vide : \n\n" << endl;
    CBateau c1;
    cout << "Get position : " << c1.getPosition().first << ", " << c1.getPosition().second << endl;
    cout << "Set position à 2, 3." << endl;
    c1.setPosition(2, 3);
    cout << "Get position : " << c1.getPosition().first << ", " << c1.getPosition().second << endl;

    CBateau c2;
    cout << "\n\nGet position : " << c2.getPosition().first << ", " << c2.getPosition().second << endl;
    cout << "Set position à -1, 3 (lève une erreur)." << endl;
    try {
        c2.setPosition(-1, 3);
    } catch (invalid_argument error) {
        cout << "Error : " << error.what() << endl;
    }
    cout << "Get position : " << c2.getPosition().first << ", " << c2.getPosition().second << endl;

    cout << "\n\nTest avec le constructeur normal : \n\n" << endl;
    CBateau c3("Name", make_pair(1, 1), 2);
    cout << "Get position : " << c3.getPosition().first << ", " << c3.getPosition().second << endl;
    cout << "Set position à 2, 3." << endl;
    c3.setPosition(2, 3);
    cout << "Get position : " << c3.getPosition().first << ", " << c3.getPosition().second << endl;

    CBateau c4("Name", make_pair(1, 1), 2);
    cout << "\n\nGet position : " << c4.getPosition().first << ", " << c4.getPosition().second << endl;
    cout << "Set position à -1, 3 (lève une erreur)." << endl;
    try {
        c4.setPosition(-1, 3);
    } catch (invalid_argument error) {
        cout << "Error : " << error.what() << endl;
    }
    cout << "Get position : " << c4.getPosition().first << ", " << c4.getPosition().second << endl;

}

void testGetDegats() {

    cout << "\n\n********** Test de la méthode getDegats **********" << endl;

    cout << "\n\nTest avec le constructeur vide : \n\n" << endl;
    CBateau c1;
    try {
        cout << "Get degats (lève une erreur) : " << endl;
        cout << c1.getDegats(0) << endl;
    } catch (range_error error) {
        cout << "Error : " << error.what() << endl;
    }

    cout << "\n\nTest avec le constructeur normal : \n\n" << endl;
    CBateau c2("Name", make_pair(1, 1), 2);
    cout << "Get degats (renvoie false) : " << c2.getDegats(0) << endl;
    c2.tirAdverse(make_pair(1, 1));
    cout << "Get degats (renvoie true) : " << c2.getDegats(0) << endl;

    CBateau c3("Name", make_pair(1, 1), 2);
    try {
        cout << "\n\nGet degats (lève une erreur) : " << c3.getDegats(-1) << endl;
    } catch (invalid_argument error) {
        cout << "\nError : " << error.what() << endl;
    }

}

void testCopyConstructor() {

    cout << "\n\n********** Test du copy constructeur **********" << endl;

    cout << "\n\nTest avec le constructeur vide : \n\n" << endl;
    CBateau c1;
    cout << c1;
    cout << "\nCopie du bateau : \n" << endl;
    CBateau c2(c1);
    cout << c2;

    cout << "\n\nTest avec le constructeur normal : \n\n" << endl;
    CBateau c3("Name", make_pair(1, 2), 3);
    cout << c3;
    cout << "\nCopie du bateau : \n" << endl;
    CBateau c4(c3);
    cout << c4;

}

void testEqualOperator() {

    cout << "\n\n********** Test de la surcharge de l'opérateur égal **********\n\n" << endl;

    CBateau c1;
    cout << c1;
    cout << "\nCopie du bateau avec l'opérateur égal : \n" << endl;
    CBateau c2 = c1;
    cout << c2;

    cout << "\n\nTest avec le constructeur normal : \n\n" << endl;
    CBateau c3("Name", make_pair(1, 2), 3);
    cout << c3;
    cout << "\nCopie du bateau avec l'opérateur égal : \n" << endl;
    CBateau c4 = c3;
    cout << c4;

}