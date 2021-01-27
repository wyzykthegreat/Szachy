
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

    do {
        if((strcmp(p_wr->NazwaRuchu, ruch_wr) == 0)){
            if(sz_wr->enpassant == p_wr->KwadratDocelowy){
                if(sz_wr->szachownica[p_wr->KwadratZrodlowy] == 9){
                    sz_wr->szachownica[p_wr->KwadratDocelowy +16] = 0;
                }
                
                if(sz_wr->szachownica[p_wr->KwadratZrodlowy] == 18){
                    sz_wr->szachownica[p_wr->KwadratDocelowy -16] = 0;
                }
            }
            if(sz_wr->szachownica[p_wr->KwadratZrodlowy]==9){
                if(p_wr->KwadratZrodlowy == p_wr->KwadratDocelowy + 32){
                    sz_wr->enpassant = p_wr->KwadratDocelowy + 16;
                }
            }
            else if(sz_wr->szachownica[p_wr->KwadratZrodlowy]==18){
                if(p_wr->KwadratZrodlowy == p_wr->KwadratDocelowy - 32){
                    sz_wr->enpassant = p_wr->KwadratDocelowy - 16;
                }
            }
            else{
                sz_wr->enpassant = -1;
            }
            if(((sz_wr->szachownica[p_wr->KwadratZrodlowy] & 7) == 6) && ((p_wr->KwadratZrodlowy == 112)||(p_wr->KwadratZrodlowy == 119))){
                if((sz_wr->strona&8) && (sz_wr->szachownica[p_wr->KwadratZrodlowy] & 8)){
                    if(p_wr->KwadratZrodlowy == 112){
                        sz_wr->roszadaBialyQueenSide = 0;
                    }
                    else if(p_wr->KwadratZrodlowy == 119){
                        sz_wr->roszadaBialyKingSide = 0;
                    }
                }
            }
            if(((sz_wr->szachownica[p_wr->KwadratZrodlowy] & 7) == 6) && ((p_wr->KwadratZrodlowy == 0)||(p_wr->KwadratZrodlowy == 7))){
                if((sz_wr->strona & 16) && (sz_wr->szachownica[p_wr->KwadratZrodlowy] & 16)){
                    if(p_wr->KwadratZrodlowy == 0){
                        sz_wr->roszadaCzarnyQueenSide = 0;
                    }
                    else if(p_wr->KwadratZrodlowy == 7){
                        sz_wr->roszadaCzarnyKingSide = 0;
                    }
                
                }
            }
            if((sz_wr->szachownica[p_wr->KwadratZrodlowy] & 7) == 3){
                if(p_wr->KwadratZrodlowy == 116){
                    sz_wr->roszadaBialyKingSide = 0;
                    sz_wr->roszadaBialyQueenSide = 0;
                    if(p_wr->KwadratDocelowy == 114){
                        sz_wr->szachownica[112]=0;
                        sz_wr->szachownica[115]= 14;
                    }
                    else if(p_wr->KwadratDocelowy == 118){
                        sz_wr->szachownica[119]=0;
                        sz_wr->szachownica[117]= 14;
                    }
                }
                else if(p_wr->KwadratZrodlowy == 4){
                    sz_wr->roszadaCzarnyKingSide = 0;
                    sz_wr->roszadaCzarnyQueenSide = 0;
                    if(p_wr->KwadratDocelowy == 2){
                        sz_wr->szachownica[0]=0;
                        sz_wr->szachownica[3]= 22;
                    }
                    else if(p_wr->KwadratDocelowy == 6){
                        sz_wr->szachownica[7]= 0;
                        sz_wr->szachownica[5]= 22;
                    }
                }
            } 

            sz_wr->szachownica[p_wr->KwadratDocelowy]=sz_wr->szachownica[p_wr->KwadratZrodlowy];
            sz_wr->szachownica[p_wr->KwadratZrodlowy] = 0;
            CzyPoprawnieWpisanyRuch_wr = 0;
            
            p_wr->next = NULL;
            break;
                
        } 
        p_wr = p_wr->next;
    } while(p_wr->next != NULL);
    if(CzyPoprawnieWpisanyRuch_wr == 0){
        if(sz_wr->strona == 8){
            sz_wr->strona = 16;
        }
        else{
            sz_wr->strona = 8;
        }
    }
    else{
        printf("zly kod\n");
    }
    //free(p_wr);
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
                else if(RodzajPionkaBezWzgleduNaKolor == 3){
                    glowa_mr = krol(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, RodzajPionkaBezWzgleduNaKolor, glowa_mr, sz_mr);
                }

                else if(RodzajPionkaBezWzgleduNaKolor == 4){
                    glowa_mr = kon(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, RodzajPionkaBezWzgleduNaKolor, glowa_mr, sz_mr);
                }
                            
                else if((RodzajPionkaBezWzgleduNaKolor >= 5) || (RodzajPionkaBezWzgleduNaKolor <= 7)){
                    glowa_mr = hetman_goniec_wieza(GraczKtoregoJestRuch, KwadratZKtoregoRuszaPionek, RodzajPionkaBezWzgleduNaKolor, glowa_mr, sz_mr);
                }               
            }
        }
    }
    return glowa_mr; 
}
