#include "struktury.h"

ruchy * krol_kon(int Strona_kk, int KwadratZKtoregoRuszaSieBierka_kk, int RodzajBierkiBezWzgleduNaKolor_kk, ruchy * glowa_kk, szachownica *sz_kk){
    
    int Kierunek_kk, KwadratNaKtoryRuszaSieBierka_kk, ZbitaBierka_kk;
    
    Kierunek_kk = ListaRuchow[RodzajBierkiBezWzgleduNaKolor_kk+30];
    
    while(ListaRuchow[++Kierunek_kk] !=0){
        KwadratNaKtoryRuszaSieBierka_kk = KwadratZKtoregoRuszaSieBierka_kk + ListaRuchow[Kierunek_kk];
        ZbitaBierka_kk = sz_kk->szachownica[KwadratNaKtoryRuszaSieBierka_kk];
        if((!(ZbitaBierka_kk & Strona_kk)) && (!(KwadratNaKtoryRuszaSieBierka_kk & 0x88)))
            glowa_kk = ZrobListeRuchow(KwadratZKtoregoRuszaSieBierka_kk, KwadratNaKtoryRuszaSieBierka_kk, glowa_kk);
    }
    return glowa_kk;
}