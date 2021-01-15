#include <stdio.h>
#include <string.h>
#include "struktury.h"



void WypiszPlansze(){
    for(int Pole = 0; Pole < 128; Pole++){
        if(!(Pole % 16)){
            printf(" %d. ", 8 - ( Pole / 16 ));
            printf(" %c", ((Pole & 8) && (Pole +=7)) ? '\n' : Bierki[Plansza[Pole] & 15]);
        }
    }
    printf("\n     a b c d e f g h\n\nTwoj ruch: \n");
}

int PrzypiszBierke(int Zrodlowy_Kw){
    int Bierka;
    Bierka = Plansza[Zrodlowy_Kw];

    return Bierka;
}

void bialy_pionek(int Strona_bp, int Zrodlowy_Kw_bp, int Zbita_Bierka_bp, int Docelowy_Kw_bp, int Kierunek_bp){
    
    if(Zbita_Bierka_bp & 16){                           //jesli pole na ktore ma sie ruszyc po skosie jest czarnym pionkiem
        printf("%s%s  ", notacja[Zrodlowy_Kw_bp], notacja[Docelowy_Kw_bp]);   //napisz ze mozliwy ruch na to pole
        }
        Docelowy_Kw_bp -= 2;                                            //zmien docelowe pole na to drugie po skosie
        Zbita_Bierka_bp = PrzypiszBierke(Docelowy_Kw_bp);               //zaktualizuj informacje o bierce na tym polu
        
        if(Zbita_Bierka_bp & 16){                   //jesli pole na ktore ma sie ruszyc po skosie jest czarnym pionkiem
            printf("%s%s  ", notacja[Zrodlowy_Kw_bp], notacja[Docelowy_Kw_bp]);   //napisz ze mozliwy ruch na to pole
        }
        Kierunek_bp++;                                                              //Zmien na kolejny ruch
        Docelowy_Kw_bp = Zrodlowy_Kw_bp + ListaRuchow[Kierunek_bp];  //Zmien docelowe pole na ktore ma sie ruszyc pionek
        Zbita_Bierka_bp = PrzypiszBierke(Docelowy_Kw_bp);           //Zaktualizuj info o bierce na tym polu
                       
        if((!(Zbita_Bierka_bp & 8)) && (!(Zbita_Bierka_bp & 16))){
            printf("%s%s  ", notacja[Zrodlowy_Kw_bp], notacja[Docelowy_Kw_bp]);   //napisz ze mozliwy ruch na to pole
            Kierunek_bp++;
            Docelowy_Kw_bp = Zrodlowy_Kw_bp + ListaRuchow[Kierunek_bp];
            Zbita_Bierka_bp = PrzypiszBierke(Docelowy_Kw_bp);

            if(((Zrodlowy_Kw_bp>=96) && (Zrodlowy_Kw_bp<=104)) && ((!(Zbita_Bierka_bp & Strona_bp)) && (!(Zbita_Bierka_bp & 16)))){
                printf("%s%s  ", notacja[Zrodlowy_Kw_bp], notacja[Docelowy_Kw_bp]);
            }
        }
}   

void hetman_goniec_wieza(int Strona_hgw, int Zrodlowy_Kw_hgw, int Zbita_Bierka_hgw, int Docelowy_Kw_hgw, int Kierunek_hgw){
    while((Zbita_Bierka_hgw == 0) && (!(Docelowy_Kw_hgw & 0x88))){
        printf("%s%s  ", notacja[Zrodlowy_Kw_hgw], notacja[Docelowy_Kw_hgw]);
        Docelowy_Kw_hgw += ListaRuchow[Kierunek_hgw];
        Zbita_Bierka_hgw = Plansza[Docelowy_Kw_hgw];
        }
    if((!(Zbita_Bierka_hgw & Strona_hgw)) && (!(Docelowy_Kw_hgw & 0x88)))
        printf("%s%s  ", notacja[Zrodlowy_Kw_hgw], notacja[Docelowy_Kw_hgw]);
}

void MozliweRuchy(int Strona){
    int Bierka, Rodzaj, Kierunek, Docelowy_Kw, Zbity_Kw, Zbita_Bierka, Przejscie;

    printf("Mozliwe ruchy to:\n");
        
    for(int Zrodlowy_Kw = 0; Zrodlowy_Kw < 128; Zrodlowy_Kw++){
        if(!(Zrodlowy_Kw & 0x88)){
            Bierka = PrzypiszBierke(Zrodlowy_Kw);

            if(Bierka & Strona){

                Rodzaj = Bierka & 7;
                Kierunek = ListaRuchow[Rodzaj+30];
                //printf(" %s", notacja[Zrodlowy_Kw]);
                Docelowy_Kw = Zrodlowy_Kw;
                while(ListaRuchow[++Kierunek] != 0){
                    Docelowy_Kw = Zrodlowy_Kw + ListaRuchow[Kierunek];
                    if(!(Docelowy_Kw & 0x88)){
                        Zbita_Bierka = PrzypiszBierke(Docelowy_Kw);
                        if(!(Zbita_Bierka & Strona)){   //Do tego momentu program skanuje kazde pole w poszukiwaniu bierek
                                                        // z danego koloru i wypisuje pierwsze wolne pola na ktore moze sie ruszyc bierka
                            if(Bierka == 9){            //jesli bierka to bialy pionek

                                bialy_pionek(Strona, Zrodlowy_Kw, Zbita_Bierka, Docelowy_Kw, Kierunek);
                            }
                            // else if(Bierka ==18){

                            // }
                            else if((Rodzaj == 3) || (Rodzaj == 4)){
                                printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);
                            }
                            
                            else if((Rodzaj >= 5) || (Rodzaj <= 7)){
                                hetman_goniec_wieza(Strona, Zrodlowy_Kw, Zbita_Bierka, Docelowy_Kw, Kierunek);
                            }
                        }
                        //printf("%s%s   ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);
                    }
                    //printf("%s%s   ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);
                    
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
//         int Bierka, Rodzaj, Kierunek, Docelowy_Kw, Zbity_Kw, Zbita_Bierka, Przejscie;
//         for(int Zrodlowy_Kw = 0; Zrodlowy_Kw < 120; Zrodlowy_Kw++){
//             if(Zrodlowy_Kw & 7){
//                 (Zrodlowy_Kw+=8);
//             }

//             Bierka = Plansza[Zrodlowy_Kw];
//             if(Bierka & Ruch){
//                 Rodzaj = Bierka & 7;
//                 Kierunek = ListaRuchow[Rodzaj+30];

//                 while(Przejscie = ListaRuchow[++Kierunek]){
                    
//                 }
//             }

//         }
        
//     }
// }
          


int main(){
    WypiszPlansze();
    //SzukajRuchu(1, 1);
    //MozliweRuchy(bialy);

    return 0;
}