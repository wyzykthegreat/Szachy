#include "struktury.h"

ruchy * czarny_pionek(int KwadratZKtoregoRuszaPionek_cp, ruchy *glowa_cp, szachownica *sz_cp){
    int Strona_cp, Kierunek_cp, KwadratNaKtoryRuszaPionek_cp, ZbitaBierka_cp;
    Strona_cp = 16;
    Kierunek_cp = ListaRuchow[31];
    Kierunek_cp++;
    KwadratNaKtoryRuszaPionek_cp = KwadratZKtoregoRuszaPionek_cp + ListaRuchow[Kierunek_cp];
    ZbitaBierka_cp = sz_cp->szachownica[KwadratNaKtoryRuszaPionek_cp];
    
    if((ZbitaBierka_cp & 8) && (!(KwadratNaKtoryRuszaPionek_cp & 0x88))){
        glowa_cp = ZrobListeRuchow(KwadratZKtoregoRuszaPionek_cp, KwadratNaKtoryRuszaPionek_cp, glowa_cp);
    }

    KwadratNaKtoryRuszaPionek_cp = KwadratNaKtoryRuszaPionek_cp +2;
    ZbitaBierka_cp = sz_cp->szachownica[KwadratNaKtoryRuszaPionek_cp];

    if((ZbitaBierka_cp & 8) && (!(KwadratNaKtoryRuszaPionek_cp & 0x88))){
        glowa_cp = ZrobListeRuchow(KwadratZKtoregoRuszaPionek_cp, KwadratNaKtoryRuszaPionek_cp, glowa_cp);
    }

    Kierunek_cp++;
    KwadratNaKtoryRuszaPionek_cp = KwadratZKtoregoRuszaPionek_cp + ListaRuchow[Kierunek_cp];
    ZbitaBierka_cp = sz_cp->szachownica[KwadratNaKtoryRuszaPionek_cp];
    if((!(ZbitaBierka_cp & 16)) && (!(ZbitaBierka_cp & 8))){
        glowa_cp = ZrobListeRuchow(KwadratZKtoregoRuszaPionek_cp, KwadratNaKtoryRuszaPionek_cp, glowa_cp);
        if((KwadratZKtoregoRuszaPionek_cp >= 16) && (KwadratZKtoregoRuszaPionek_cp <= 23)){
            Kierunek_cp++;
            KwadratNaKtoryRuszaPionek_cp = KwadratZKtoregoRuszaPionek_cp + ListaRuchow[Kierunek_cp];
            ZbitaBierka_cp = sz_cp->szachownica[KwadratNaKtoryRuszaPionek_cp];
            if((!(ZbitaBierka_cp & 16)) && (!(ZbitaBierka_cp & 8))){
                glowa_cp = ZrobListeRuchow(KwadratZKtoregoRuszaPionek_cp, KwadratNaKtoryRuszaPionek_cp, glowa_cp);
            }
        }
    }
    return glowa_cp;
}