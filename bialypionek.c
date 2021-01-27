#include "struktury.h"

ruchy * bialy_pionek(int KwadratZKtoregoRuszaPionek_bp, ruchy *glowa_bp, szachownica *sz_bp){
    int Strona_bp, Kierunek_bp, KwadratNaKtoryRuszaPionek_bp, ZbitaBierka_bp;
    Strona_bp = 8;
    Kierunek_bp = ListaRuchow[32];
    Kierunek_bp++;
    KwadratNaKtoryRuszaPionek_bp = KwadratZKtoregoRuszaPionek_bp + ListaRuchow[Kierunek_bp];
    ZbitaBierka_bp = sz_bp->szachownica[KwadratNaKtoryRuszaPionek_bp];
    
    if((ZbitaBierka_bp & 16) && (!(KwadratNaKtoryRuszaPionek_bp & 0x88))){
        glowa_bp = ZrobListeRuchow(KwadratZKtoregoRuszaPionek_bp, KwadratNaKtoryRuszaPionek_bp, glowa_bp);
    }
    KwadratNaKtoryRuszaPionek_bp = KwadratNaKtoryRuszaPionek_bp -2;
    ZbitaBierka_bp = sz_bp->szachownica[KwadratNaKtoryRuszaPionek_bp];
    if((ZbitaBierka_bp & 16) && (!(KwadratNaKtoryRuszaPionek_bp & 0x88))){
        glowa_bp = ZrobListeRuchow(KwadratZKtoregoRuszaPionek_bp, KwadratNaKtoryRuszaPionek_bp, glowa_bp);
    }
    Kierunek_bp++;
    KwadratNaKtoryRuszaPionek_bp = KwadratZKtoregoRuszaPionek_bp + ListaRuchow[Kierunek_bp];
    ZbitaBierka_bp = sz_bp->szachownica[KwadratNaKtoryRuszaPionek_bp];
    if(((!(ZbitaBierka_bp & 16)) && (!(ZbitaBierka_bp & 8)))){
        glowa_bp = ZrobListeRuchow(KwadratZKtoregoRuszaPionek_bp, KwadratNaKtoryRuszaPionek_bp, glowa_bp);
        if((KwadratZKtoregoRuszaPionek_bp >= 96) && (KwadratZKtoregoRuszaPionek_bp <= 103)){
            Kierunek_bp++;
            KwadratNaKtoryRuszaPionek_bp = KwadratZKtoregoRuszaPionek_bp + ListaRuchow[Kierunek_bp];
            ZbitaBierka_bp = sz_bp->szachownica[KwadratNaKtoryRuszaPionek_bp];
            if((!(ZbitaBierka_bp & 16)) && (!(ZbitaBierka_bp & 8))){
                glowa_bp = ZrobListeRuchow(KwadratZKtoregoRuszaPionek_bp, KwadratNaKtoryRuszaPionek_bp, glowa_bp);
                }
        }
    }
    return glowa_bp;
}