#include <stdio.h>
#include <string.h>
#include "struktury.h"



void WypiszPlansze(){
  for(int Pole = 0; Pole < 128; Pole++){
    if(!(Pole % 16)) printf(" %d. ", 8 - ( Pole / 16 ));
    printf(" %c", ((Pole & 8) && (Pole +=7)) ? '\n' : Bierki[Plansza[Pole] & 15]);
  }
  
  printf("\n     a b c d e f g h\n\nTwoj ruch: \n");
}

int PrzypiszBierke(int Zrodlowy_Kw){
    int Bierka;
    Bierka = Plansza[Zrodlowy_Kw];

    return Bierka;
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
                                if(Zbita_Bierka & 16){  //jesli pole na ktore ma sie ruszyc po skosie jest czarnym pionkiem
                                    printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);   //napisz ze mozliwy ruch na to pole
                                }
                                Docelowy_Kw -= 2;       //zmien docelowe pole na to drugie po skosie
                                Zbita_Bierka = PrzypiszBierke(Docelowy_Kw); //zaktualizuj informacje o bierce na tym polu
                                if(Zbita_Bierka & 16){              //jesli pole na ktore ma sie ruszyc po skosie jest czarnym pionkiem
                                    printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);   //napisz ze mozliwy ruch na to pole
                                }
                                Kierunek++;             //Zmien na kolejny ruch
                                Docelowy_Kw = Zrodlowy_Kw + ListaRuchow[Kierunek];  //Zmien docelowe pole na ktore ma sie ruszyc pionek
                                Zbita_Bierka = PrzypiszBierke(Docelowy_Kw);                //Zaktualizuj info o bierce na tym polu
                                if((!(Zbita_Bierka & 8)) && (!(Zbita_Bierka & 16))){
                                    printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);   //napisz ze mozliwy ruch na to pole
                                
                                    Kierunek++;
                                    Docelowy_Kw = Zrodlowy_Kw + ListaRuchow[Kierunek];
                                    Zbita_Bierka = PrzypiszBierke(Docelowy_Kw); 
                                    if(((Zrodlowy_Kw>=96) && (Zrodlowy_Kw<=104)) && ((!(Zbita_Bierka & Strona)) && (!(Zbita_Bierka & 16)))){
                                        printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);
                                    
                                    }
                                }
                            }

                            /*else if(Bierka ==18){

                            }*/

                            else if((Rodzaj == 3) || (Rodzaj == 4)){
                                printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);
                            }
                            
                            else if((Rodzaj >= 5) || (Rodzaj <= 7)){
                                while((Zbita_Bierka == 0) && (!(Docelowy_Kw & 0x88))){
                                    printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);
                                    Docelowy_Kw += ListaRuchow[Kierunek];
                                    Zbita_Bierka = Plansza[Docelowy_Kw];
                                }
                                if((!(Zbita_Bierka & Strona)) && (!(Docelowy_Kw & 0x88)))
                                printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);
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

/*int SzukajRuchu(int Ruch, int glebokosc){
    if(glebokosc == 0){
        return 0;
    }
    else{
        int Bierka, Rodzaj, Kierunek, Docelowy_Kw, Zbity_Kw, Zbita_Bierka, Przejscie;
        for(int Zrodlowy_Kw = 0; Zrodlowy_Kw < 120; Zrodlowy_Kw++){
            if(Zrodlowy_Kw & 7){
                (Zrodlowy_Kw+=8);
            }

            Bierka = Plansza[Zrodlowy_Kw];
            if(Bierka & Ruch){
                Rodzaj = Bierka & 7;
                Kierunek = ListaRuchow[Rodzaj+30];

                while(Przejscie = ListaRuchow[++Kierunek]){
                    
                }
            }

        }
        
    }
}*/
          


int main(){
  WypiszPlansze();
  //SzukajRuchu(1, 1);
  //MozliweRuchy(bialy);

  return 0;
}
