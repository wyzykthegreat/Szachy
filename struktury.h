#ifndef _STRUKTURY_H
#define _STRUKTURY_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static int ListaRuchow[] = {

       15,  16,  32,   0,                           // operacje wykorzystywane do ruchu bialych pionkow
      -15, -16, -32,   0,                           // operacje wykorzystywane do ruchu czarnych pionkow
        1,  16,  -1, -16,   0,                      // operacje wykorzystywane do ruchu wiez
        1,  16,  -1, -16,  15, -15, 17, -17,  0,    // operacje wykorzystywane do ruchu dam, krolow i goncow
       14, -14,  18, -18,  31, -31, 33, -33,  0,    // operacje wykorzystywane do ruchu koni
        -1,  3,  12,  21,  16,   7, 12              //opisane kolejno poczatki mozliwych ruchow do wykonania przez poszczegolne figury
    };

static int Plansza[128] = {                

    22, 20, 21, 23, 19, 21, 20, 22,     0, 0, 0, 0, 0, 0, 0, 0,
    18, 18, 18, 18, 18, 18, 18, 18,     0, 0, 0, 0, 0, 0, 0, 0,
     0,  0,  0,  0,  0,  0,  0,  0,     0, 0, 0, 0, 0, 0, 0, 0,
     0,  0,  0,  0,  0,  0,  0,  0,     0, 0, 0, 0, 0, 0, 0, 0,
     0,  0,  0,  0,  0,  0,  0,  0,     0, 0, 0, 0, 0, 0, 0, 0,
     0,  0,  0,  0,  0,  0,  0,  0,     0, 0, 0, 0, 0, 0, 0, 0,
     9,  9,  9,  9,  9,  9,  9,  9,     0, 0, 0, 0, 0, 0, 0, 0,
    14, 12, 13, 15, 11, 13, 12, 14,     0, 0, 0, 0, 0, 0, 0, 0,

};

static char *notacja[] = {

    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",     "i8","j8","k8","l8","m8","n8","o8", "p8",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",     "i7","j7","k7","l7","m7","n7","o7", "p7",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",     "i6","j6","k6","l6","m6","n6","o6", "p6",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",     "i5","j5","k5","l5","m5","n5","o5", "p5",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",     "i4","j4","k4","l4","m4","n4","o4", "p4",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",     "i3","j3","k3","l3","m3","n3","o3", "p3",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",     "i2","j2","k2","l2","m2","n2","o2", "p2",
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",     "i1","j1","k1","l1","m1","n1","o1", "p1",

};

static char *Bierki[] = {

	".", "\u2588", "\u265F", "\u265A", "\u265E", "\u265D", "\u265C", "\u265B", 
	"-", "\u2659", "-", "\u2654", "\u2658", "\u2657", "\u2656", "\u2655",  

};

typedef struct _ruchy{
    int KwadratZrodlowy;
    int KwadratDocelowy;
    char NazwaRuchu[5];
    struct _ruchy *next;
} ruchy;

typedef struct _szachownica{
    int szachownica[128];
    int strona;
    int enpassant;
    int roszadaCzarnyKingSide;
    int roszadaCzarnyQueenSide;
    int roszadaBialyKingSide;
    int roszadaBialyQueenSide;
    
    ruchy *glowaMozliwychRuchow;
} szachownica;

void WypiszListe(ruchy *glowa_wl);
void WypiszPlansze(szachownica *sz_wp);

int OcenaGry();
int ZliczanieBierkek(szachownica *sz_zb);
int negaMax(szachownica *sz_nm, int glebokosc_nm, int alpha_nm, int beta_nm);
int PrzypiszBierke(int KwadratZKtoregoRuszaPionek, szachownica *sz_pb);

szachownica * UstawSzachownice(szachownica *sz_us);
szachownica * Ruch(szachownica *sz);
szachownica * WykonajRuch(char *ruch_wr, szachownica *sz_wr, ruchy *glowa_wr);
szachownica * najlepszyRuch(szachownica *sz_nr, int glebokosc_nr, int alfa_nr, int beta_nr);

ruchy * ZrobListeRuchow(int KwadratZKtoregoRuszaSieBierka_zlr, int KwadratNaKtoryRuszaSieBierka_zlr, ruchy *glowa_zlr);
ruchy * bialy_pionek(int KwadratZKtoregoRuszaPionek_bp, ruchy *glowa_bp, szachownica *sz_bp);
ruchy * czarny_pionek(int KwadratZKtoregoRuszaPionek_bp, ruchy *glowa_cp, szachownica *sz_cp);
ruchy * hetman_goniec_wieza(int Strona_hgw, int KwadratZKtoregoRuszaSieBierka_hgw, int RodzajBierkiBezWzgleduNaKolor_hgw, ruchy *glowa_hgw, szachownica *sz_hgw);
ruchy * kon(int Strona_kk, int KwadratZKtoregoRuszaSieBierka_kk, int RodzajBierkiBezWzgleduNaKolor_kk, ruchy *glowa_kk, szachownica *sz_kk);
ruchy * krol(int Strona_kk, int KwadratZKtoregoRuszaSieBierka_kk, int RodzajBierkiBezWzgleduNaKolor_kk, ruchy *glowa_kk, szachownica *sz_kk);
ruchy * MozliweRuchy(szachownica *sz_mr);






#endif

