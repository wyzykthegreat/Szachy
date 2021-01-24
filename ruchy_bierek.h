#ifndef _RUCHY_BIEREK_H
#define _RUCHY_BIEREK_H


typedef struct _ruchy{
    int KwadratZrodlowy;
    int KwadratDocelowy;
    char NazwaRuchu[5];
    struct _ruchy *next;
} ruchy;

typedef struct _szachownica{
    int szachownica[128];
} szachownica;

szachownica * UstawSzachownice(szachownica *sz_us);

szachownica * WykonajRuch(int Strona_wr, char *ruch_wr, ruchy *glowa_wr, szachownica *sz_wr);

void WypiszListe(ruchy *glowa_wl);

ruchy * ZrobListeRuchow(int KwadratZKtoregoRuszaSieBierka_zlr, int KwadratNaKtoryRuszaSieBierka_zlr, ruchy *glowa_zlr);

int OcenaGry();

void WypiszPlansze(szachownica *sz_wp);

int PrzypiszBierke(int KwadratZKtoregoRuszaPionek, szachownica *sz_pb);

ruchy * bialy_pionek(int KwadratZKtoregoRuszaPionek_bp, ruchy *glowa_bp, szachownica *sz_bp);

ruchy * czarny_pionek(int KwadratZKtoregoRuszaPionek_bp, ruchy *glowa_cp, szachownica *sz_cp);

ruchy * hetman_goniec_wieza(int Strona_hgw, int KwadratZKtoregoRuszaSieBierka_hgw, int RodzajBierkiBezWzgleduNaKolor_hgw, ruchy *glowa_hgw, szachownica *sz_hgw);

ruchy * krol_kon(int Strona_kk, int KwadratZKtoregoRuszaSieBierka_kk, int RodzajBierkiBezWzgleduNaKolor_kk, ruchy *glowa_kk, szachownica *sz_kk);

ruchy * MozliweRuchy(int GraczKtoregoJestRuch, ruchy * glowa_mr, szachownica *sz_mr);

#endif
