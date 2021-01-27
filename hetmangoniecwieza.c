#include "struktury.h"

ruchy * hetman_goniec_wieza(int Strona_hgw, int KwadratZKtoregoRuszaSieBierka_hgw, int RodzajBierkiBezWzgleduNaKolor_hgw, ruchy * glowa_hgw, szachownica *sz_hgw){
    
    int Kierunek_hgw, KwadratNaKtoryRuszaSieBierka_hgw, ZbitaBierka_hgw;
    
    Kierunek_hgw = ListaRuchow[RodzajBierkiBezWzgleduNaKolor_hgw+30];
    while(ListaRuchow[++Kierunek_hgw] !=0){
        KwadratNaKtoryRuszaSieBierka_hgw = KwadratZKtoregoRuszaSieBierka_hgw + ListaRuchow[Kierunek_hgw];
        ZbitaBierka_hgw = sz_hgw->szachownica[KwadratNaKtoryRuszaSieBierka_hgw];
        while((ZbitaBierka_hgw == 0) && (!(KwadratNaKtoryRuszaSieBierka_hgw & 0x88))){
            glowa_hgw = ZrobListeRuchow(KwadratZKtoregoRuszaSieBierka_hgw, KwadratNaKtoryRuszaSieBierka_hgw, glowa_hgw); 
            KwadratNaKtoryRuszaSieBierka_hgw += ListaRuchow[Kierunek_hgw];
            ZbitaBierka_hgw = sz_hgw->szachownica[KwadratNaKtoryRuszaSieBierka_hgw];
        }
        if((!(ZbitaBierka_hgw & Strona_hgw)) && (!(KwadratNaKtoryRuszaSieBierka_hgw & 0x88))){
            glowa_hgw = ZrobListeRuchow(KwadratZKtoregoRuszaSieBierka_hgw, KwadratNaKtoryRuszaSieBierka_hgw, glowa_hgw);        }
    }
    return glowa_hgw;
}