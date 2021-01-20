#ifndef _RUCHY_BIEREK_H
#define _RUCHY_BIEREK_H

void ZrobListeRuchow(int KwadratZKtoregoRuszaSieBierka_zlr, int KwadratNaKtoryRuszaSieBierka_zlr);

void WypiszPlansze();

int PrzypiszBierke(int KwadratZKtoregoRuszaPionek);

void bialy_pionek(int KwadratZKtoregoRuszaPionek_bp);

void czarny_pionek(int KwadratZKtoregoRuszaPionek_cp);

void hetman_goniec_wieza(int Strona_hgw, int KwadratZKtoregoRuszaSieBierka_hgw, int RodzajBierkiBezWzgleduNaKolor_hgw);

void krol_kon(int Strona_kk, int KwadratZKtoregoRuszaSieBierka_kk, int RodzajBierkiBezWzgleduNaKolor_kk);

void MozliweRuchy(int GraczKtoregoJestRuch);

#endif
