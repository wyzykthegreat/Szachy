#include <stdio.h>
#include <string.h>

static int ListaRuchow[] = {

       15,  16,  32,   0,                           // operacje wykorzystywane do ruchu bialych pionkow
      -15, -16, -32,   0,                           // operacje wykorzystywane do ruchu czarnych pionkow
        1,  16,  -1, -16,   0,                      // operacje wykorzystywane do ruchu wiez
        1,  16,  -1, -16,  15, -15, 17, -17,  0,    // operacje wykorzystywane do ruchu dam, krolow i goncow
       14, -14,  18, -18,  31, -31, 33, -33,  0,    // operacje wykorzystywane do ruchu koni
        3,  -1,  12,  21,  16,   7, 12              //opisane kolejno poczatki mozliwych ruchow do wykonania przez poszczegolne figury
    };

int Plansza[128] = {                

    22, 20, 21, 23, 19, 21, 20, 22,     0, 0, 0, 0, 0, 0, 0, 0,
    18, 18, 18, 18, 18, 18, 18, 18,     0, 0, 0, 0, 0, 0, 0, 0,
     0,  0,  0,  0,  0,  0,  0,  0,     0, 0, 0, 0, 0, 0, 0, 0,
     0,  0,  0,  0,  0,  0,  0,  0,     0, 0, 0, 0, 0, 0, 0, 0,
     0,  0,  0,  0,  0,  0,  0,  0,     0, 0, 0, 0, 0, 0, 0, 0,
     0,  0,  0,  0,  0,  0,  0,  0,     0, 0, 0, 0, 0, 0, 0, 0,
     9,  9,  9,  9,  9,  9,  9,  9,     0, 0, 0, 0, 0, 0, 0, 0,
    14, 12, 13, 15, 11, 13, 12, 14,     0, 0, 0, 0, 0, 0, 0, 0,

};

char *notacja[] = {

    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",     "i8","j8","k8","l8","m8","n8","o8", "p8",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",     "i7","j7","k7","l7","m7","n7","o7", "p7",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",     "i6","j6","k6","l6","m6","n6","o6", "p6",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",     "i5","j5","k5","l5","m5","n5","o5", "p5",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",     "i4","j4","k4","l4","m4","n4","o4", "p4",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",     "i3","j3","k3","l3","m3","n3","o3", "p3",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",     "i2","j2","k2","l2","m2","n2","o2", "p2",
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",     "i1","j1","k1","l1","m1","n1","o1", "p1",

};

enum { bialy = 8, czarny = 16};

char Bierki[] = ".-pknbrq-P-KNBRQ";

void WypiszPlansze(){
  for(int Pole = 0; Pole < 128; Pole++){
    if(!(Pole % 16)) printf(" %d. ", 8 - ( Pole / 16 ));
    printf(" %c", ((Pole & 8) && (Pole +=7)) ? '\n' : Bierki[Plansza[Pole] & 15]);
  }
  
  printf("\n     a b c d e f g h\n\nTwoj ruch: \n");
}
void MozliweRuchy(int Strona){
    int Bierka, Rodzaj, Kierunek, Docelowy_Kw, Zbity_Kw, Zbita_Bierka, Przejscie;
    printf("Mozliwe ruchy to:\n");
    for(int Zrodlowy_Kw = 0; Zrodlowy_Kw < 128; Zrodlowy_Kw++){
        if(!(Zrodlowy_Kw & 0x88)){
            Bierka = Plansza[Zrodlowy_Kw];

            if(Bierka & Strona){

                Rodzaj = Bierka & 7;
                Kierunek = ListaRuchow[Rodzaj+30];
                //printf(" %s", notacja[Zrodlowy_Kw]);
                Docelowy_Kw = Zrodlowy_Kw;
                while(ListaRuchow[++Kierunek] != 0){
                    Docelowy_Kw = Zrodlowy_Kw + ListaRuchow[Kierunek];
                    if(!(Docelowy_Kw & 0x88)){
                        Zbita_Bierka=Plansza[Docelowy_Kw];
                        if(!(Zbita_Bierka & Strona)){   //Do tego momentu program skanuje kazde pole w poszukiwaniu bierek
                                                        // z danego koloru i wypisuje pierwsze wolne pola na ktore moze sie ruszyc bierka
                            if(Bierka == 9){            //jesli bierka to bialy pionek
                                if(Zbita_Bierka & 16){  //jesli pole na ktore ma sie ruszyc po skosie jest czarnym pionkiem
                                    printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);   //napisz ze mozliwy ruch na to pole
                                }
                                Docelowy_Kw -= 2;       //zmien docelowe pole na to drugie po skosie
                                Zbita_Bierka = Plansza[Docelowy_Kw]; //zaktualizuj informacje o bierce na tym polu
                                if(Zbita_Bierka & 16){              //jesli pole na ktore ma sie ruszyc po skosie jest czarnym pionkiem
                                    printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);   //napisz ze mozliwy ruch na to pole
                                }
                                Kierunek++;             //Zmien na kolejny ruch
                                Docelowy_Kw = Zrodlowy_Kw + ListaRuchow[Kierunek];  //Zmien docelowe pole na ktore ma sie ruszyc pionek
                                Zbita_Bierka = Plansza[Docelowy_Kw];                //Zaktualizuj info o bierce na tym polu
                                if((!(Zbita_Bierka & 8)) && (!(Zbita_Bierka & 16))){
                                    printf("%s%s  ", notacja[Zrodlowy_Kw], notacja[Docelowy_Kw]);   //napisz ze mozliwy ruch na to pole
                                
                                    Kierunek++;
                                    Docelowy_Kw = Zrodlowy_Kw + ListaRuchow[Kierunek];
                                    Zbita_Bierka = Plansza[Docelowy_Kw]; 
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
