#include "struktury.h"

ruchy * krol(int Strona_kr, int KwadratZKtoregoRuszaSieBierka_kr, int RodzajBierkiBezWzgleduNakrlor_kr, ruchy * glowa_kr, szachownica *sz_kr){
    
    int Kierunek_kr, KwadratNaKtoryRuszaSieBierka_kr, ZbitaBierka_kr;
    
    Kierunek_kr = ListaRuchow[RodzajBierkiBezWzgleduNakrlor_kr+30];
    
    while(ListaRuchow[++Kierunek_kr] !=0){
        KwadratNaKtoryRuszaSieBierka_kr = KwadratZKtoregoRuszaSieBierka_kr + ListaRuchow[Kierunek_kr];
        ZbitaBierka_kr = sz_kr->szachownica[KwadratNaKtoryRuszaSieBierka_kr];
        if((!(ZbitaBierka_kr & Strona_kr)) && (!(KwadratNaKtoryRuszaSieBierka_kr & 0x88)))
            glowa_kr = ZrobListeRuchow(KwadratZKtoregoRuszaSieBierka_kr, KwadratNaKtoryRuszaSieBierka_kr, glowa_kr);
    }
    if((sz_kr->roszadaBialyKingSide == 1) && (Strona_kr == 8)){
        if(((sz_kr->szachownica[118])+(sz_kr->szachownica[117])) == 0){
            glowa_kr = ZrobListeRuchow(116, 118, glowa_kr);
        }
    }
    if((sz_kr->roszadaBialyQueenSide == 1) && (Strona_kr == 8)){
            
        if(((sz_kr->szachownica[115])+(sz_kr->szachownica[114])+(sz_kr->szachownica[113]))== 0){
            glowa_kr = ZrobListeRuchow(116, 114, glowa_kr);
        }
            
            //glowa_kr = ZrobListeRuchow(KwadratZKtoregoRuszaSieBierka_kr, KwadratNaKtoryRuszaSieBierka_kr, glowa_kr);
    }
    if((sz_kr->roszadaCzarnyKingSide == 1) && (Strona_kr == 16)){
        if((sz_kr->szachownica[5]+sz_kr->szachownica[6]) == 0){//dodac warunek wrogiej figury
            glowa_kr = ZrobListeRuchow(4, 6, glowa_kr);
        }
    }
    if((sz_kr->roszadaCzarnyQueenSide == 1) && (Strona_kr == 16)){
        if((sz_kr->szachownica[1]+sz_kr->szachownica[2]+sz_kr->szachownica[3])== 0){//dodac warunek wrogiej figury
            glowa_kr = ZrobListeRuchow(4, 2, glowa_kr);
        }
    }
            
            //glowa_kr = ZrobListeRuchow(KwadratZKtoregoRuszaSieBierka_kr, KwadratNaKtoryRuszaSieBierka_kr, glowa_kr);
    return glowa_kr;
}