#include "struktury.h"

szachownica * ZrobNibyRuch(szachownica *sz_znr, ruchy *nibyruch_znr){
    sz_znr->szachownica[nibyruch_znr->KwadratDocelowy]=sz_znr->szachownica[nibyruch_znr->KwadratZrodlowy];
    sz_znr->szachownica[nibyruch_znr->KwadratZrodlowy] = 0;
    return sz_znr;
 }

int negaMax(szachownica *sz_nm, int glebokosc_nm, int alfa_nm, int beta_nm){

    if (!glebokosc_nm){ //dodac warunek ze gra skonczona
        return ZliczanieBierkek(sz_nm);
    }

    int nowaocena_nm;
    int ocenawezla_nm=-200;
    int i=0;

    for(ruchy *lr = MozliweRuchy(sz_nm), *ptr = lr; lr; lr = lr->next, /*free(ptr)*/ ptr = lr)
    {
        szachownica *Dziecko_nm = ZrobNibyRuch(sz_nm, ptr); //plansza po ruchu to dziecko
        nowaocena_nm = -negaMax(Dziecko_nm, glebokosc_nm - 1, -beta_nm, -alfa_nm);
    // printf("iteracja:%d\n",i);
    // printf("nowaocena1:%d\n",nowaocena);
    // printf("ocenawezla1:%d\n",ocenawezla);
    if (nowaocena_nm > ocenawezla_nm)
    ocenawezla_nm = nowaocena_nm;
    if (ocenawezla_nm > alfa_nm)
    alfa_nm = ocenawezla_nm;
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
    return ocenawezla_nm;
}

szachownica * najlepszyRuch(szachownica *sz_nr, int glebokosc_nr, int alfa_nr, int beta_nr){
    
    szachownica *sznajlepsza_nr;
    int nowaocena_nr;
    int i=-1;
    int maxocena_nr = -200;
    
    for(ruchy *lr = MozliweRuchy(sz_nr); lr; lr = lr->next){

        szachownica *szwypisywana_nr = (ZrobNibyRuch(szwypisywana_nr, lr));
        nowaocena_nr = -negaMax(szwypisywana_nr, glebokosc_nr, alfa_nr, beta_nr);

        if (nowaocena_nr > maxocena_nr){
            maxocena_nr = nowaocena_nr;
        }

        if (maxocena_nr > alfa_nr){
            alfa_nr = maxocena_nr;
            sznajlepsza_nr = szwypisywana_nr;
        }
        
        if (alfa_nr > beta_nr){
        //ZwolnijRuchy(lr);
        break;
        }
        //free(szwypisywana_nr);
    }
     return sznajlepsza_nr;
}
