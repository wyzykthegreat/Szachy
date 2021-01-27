#include "struktury.h"

void WypiszPlansze(szachownica *sz_wp){
    for(int Pole = 0; Pole < 128; Pole++){
        if(!(Pole % 16)){
            printf(" %d. ", 8 - ( Pole / 16 ));
        }
        
            if(sz_wp->szachownica[Pole] == 0){
                if(!(((Pole & 16) || (Pole & 1))&&((!(Pole & 16)) || (!(Pole & 1))))){
                    printf(" %s", ((Pole & 8) && (Pole +=7)) ? "\n": Bierki[sz_wp->szachownica[Pole] & 15]);
                }
                else{
                    printf(" %s", ((Pole & 8) && (Pole +=7)) ? "\n": Bierki[1]);
                }
            }
            else{
                printf(" %s", ((Pole & 8) && (Pole +=7)) ? "\n" : Bierki[sz_wp->szachownica[Pole] & 15]);
            }
    }
    printf("\n     a b c d e f g h\n \n");
}

int PrzypiszBierke(int KwadratZKtoregoRuszaPionek, szachownica *sz_pb){
    int BierkaJakaZnajdujeSieNaPolu;
    BierkaJakaZnajdujeSieNaPolu = sz_pb->szachownica[KwadratZKtoregoRuszaPionek];

    return BierkaJakaZnajdujeSieNaPolu;
}

szachownica * UstawSzachownice(szachownica *sz_us){
    for(int i = 0; i<128; i++){
        sz_us->szachownica[i]=Plansza[i];
        sz_us->strona = 8;
        sz_us->enpassant = -1;
    }
    return sz_us;
}