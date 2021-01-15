#include <stdio.h>
#include <string.h>
#include "struktury.h"



void WypiszPlansze(){
    for(int Pole = 0; Pole < 128; Pole++){
        if(!(Pole % 16)){
            printf(" %d. ", 8 - ( Pole / 16 ));
        }
        printf(" %c", ((Pole & 8) && (Pole +=7)) ? '\n' : Bierki[Plansza[Pole] & 15]);
    }
    printf("\n     a b c d e f g h\n\nTwoj ruch: \n");
}

int PrzypiszBierke(int KwadratZKtoregoRuszaPionek){
    int BierkaJakaZnajdujeSieNaPolu;
    BierkaJakaZnajdujeSieNaPolu = Plansza[KwadratZKtoregoRuszaPionek];

    return BierkaJakaZnajdujeSieNaPolu;
}

int bialy_pionek(int Strona_bp, int KwadratZKtoregoRuszaPionek_bp, int ZbitaBierka_bp, int KwadratNaKtoryRuszaSieBierka_bp, int Kierunek_bp){
    
    if(ZbitaBierka_bp & 16){                           //jesli pole na ktore ma sie ruszyc po skosie jest czarnym pionkiem
        printf("%s%s  ", notacja[KwadratZKtoregoRuszaPionek_bp], notacja[KwadratNaKtoryRuszaSieBierka_bp]);   //napisz ze mozliwy ruch na to pole
        }
    else
    KwadratNaKtoryRuszaSieBierka_bp -= 2;                                            //zmien docelowe pole na to drugie po skosie
    ZbitaBierka_bp = PrzypiszBierke(KwadratNaKtoryRuszaSieBierka_bp);               //zaktualizuj informacje o bierce na tym polu
        
        if(ZbitaBierka_bp & 16){                   //jesli pole na ktore ma sie ruszyc po skosie jest czarnym pionkiem
            printf("%s%s  ", notacja[KwadratZKtoregoRuszaPionek_bp], notacja[KwadratNaKtoryRuszaSieBierka_bp]);   //napisz ze mozliwy ruch na to pole
        }
    else
        Kierunek_bp++;                                                              //Zmien na kolejny ruch
        KwadratNaKtoryRuszaSieBierka_bp = KwadratZKtoregoRuszaPionek_bp + ListaRuchow[Kierunek_bp];  //Zmien docelowe pole na ktore ma sie ruszyc pionek
        ZbitaBierka_bp = PrzypiszBierke(KwadratNaKtoryRuszaSieBierka_bp);           //Zaktualizuj info o bierce na tym polu
                       
        if((!(ZbitaBierka_bp & 8)) && (!(ZbitaBierka_bp & 16))){
            printf("%s%s  ", notacja[KwadratZKtoregoRuszaPionek_bp], notacja[KwadratNaKtoryRuszaSieBierka_bp]);   //napisz ze mozliwy ruch na to pole
            Kierunek_bp++;
            KwadratNaKtoryRuszaSieBierka_bp = KwadratZKtoregoRuszaPionek_bp + ListaRuchow[Kierunek_bp];
            ZbitaBierka_bp = PrzypiszBierke(KwadratNaKtoryRuszaSieBierka_bp);

            if(((KwadratZKtoregoRuszaPionek_bp>=96) && (KwadratZKtoregoRuszaPionek_bp<=104)) && ((!(ZbitaBierka_bp & Strona_bp)) && (!(ZbitaBierka_bp & 16)))){
                printf("%s%s  ", notacja[KwadratZKtoregoRuszaPionek_bp], notacja[KwadratNaKtoryRuszaSieBierka_bp]);
            }
        }
        if(ListaRuchow[Kierunek_bp]==16)
        Kierunek_bp++;
    return Kierunek_bp;
}   

void hetman_goniec_wieza(int Strona_hgw, int KwadratZKtoregoRuszaPionek_hgw, int ZbitaBierka_hgw, int KwadratNaKtoryRuszaSieBierka_hgw, int Kierunek_hgw){
    while((ZbitaBierka_hgw == 0) && (!(KwadratNaKtoryRuszaSieBierka_hgw & 0x88))){
        printf("%s%s  ", notacja[KwadratZKtoregoRuszaPionek_hgw], notacja[KwadratNaKtoryRuszaSieBierka_hgw]);
        KwadratNaKtoryRuszaSieBierka_hgw += ListaRuchow[Kierunek_hgw];
        ZbitaBierka_hgw = Plansza[KwadratNaKtoryRuszaSieBierka_hgw];
        }
    if((!(ZbitaBierka_hgw & Strona_hgw)) && (!(KwadratNaKtoryRuszaSieBierka_hgw & 0x88)))
        printf("%s%s  ", notacja[KwadratZKtoregoRuszaPionek_hgw], notacja[KwadratNaKtoryRuszaSieBierka_hgw]);
}

