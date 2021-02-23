//
// Created by mateo on 17/02/2021.
//

#ifndef TP_CARMADA_H
#define TP_CARMADA_H

#include <iterator>

#include "BiblioStd.h"
#include "CBateau.h"

class CArmada {

    public:
        vector<CBateau> m_listeBateaux;

    public:
        void ajouterBateau(CBateau& unBat);
        CBateau* getBateau(int i);
        int getEffectifTotal();
        int getNbreTotCases();
        int getEffectif();
        void getArmadaFromFile();
        bool placerAleatoirement();

};


#endif //TP_CARMADA_H
