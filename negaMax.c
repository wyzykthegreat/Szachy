#include "struktury.h"


int negaMax(szachownica *sz_nm, int glebokosc_nm, int alfa_nm, int beta_nm){
    
    if (!glebokosc_nm){ //dodac warunek ze gra skonczona
        return ZliczanieBierkek(sz_nm);
    }
    szachownica *sztymczas_nm;
    sztymczas_nm = (szachownica*)malloc(sizeof(szachownica));
    int nowaocena_nm;
    int maxocena_nm = -200;
    
    for(ruchy *lr_nm = MozliweRuchy(sz_nm), *ptr_nm = lr_nm; lr_nm; lr_nm = lr_nm->next, free(ptr_nm), ptr_nm = lr_nm)
    {
        sztymczas_nm->enpassant = sz_nm->enpassant;
        sztymczas_nm->glowaMozliwychRuchow = sz_nm->glowaMozliwychRuchow;
        sztymczas_nm->roszadaBialyKingSide = sz_nm->roszadaBialyKingSide;
        sztymczas_nm->roszadaBialyQueenSide = sz_nm->roszadaBialyQueenSide;
        sztymczas_nm->roszadaCzarnyKingSide = sz_nm->roszadaCzarnyKingSide;
        sztymczas_nm->roszadaCzarnyQueenSide = sz_nm->roszadaCzarnyQueenSide;
        sztymczas_nm->strona = sz_nm->strona;
        for(int i = 0; i<128; i++){
            sztymczas_nm->szachownica[i] = sz_nm->szachownica[i];
        }

        sztymczas_nm = WykonajRuch(lr_nm->NazwaRuchu, sztymczas_nm, lr_nm);
        nowaocena_nm = -negaMax(sztymczas_nm, glebokosc_nm - 1, -beta_nm, -alfa_nm);

        if (nowaocena_nm > maxocena_nm){
        maxocena_nm = nowaocena_nm;
        }
        if (maxocena_nm > alfa_nm){
        alfa_nm = maxocena_nm;
        }

        if (alfa_nm > beta_nm){
            break;
        }
    free(sztymczas_nm);
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
    sztymczas_nr = (szachownica*)malloc(sizeof(szachownica));
    int nowaocena_nr;
    int maxocena_nr = -200;
    
    for(ruchy *lr = MozliweRuchy(sz_nr), *ptr = lr; lr; lr = lr->next, free(ptr), ptr = lr){

        
        sztymczas_nr->enpassant = sz_nr->enpassant;
        sztymczas_nr->glowaMozliwychRuchow = sz_nr->glowaMozliwychRuchow;
        sztymczas_nr->roszadaBialyKingSide = sz_nr->roszadaBialyKingSide;
        sztymczas_nr->roszadaBialyQueenSide = sz_nr->roszadaBialyQueenSide;
        sztymczas_nr->roszadaCzarnyKingSide = sz_nr->roszadaCzarnyKingSide;
        sztymczas_nr->roszadaCzarnyQueenSide = sz_nr->roszadaCzarnyQueenSide;
        sztymczas_nr->strona = sz_nr->strona;
        for(int i = 0; i<128; i++){
            sztymczas_nr->szachownica[i] = sz_nr->szachownica[i];
        }

        sztymczas_nr = WykonajRuch(lr->NazwaRuchu, sztymczas_nr, lr);

        nowaocena_nr = -negaMax(sztymczas_nr, glebokosc_nr, alfa_nr, beta_nr);

        if (nowaocena_nr > maxocena_nr){
            maxocena_nr = nowaocena_nr;
        }

        if (maxocena_nr > alfa_nr){
            alfa_nr = maxocena_nr;

            sztymczas_nr = WykonajRuch(lr->NazwaRuchu, sztymczas_nr, lr);
            
        }
        
        if (alfa_nr > beta_nr){
        //ZwolnijRuchy(lr);
        break;
        }
        //free(szwypisywana_nr);
    }
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
    free(sztymczas_nr);
    return sz_nr;
}
