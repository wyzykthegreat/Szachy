
#include "struktury.h"

void ZwolnijRuchy(ruchy *glowa_zr){
    free(glowa_zr->NazwaRuchu);
}

int OcenaGry(szachownica *sz_og){
    int Ocena_og;
    int BialyKrol_og = 0;
    int CzarnyKrol_og = 0;
    for(int i = 0; i<128; i++){
        if(!(i & 0x88)){
            if(sz_og->szachownica[i] == 11)
            BialyKrol_og = 1;
            if(sz_og->szachownica[i] == 19)
            CzarnyKrol_og = 1;
        }
    }
    if(BialyKrol_og > CzarnyKrol_og)
    Ocena_og = 1;
    else if(CzarnyKrol_og > BialyKrol_og)
    Ocena_og = -1;
    else
    Ocena_og = 0;
    
    return Ocena_og;
}

int ZliczanieBierkek(szachownica *sz_zb){
    int punkty = 0;
    for(int i = 0; i<128; i++){
        if(!(i & 0x88)){
            if(sz_zb->szachownica[i]==9){
                punkty += 1;
            }
            if(sz_zb->szachownica[i]==18){
                punkty -= 1;
            }
            if(sz_zb->szachownica[i]==11){
                punkty += 100;
            }
            if(sz_zb->szachownica[i]==12){
                punkty += 3;
            }
            if(sz_zb->szachownica[i]==13){
                punkty += 3;
            }
            if(sz_zb->szachownica[i]==14){
                punkty += 5;
            }
            if(sz_zb->szachownica[i]==15){
                punkty += 9;
            }
            if(sz_zb->szachownica[i]==19){
                punkty -= 100;
            }
            if(sz_zb->szachownica[i]==20){
                punkty -= 3;
            }
            if(sz_zb->szachownica[i]==21){
                punkty -= 3;
            }
            if(sz_zb->szachownica[i]==22){
                punkty -= 5;
            }
            if(sz_zb->szachownica[i]==23){
                punkty -= 9;
            }
            
        }
    }
    return punkty;
}

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

szachownica * UstawSzachownice(szachownica *sz_us){
    for(int i = 0; i<128; i++){
        sz_us->szachownica[i]=Plansza[i];
        sz_us->strona = 8;
    }
    return sz_us;
}

void WypiszListe(ruchy *glowa_wl){
    do {
        printf("%s\n", glowa_wl->NazwaRuchu);
        glowa_wl = glowa_wl->next;
    } while(glowa_wl->next!=NULL);
}

szachownica * WykonajRuch(char *ruch_wr, szachownica *sz_wr){
    ruchy *p_wr = (ruchy*)malloc(sizeof(ruchy));
    p_wr = sz_wr->glowaMozliwychRuchow;
    int CzyPoprawnieWpisanyRuch_wr = 1;

    while(p_wr->next != NULL) {
        if((strcmp(p_wr->NazwaRuchu, ruch_wr) == 0)){
            sz_wr->szachownica[p_wr->KwadratDocelowy]=sz_wr->szachownica[p_wr->KwadratZrodlowy];
            sz_wr->szachownica[p_wr->KwadratZrodlowy] = 0;
            CzyPoprawnieWpisanyRuch_wr = 0;
            p_wr->next = NULL;
            break;
                
        }
        p_wr = p_wr->next;
    }
    if(CzyPoprawnieWpisanyRuch_wr == 1){
        if((strcmp(p_wr->NazwaRuchu, ruch_wr) == 0)){
            sz_wr->szachownica[p_wr->KwadratDocelowy]=sz_wr->szachownica[p_wr->KwadratZrodlowy];
            sz_wr->szachownica[p_wr->KwadratZrodlowy] = 0;
            CzyPoprawnieWpisanyRuch_wr = 0;
        }
        else{
            printf("zle wpisany ruch\n");
        }
    }
    if(CzyPoprawnieWpisanyRuch_wr == 0){
        if(sz_wr->strona == 8){
            sz_wr->strona = 16;
        }
        else{
            sz_wr->strona = 8;
        }
    }
    //ZwolnijRuchy(p_wr);
    return sz_wr;
}

