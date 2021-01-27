#include "struktury.h"


int negaMax(szachownica *sz_nm, int glebokosc_nm, int alfa_nm, int beta_nm){
    
    if (!glebokosc_nm){ //dodac warunek ze gra skonczona
        return ZliczanieBierkek(sz_nm);
    }
    szachownica *sztymczas_nm;
    int nowaocena_nm;
    int maxocena_nm=-200;
    
    for(ruchy *lr_nm = MozliweRuchy(sz_nm), *ptr_nm = lr_nm; lr_nm; lr_nm = lr_nm->next, free(ptr_nm), ptr_nm = lr_nm)
    {
        printf("skanuje %s\n", lr_nm->NazwaRuchu);
        szachownica *Dziecko_nm = WykonajRuch(lr_nm->NazwaRuchu, sz_nm, lr_nm); //plansza po ruchu to dziecko
        printf("wypisuje negamaxa wewnetrznego:\n");
        WypiszPlansze(Dziecko_nm);
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
    sz_r = WykonajRuch(sz_r->glowaMozliwychRuchow->NazwaRuchu, sz_r, sz_r->glowaMozliwychRuchow);
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
        printf("a\n");
        
        sztymczas_nr = WykonajRuch(lr->NazwaRuchu, sz_nr, lr);
        printf("wypisuje analizowana galaz:\n");
        WypiszPlansze(sztymczas_nr);
        nowaocena_nr = -negaMax(sztymczas_nr, glebokosc_nr, alfa_nr, beta_nr);

        if (nowaocena_nr > maxocena_nr){
            maxocena_nr = nowaocena_nr;
        }

        if (maxocena_nr >= alfa_nr){
            alfa_nr = maxocena_nr;
            printf("jestem tutaj\n");

            sztymczas_nr = WykonajRuch(lr->NazwaRuchu, sz_nr, lr);
            printf("a tu mnie nie ma\n");
        }
        
        if (alfa_nr > beta_nr){
        //ZwolnijRuchy(lr);
        break;
        }
        //free(szwypisywana_nr);
    }
    printf("a tu znowu jestem\n");
    sz_nr->enpassant = sztymczas_nr->enpassant;
    sz_nr->glowaMozliwychRuchow = sztymczas_nr->glowaMozliwychRuchow;
    sz_nr->roszadaBialyKingSide = sztymczas_nr->roszadaBialyKingSide;
    sz_nr->roszadaBialyQueenSide = sztymczas_nr->roszadaBialyQueenSide;
    sz_nr->roszadaCzarnyKingSide = sztymczas_nr->roszadaCzarnyKingSide;
    sz_nr->roszadaCzarnyQueenSide = sztymczas_nr->roszadaCzarnyQueenSide;
    sz_nr->strona = sztymczas_nr->strona;
    for(int i = 0; i<128; i++){
        sz_nr->szachownica[i] = sztymczas_nr->szachownica[i];
    }
    printf("a jestem tu?");
    return sz_nr;
}
