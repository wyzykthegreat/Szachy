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
    Ocena_main = OcenaGry(sz_main);
    // int punktybierek_main;
    // punktybierek_main = NegaMax(sz_main, 0, -2000, 2000, Strona_main);
    // printf("%d", punktybierek_main);
    while(Ocena_main == 0){
        WypiszPlansze(sz_main);
        sz_main->glowaMozliwychRuchow = MozliweRuchy(sz_main->strona, sz_main);
        printf("Jaki ruch wykonujesz?\n");
        scanf("%s", ruch_main);
        sz_main = WykonajRuch(sz_main->strona, ruch_main, sz_main);
        
        Ocena_main = OcenaGry(sz_main);
    }
    free(sz_main);
    free(glowa_main);
    
    return 0;
}