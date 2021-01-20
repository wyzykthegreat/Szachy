#include <stdio.h>
#include <string.h>
#include "struktury.h"



void WypiszPlansze(){
    for(int Pole = 0; Pole < 128; Pole++){
        if(!(Pole % 16)){
            printf(" %d. ", 8 - ( Pole / 16 ));
        }
        printf(" %s", ((Pole & 8) && (Pole +=7)) ? "\n" : Bierki[Plansza[Pole] & 15]);
    }
    printf("\n     a b c d e f g h\n\nTwoj ruch: \n");
}

int PrzypiszBierke(int KwadratZKtoregoRuszaPionek){
    int BierkaJakaZnajdujeSieNaPolu;
    BierkaJakaZnajdujeSieNaPolu = Plansza[KwadratZKtoregoRuszaPionek];

    return BierkaJakaZnajdujeSieNaPolu;
}

void bialy_pionek(int KwadratZKtoregoRuszaPionek_bp){
    int Strona_bp, Kierunek_bp, KwadratNaKtoryRuszaPionek_bp, ZbitaBierka_bp;
    Strona_bp = 8;
    Kierunek_bp = ListaRuchow[32];
    Kierunek_bp++;
    KwadratNaKtoryRuszaPionek_bp = KwadratZKtoregoRuszaPionek_bp + ListaRuchow[Kierunek_bp];
    ZbitaBierka_bp = Plansza[KwadratNaKtoryRuszaPionek_bp];
    
    if((ZbitaBierka_bp & 16) && (!(KwadratNaKtoryRuszaPionek_bp & 0x88))){
        printf("%s%s\n", notacja[KwadratZKtoregoRuszaPionek_bp], notacja[KwadratNaKtoryRuszaPionek_bp]);
    }
    KwadratNaKtoryRuszaPionek_bp = KwadratNaKtoryRuszaPionek_bp -2;
    ZbitaBierka_bp = Plansza[KwadratNaKtoryRuszaPionek_bp];
    if((ZbitaBierka_bp & 16) && (!(KwadratNaKtoryRuszaPionek_bp & 0x88))){
        printf("%s%s\n", notacja[KwadratZKtoregoRuszaPionek_bp], notacja[KwadratNaKtoryRuszaPionek_bp]);
    }
    Kierunek_bp++;
    KwadratNaKtoryRuszaPionek_bp = KwadratZKtoregoRuszaPionek_bp + ListaRuchow[Kierunek_bp];
    ZbitaBierka_bp = Plansza[KwadratNaKtoryRuszaPionek_bp];
    if(((!(ZbitaBierka_bp & 16)) && (!(ZbitaBierka_bp & 8)))){
        printf("%s%s\n", notacja[KwadratZKtoregoRuszaPionek_bp], notacja[KwadratNaKtoryRuszaPionek_bp]);
        if((KwadratZKtoregoRuszaPionek_bp >= 96) && (KwadratZKtoregoRuszaPionek_bp <= 103)){
            Kierunek_bp++;
            KwadratNaKtoryRuszaPionek_bp = KwadratZKtoregoRuszaPionek_bp + ListaRuchow[Kierunek_bp];
            ZbitaBierka_bp = Plansza[KwadratNaKtoryRuszaPionek_bp];
            if((!(ZbitaBierka_bp & 16)) && (!(ZbitaBierka_bp & 8))){
                printf("%s%s\n", notacja[KwadratZKtoregoRuszaPionek_bp], notacja[KwadratNaKtoryRuszaPionek_bp]);
            }
        }
    }
}

void czarny_pionek(int KwadratZKtoregoRuszaPionek_cp){
    int Strona_cp, Kierunek_cp, KwadratNaKtoryRuszaPionek_cp, ZbitaBierka_cp;
    Strona_cp = 16;
    Kierunek_cp = ListaRuchow[31];
    Kierunek_cp++;
    KwadratNaKtoryRuszaPionek_cp = KwadratZKtoregoRuszaPionek_cp + ListaRuchow[Kierunek_cp];
    ZbitaBierka_cp = Plansza[KwadratNaKtoryRuszaPionek_cp];
    
    if((ZbitaBierka_cp & 8) && (!(KwadratNaKtoryRuszaPionek_cp & 0x88))){
        printf("%s%s\n", notacja[KwadratZKtoregoRuszaPionek_cp], notacja[KwadratNaKtoryRuszaPionek_cp]);
    }
    KwadratNaKtoryRuszaPionek_cp = KwadratNaKtoryRuszaPionek_cp +2;
    ZbitaBierka_cp = Plansza[KwadratNaKtoryRuszaPionek_cp];
    if((ZbitaBierka_cp & 8) && (!(KwadratNaKtoryRuszaPionek_cp & 0x88))){
        printf("%s%s\n", notacja[KwadratZKtoregoRuszaPionek_cp], notacja[KwadratNaKtoryRuszaPionek_cp]);
    }
    Kierunek_cp++;
    KwadratNaKtoryRuszaPionek_cp = KwadratZKtoregoRuszaPionek_cp + ListaRuchow[Kierunek_cp];
    ZbitaBierka_cp = Plansza[KwadratNaKtoryRuszaPionek_cp];
    if((!(ZbitaBierka_cp & 16)) && (!(ZbitaBierka_cp & 8))){
        printf("%s%s\n", notacja[KwadratZKtoregoRuszaPionek_cp], notacja[KwadratNaKtoryRuszaPionek_cp]);
        if((KwadratZKtoregoRuszaPionek_cp >= 16) && (KwadratZKtoregoRuszaPionek_cp <= 23)){
            Kierunek_cp++;
            KwadratNaKtoryRuszaPionek_cp = KwadratZKtoregoRuszaPionek_cp + ListaRuchow[Kierunek_cp];
            ZbitaBierka_cp = Plansza[KwadratNaKtoryRuszaPionek_cp];
            if((!(ZbitaBierka_cp & 16)) && (!(ZbitaBierka_cp & 8))){
                printf("%s%s\n", notacja[KwadratZKtoregoRuszaPionek_cp], notacja[KwadratNaKtoryRuszaPionek_cp]);
            }
        }
    }
}

