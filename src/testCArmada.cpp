//
// Created by mateo on 23/02/2021.
//

# include "CArmada.h"

void testAjouterBateau();
void testEffectifTotal();
void testNbrTotCases();
void testEffectif();

int main() {

    testAjouterBateau();
    testEffectifTotal();
    testNbrTotCases();
    testEffectif();

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
    cout << a.getBateau(0)->estCoule();

    if (a.getEffectif() == 1) {
        cout << "OK : L'armada compte bien un bateau coulé." << endl;
    } else {
        cout << "ERREUR : L'armada compte plus ou moins d'un bateau coulé." << endl;
    }

}