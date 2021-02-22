//
// Created by mateo on 10/02/2021.
//

#ifndef TP_CBATEAU_H
#define TP_CBATEAU_H

#include "BiblioStd.h"

class CBateau {

    private:
        int m_taille;
        string m_nom;
        pair<int, int> m_position;
        bool* m_pDegats;

    public:
        CBateau();
        CBateau(string n, pair<int, int> p, int t);
        CBateau(const CBateau &bateau);
        bool getDegats(int i);
        string getNom();
        int getTaille();
        pair<int, int> getPosition();
        void setPosition(int i, int j);
        bool estCoule();
        bool tirAdverse(pair<int, int> p);
        friend ostream& operator<< (ostream& os, CBateau& theB);
        void operator=(const CBateau &bateau);
        ~CBateau();

};


#endif //TP_CBATEAU_H