void hetman_goniec_wieza(int Strona_hgw, int KwadratZKtoregoRuszaSieBierka_hgw, int RodzajBierkiBezWzgleduNaKolor_hgw){
    
    int Kierunek_hgw, KwadratNaKtoryRuszaSieBierka_hgw, ZbitaBierka_hgw;
    
    Kierunek_hgw = ListaRuchow[RodzajBierkiBezWzgleduNaKolor_hgw+30];
    while(ListaRuchow[++Kierunek_hgw] !=0){
        KwadratNaKtoryRuszaSieBierka_hgw = KwadratZKtoregoRuszaSieBierka_hgw + ListaRuchow[Kierunek_hgw];
        ZbitaBierka_hgw = Plansza [KwadratNaKtoryRuszaSieBierka_hgw];
        while((ZbitaBierka_hgw == 0) && (!(KwadratNaKtoryRuszaSieBierka_hgw & 0x88))){
            printf("%s%s\n", notacja[KwadratZKtoregoRuszaSieBierka_hgw], notacja[KwadratNaKtoryRuszaSieBierka_hgw]);
            KwadratNaKtoryRuszaSieBierka_hgw += ListaRuchow[Kierunek_hgw];
            ZbitaBierka_hgw = Plansza[KwadratNaKtoryRuszaSieBierka_hgw];
        }
        if((!(ZbitaBierka_hgw & Strona_hgw)) && (!(KwadratNaKtoryRuszaSieBierka_hgw & 0x88))){
            printf("%s%s\n", notacja[KwadratZKtoregoRuszaSieBierka_hgw], notacja[KwadratNaKtoryRuszaSieBierka_hgw]);
        }
    }
}

void krol_kon(int Strona_kk, int KwadratZKtoregoRuszaSieBierka_kk, int RodzajBierkiBezWzgleduNaKolor_kk){
    
    int Kierunek_kk, KwadratNaKtoryRuszaSieBierka_kk, ZbitaBierka_kk;
    
    Kierunek_kk = ListaRuchow[RodzajBierkiBezWzgleduNaKolor_kk+30];
    
    while(ListaRuchow[++Kierunek_kk] !=0){
        KwadratNaKtoryRuszaSieBierka_kk = KwadratZKtoregoRuszaSieBierka_kk + ListaRuchow[Kierunek_kk];
        ZbitaBierka_kk = Plansza[KwadratNaKtoryRuszaSieBierka_kk];
        if((!(ZbitaBierka_kk & Strona_kk)) && (!(KwadratNaKtoryRuszaSieBierka_kk & 0x88)))
        printf("%s%s\n", notacja[KwadratZKtoregoRuszaSieBierka_kk], notacja[KwadratNaKtoryRuszaSieBierka_kk]);
    }
}

void MozliweRuchy(int GraczKtoregoJestRuch){
    int BierkaJakaZnajdujeSieNaPolu, RodzajPionkaBezWzgleduNaKolor, RuchWykonywanyPrzezPionek, KwadratNaKtoryRuszaSieBierka, Zbity_Kw, ZbitaBierka, Przejscie;

    printf("Mozliwe ruchy to:\n");
        
    for(int KwadratZKtoregoRuszaPionek = 0; KwadratZKtoregoRuszaPionek < 128; KwadratZKtoregoRuszaPionek++){
        if(!(KwadratZKtoregoRuszaPionek & 0x88)){
            BierkaJakaZnajdujeSieNaPolu = Plansza[KwadratZKtoregoRuszaPionek];

            if(BierkaJakaZnajdujeSieNaPolu & GraczKtoregoJestRuch){

                RodzajPionkaBezWzgleduNaKolor = BierkaJakaZnajdujeSieNaPolu & 7;
                if(BierkaJakaZnajdujeSieNaPolu == 9){
                    bialy_pionek(KwadratZKtoregoRuszaPionek);
                }
                else if(BierkaJakaZnajdujeSieNaPolu ==18){
                    czarny_pionek(KwadratZKtoregoRuszaPionek);
                }
                else if((RodzajPionkaBezWzgleduNaKolor == 3) || (RodzajPionkaBezWzgleduNaKolor == 4)){
                    krol_kon(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, RodzajPionkaBezWzgleduNaKolor);
                }
                            
                else if((RodzajPionkaBezWzgleduNaKolor >= 5) || (RodzajPionkaBezWzgleduNaKolor <= 7)){
                    hetman_goniec_wieza(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, RodzajPionkaBezWzgleduNaKolor);
                }                
            }
        }
    }
}


          


int main(){
    WypiszPlansze();
    //SzukajRuchu(1, 1);
    MozliweRuchy(8);

    return 0;
}