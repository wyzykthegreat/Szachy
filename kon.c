#include "struktury.h"

ruchy * kon(int Strona_ko, int KwadratZKtoregoRuszaSieBierka_ko, int RodzajBierkiBezWzgleduNaKolor_ko, ruchy * glowa_ko, szachownica *sz_ko){
    
    int Kierunek_ko, KwadratNaKtoryRuszaSieBierka_ko, ZbitaBierka_ko;
    
    Kierunek_ko = ListaRuchow[RodzajBierkiBezWzgleduNaKolor_ko+30];
    
    while(ListaRuchow[++Kierunek_ko] !=0){
        KwadratNaKtoryRuszaSieBierka_ko = KwadratZKtoregoRuszaSieBierka_ko + ListaRuchow[Kierunek_ko];
        ZbitaBierka_ko = sz_ko->szachownica[KwadratNaKtoryRuszaSieBierka_ko];
        if((!(ZbitaBierka_ko & Strona_ko)) && (!(KwadratNaKtoryRuszaSieBierka_ko & 0x88)))
            glowa_ko = ZrobListeRuchow(KwadratZKtoregoRuszaSieBierka_ko, KwadratNaKtoryRuszaSieBierka_ko, glowa_ko);
    }
    return glowa_ko;
}