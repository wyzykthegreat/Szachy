#include "struktury.h"


int negaMax(szachownica *sz_nm, int glebokosc_nm, int alfa_nm, int beta_nm){
    
    if (!glebokosc_nm){ //dodac warunek ze gra skonczona
        return ZliczanieBierkek(sz_nm);
    }
    szachownica *sztymczas_nm;
    int nowaocena_nm;
    int maxocena_nm=-200;
    
    for(ruchy *lr = MozliweRuchy(sz_nm), *ptr = lr; lr; lr = lr->next, free(ptr), ptr = lr)
    {
        printf("skanuje %s\n", lr->NazwaRuchu);
        szachownica *Dziecko_nm = WykonajRuch(lr->NazwaRuchu, sz_nm); //plansza po ruchu to dziecko
        nowaocena_nm = -negaMax(Dziecko_nm, glebokosc_nm - 1, -beta_nm, -alfa_nm);
    // printf("iteracja:%d\n",i);
    // printf("nowaocena1:%d\n",nowaocena);
    // printf("ocenawezla1:%d\n",ocenawezla);
    if (nowaocena_nm > maxocena_nm)
    maxocena_nm = nowaocena_nm;
    if (maxocena_nm > alfa_nm)
    alfa_nm = maxocena_nm;
    // printf("alfa:%d\n\n",alfa);
    if (alfa_nm > beta_nm)
    {
        // if(lr->next!=NULL){
        //         free(lr->next);
        // }
        // free(lr);
        break;
    }
}
    return maxocena_nm;
}

szachownica * Ruch(szachownica *sz_r){
    sz_r->glowaMozliwychRuchow = sz_r->glowaMozliwychRuchow->next;
    sz_r = WykonajRuch(sz_r->glowaMozliwychRuchow->NazwaRuchu, sz_r);
    return sz_r;
}


szachownica * najlepszyRuch(szachownica *sz_nr, int glebokosc_nr, int alfa_nr, int beta_nr){
    szachownica *sztymczas_nr;
    int nowaocena_nr;
    int maxocena_nr = -200;
    
    for(ruchy *lr = MozliweRuchy(sz_nr), *ptr = lr; lr; lr = lr->next, free(ptr), ptr = lr){
        printf("a\n");
        szachownica *sztymczas_nr = (szachownica*)malloc(sizeof(szachownica));
        printf("b\n");
        char NazwaRuchu_nr[5];
        int KwadratZrodlowy_nr;
        int KwadratDocelowy_nr;
        strcpy(NazwaRuchu_nr, lr->NazwaRuchu);
        printf("a\n");
        KwadratDocelowy_nr = lr->KwadratDocelowy;
        KwadratZrodlowy_nr = lr->KwadratZrodlowy;
        
        sztymczas_nr = WykonajRuch(sztymczas_nr->glowaMozliwychRuchow->NazwaRuchu, sz_nr);
        nowaocena_nr = -negaMax(sztymczas_nr, glebokosc_nr, alfa_nr, beta_nr);
        
        if (nowaocena_nr > maxocena_nr){
            maxocena_nr = nowaocena_nr;
        }

        if (maxocena_nr >= alfa_nr){
            alfa_nr = maxocena_nr;
            printf("jestem tutaj\n");

            // strcpy(sz_nr->glowaMozliwychRuchow->NazwaRuchu, lr->NazwaRuchu);
            // sztymczas_nr->glowaMozliwychRuchow->KwadratDocelowy = lr->KwadratDocelowy;
            // sztymczas_nr->glowaMozliwychRuchow->KwadratZrodlowy = lr->KwadratZrodlowy;

            sz_nr = WykonajRuch(sztymczas_nr->glowaMozliwychRuchow->NazwaRuchu, sz_nr);
            WypiszPlansze(sztymczas_nr);
        }
        
        if (alfa_nr > beta_nr){
        //ZwolnijRuchy(lr);
        break;
        }
        //free(szwypisywana_nr);
    }
    sz_nr = sztymczas_nr;
     return sz_nr;
}