void MozliweRuchy(int GraczKtoregoJestRuch){
    int BierkaJakaZnajdujeSieNaPolu, RodzajPionkaBezWzgleduNaKolor, RuchWykonywanyPrzezPionek, KwadratNaKtoryRuszaSieBierka, Zbity_Kw, ZbitaBierka, Przejscie;

    printf("Mozliwe ruchy to:\n");
        
    for(int KwadratZKtoregoRuszaPionek = 0; KwadratZKtoregoRuszaPionek < 128; KwadratZKtoregoRuszaPionek++){
        if(!(KwadratZKtoregoRuszaPionek & 0x88)){
            BierkaJakaZnajdujeSieNaPolu = PrzypiszBierke(KwadratZKtoregoRuszaPionek);

            if(BierkaJakaZnajdujeSieNaPolu & GraczKtoregoJestRuch){

                RodzajPionkaBezWzgleduNaKolor = BierkaJakaZnajdujeSieNaPolu & 7;
                RuchWykonywanyPrzezPionek = ListaRuchow[RodzajPionkaBezWzgleduNaKolor+30];
                //printf(" %s", notacja[KwadratZKtoregoRuszaPionek]);
                KwadratNaKtoryRuszaSieBierka = KwadratZKtoregoRuszaPionek;
                while(ListaRuchow[++RuchWykonywanyPrzezPionek] != 0){
                    KwadratNaKtoryRuszaSieBierka = KwadratZKtoregoRuszaPionek + ListaRuchow[RuchWykonywanyPrzezPionek];
                    if(!(KwadratNaKtoryRuszaSieBierka & 0x88)){
                        ZbitaBierka = PrzypiszBierke(KwadratNaKtoryRuszaSieBierka);
                        if(!(ZbitaBierka & GraczKtoregoJestRuch)){   //Do tego momentu program skanuje kazde pole w poszukiwaniu bierek
                                                        // z danego koloru i wypisuje pierwsze wolne pola na ktore moze sie ruszyc bierkaJakaZnajdujeSieNaPolu
                            if(BierkaJakaZnajdujeSieNaPolu == 9){            //jesli bierkaJakaZnajdujeSieNaPolu to bialy pionek

                                RuchWykonywanyPrzezPionek = bialy_pionek(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, ZbitaBierka, KwadratNaKtoryRuszaSieBierka, RuchWykonywanyPrzezPionek);
                            }
                            // else if(BierkaJakaZnajdujeSieNaPolu ==18){

                            // }
                            else if((RodzajPionkaBezWzgleduNaKolor == 3) || (RodzajPionkaBezWzgleduNaKolor == 4)){
                                printf("%s%s  ", notacja[KwadratZKtoregoRuszaPionek], notacja[KwadratNaKtoryRuszaSieBierka]);
                            }
                            
                            else if((RodzajPionkaBezWzgleduNaKolor >= 5) || (RodzajPionkaBezWzgleduNaKolor <= 7)){
                                hetman_goniec_wieza(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, ZbitaBierka, KwadratNaKtoryRuszaSieBierka, RuchWykonywanyPrzezPionek);
                            }
                        }
                        //printf("%s%s   ", notacja[KwadratZKtoregoRuszaPionek], notacja[KwadratNaKtoryRuszaSieBierka]);
                    }
                    //printf("%s%s   ", notacja[KwadratZKtoregoRuszaPionek], notacja[KwadratNaKtoryRuszaSieBierka]);
                    
                }
                //printf("\n");
                
            }

        }
    }
}

// int SzukajRuchu(int Ruch, int glebokosc){
//     if(glebokosc == 0){
//         return 0;
//     }
//     else{
//         int BierkaJakaZnajdujeSieNaPolu, RodzajPionkaBezWzgleduNaKolor, RuchWykonywanyPrzezPionek, KwadratNaKtoryRuszaSieBierka, Zbity_Kw, ZbitaBierka, Przejscie;
//         for(int KwadratZKtoregoRuszaPionek = 0; KwadratZKtoregoRuszaPionek < 120; KwadratZKtoregoRuszaPionek++){
//             if(KwadratZKtoregoRuszaPionek & 7){
//                 (KwadratZKtoregoRuszaPionek+=8);
//             }

//             BierkaJakaZnajdujeSieNaPolu = Plansza[KwadratZKtoregoRuszaPionek];
//             if(BierkaJakaZnajdujeSieNaPolu & Ruch){
//                 RodzajPionkaBezWzgleduNaKolor = BierkaJakaZnajdujeSieNaPolu & 7;
//                 RuchWykonywanyPrzezPionek = ListaRuchow[RodzajPionkaBezWzgleduNaKolor+30];

//                 while(Przejscie = ListaRuchow[++RuchWykonywanyPrzezPionek]){
                    
//                 }
//             }

//         }
        
//     }
// }
          


int main(){
    WypiszPlansze();
    //SzukajRuchu(1, 1);
    MozliweRuchy(8);

    return 0;
}