ruchy * ZrobListeRuchow(int KwadratZKtoregoRuszaSieBierka_zlr, int KwadratNaKtoryRuszaSieBierka_zlr, ruchy *glowa_zlr){
    char NazwaRuchu1_zlr[5];
    char NazwaRuchu2_zlr[3];

    strcpy(NazwaRuchu1_zlr, notacja[KwadratZKtoregoRuszaSieBierka_zlr]);
    strcpy(NazwaRuchu2_zlr, notacja[KwadratNaKtoryRuszaSieBierka_zlr]);
    strcat(NazwaRuchu1_zlr, NazwaRuchu2_zlr);

    ruchy * temp_zlr = NULL;
    ruchy * p_zlr = NULL;

     

    temp_zlr = (ruchy*)malloc(sizeof(ruchy));
    p_zlr = (ruchy*)malloc(sizeof(ruchy));
    temp_zlr->KwadratZrodlowy = KwadratZKtoregoRuszaSieBierka_zlr;
    temp_zlr->KwadratDocelowy = KwadratNaKtoryRuszaSieBierka_zlr;
    strcpy(temp_zlr->NazwaRuchu, NazwaRuchu1_zlr);
    temp_zlr->next=NULL;


    if(glowa_zlr == NULL){
        glowa_zlr = temp_zlr;
    }
    else{
        p_zlr = glowa_zlr;
        while(p_zlr->next != NULL)
            p_zlr = p_zlr->next;
        p_zlr->next = temp_zlr;
    }
    // ZwolnijRuchy(temp_zlr);
    // ZwolnijRuchy(p_zlr);
    // free(NazwaRuchu1_zlr);
    // free(NazwaRuchu2_zlr);
    return glowa_zlr;
}

void WypiszPlansze(szachownica *sz_wp){
    for(int Pole = 0; Pole < 128; Pole++){
        if(!(Pole % 16)){
            printf(" %d. ", 8 - ( Pole / 16 ));
        }
        
            if(sz_wp->szachownica[Pole] == 0){
                if(!(((Pole & 16) || (Pole & 1))&&((!(Pole & 16)) || (!(Pole & 1))))){
                    printf(" %s", ((Pole & 8) && (Pole +=7)) ? "\n": Bierki[sz_wp->szachownica[Pole] & 15]);
                }
                else{
                    printf(" %s", ((Pole & 8) && (Pole +=7)) ? "\n": Bierki[1]);
                }
            }
            else{
                printf(" %s", ((Pole & 8) && (Pole +=7)) ? "\n" : Bierki[sz_wp->szachownica[Pole] & 15]);
            }
    }
    printf("\n     a b c d e f g h\n \n");
}

int PrzypiszBierke(int KwadratZKtoregoRuszaPionek, szachownica *sz_pb){
    int BierkaJakaZnajdujeSieNaPolu;
    BierkaJakaZnajdujeSieNaPolu = sz_pb->szachownica[KwadratZKtoregoRuszaPionek];

    return BierkaJakaZnajdujeSieNaPolu;
}









ruchy * MozliweRuchy(szachownica *sz_mr){
    int GraczKtoregoJestRuch = sz_mr->strona;
    ruchy *glowa_mr = NULL;
    int BierkaJakaZnajdujeSieNaPolu, RodzajPionkaBezWzgleduNaKolor, RuchWykonywanyPrzezPionek, KwadratNaKtoryRuszaSieBierka, Zbity_Kw, ZbitaBierka, Przejscie;
    for(int KwadratZKtoregoRuszaPionek = 0; KwadratZKtoregoRuszaPionek < 128; KwadratZKtoregoRuszaPionek++){
        if(!(KwadratZKtoregoRuszaPionek & 0x88)){
            BierkaJakaZnajdujeSieNaPolu = sz_mr->szachownica[KwadratZKtoregoRuszaPionek];

            if(BierkaJakaZnajdujeSieNaPolu & GraczKtoregoJestRuch){

                RodzajPionkaBezWzgleduNaKolor = BierkaJakaZnajdujeSieNaPolu & 7;
                if(BierkaJakaZnajdujeSieNaPolu == 9){
                    
                    glowa_mr = bialy_pionek(KwadratZKtoregoRuszaPionek, glowa_mr, sz_mr);
                }
                else if(BierkaJakaZnajdujeSieNaPolu ==18){
                    glowa_mr = czarny_pionek(KwadratZKtoregoRuszaPionek, glowa_mr, sz_mr);
                }
                else if((RodzajPionkaBezWzgleduNaKolor == 3) || (RodzajPionkaBezWzgleduNaKolor == 4)){
                    glowa_mr = krol_kon(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, RodzajPionkaBezWzgleduNaKolor, glowa_mr, sz_mr);
                }
                            
                else if((RodzajPionkaBezWzgleduNaKolor >= 5) || (RodzajPionkaBezWzgleduNaKolor <= 7)){
                    glowa_mr = hetman_goniec_wieza(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, RodzajPionkaBezWzgleduNaKolor, glowa_mr, sz_mr);
                }               
            }
        }
    }
    return glowa_mr; 
}
