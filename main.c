#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ruchy_bierek.h"


int main(){
    ruchy *glowa_main = (ruchy*)malloc(sizeof(ruchy));
    szachownica * sz_main = (szachownica*)malloc(sizeof(szachownica));
    sz_main = UstawSzachownice(sz_main);
    char ruch_main[5];
    int Strona_main = 8;
    int Ocena_main = 0;
    Ocena_main = OcenaGry();
    while(Ocena_main == 0){
        WypiszPlansze(sz_main);
        glowa_main = MozliweRuchy(Strona_main, glowa_main, sz_main);
        //WypiszListe(glowa_main);
        printf("Jaki ruch wykonujesz?\n");
        scanf("%s", ruch_main);
        sz_main = WykonajRuch(Strona_main, ruch_main, glowa_main, sz_main);
        
        
        if(Strona_main == 8){
            Strona_main = 16;
        }
        else{
            Strona_main = 8;
        }
        Ocena_main = OcenaGry();
    }
    
    return 0;
}