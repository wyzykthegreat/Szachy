#include "struktury.h"


int main(){
    ruchy *glowa_main = (ruchy*)malloc(sizeof(ruchy));
    szachownica * sz_main = (szachownica*)malloc(sizeof(szachownica));
    sz_main = UstawSzachownice(sz_main);
    char ruch_main[5];
    int Strona_main = 8;
    int Ocena_main = 0;
    Ocena_main = OcenaGry(sz_main);
    while(Ocena_main == 0){
            WypiszPlansze(sz_main);
            sz_main->glowaMozliwychRuchow = MozliweRuchy(sz_main);
            printf("Jaki ruch wykonujesz?\n");
            scanf("%s", ruch_main);
            sz_main = WykonajRuch(ruch_main, sz_main);
        
        Ocena_main = OcenaGry(sz_main);
    }
    free(sz_main);
    free(glowa_main);
    
    return 0;
}