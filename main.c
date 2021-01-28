#include "struktury.h"


/*
Projekt szachy labolatoria Aleksander Wyzykowski oraz Kacper Chamera

Instrukcja jak zagrac:
        1. Na poczatku nalezy wpisac make aby skompilowac program.
        2. Nastepnie nalezy wpisac "make graj" aby uruchomic skompilowany program.
        3. Przez reszte ustawien poprowadzi gra.


1.  Program na poczatku ustawia odpowiednie struktury
2.  Nastepnie zbiera dane od uzytkownika czy chce zagrac z botem czy z drugim graczem
3.  Po zebraniu informacji wchodzi w petle while ktora dziala do momentu gdy
    oba krole znajduja sie na planszy
4.  Program skanuje wszystkie mozliwe ruchy i zapisuje je w postaci tablicy jednokierunkowej
5.  Program zczytuje od uzytkownika komende ruchu informujaca z ktorego kwadratu na ktory ma sie ruszyc bierka
6.  Nastepnie program porownoje wpisany ruch z baza ruchow wygenerowanych dla danego ustawienia szachownicy
7.  W przypadku znalezienia takiego ruchu program wykonuje ruch i zmienia strone,
    w przeciwnym razie zapetla sie jeszcze raz kazac wpisac poprawny ruch.

    Bot na ta chwile nie dziala, ma problem z dobrym symulowaniem ustawienia szachownicy,
    algorytmy (negaMax) sterujace botem sa na pewno dobrze napisane. Aby zobaczyc dzialanie bota
    nalezy odkomentowac

    Szachownica jest przechowywana na tablicy jednowymiarowej.
    Podczas programowania zapoznalismy sie z logika bitwise ktora umozliwila przechowywanie ogromnej
    ilosci danych na zmiennych typu "int". W pliku bierki.txt znajduje sie opis jak sa interpretowane
    zmienne typu int na bierki na planszy.

    Uwazamy za godne zwrocenia uwagi liste ruchow bierek ktora jest bardzo kompaktowa
    i zawiera wszystkie podstawowe ruchy wykonywane prez figury. Rodzaj bierki bez wzgledu na kolor
    rozroznia bierki na pionki czarne, pionki biale, krole, gonce, hetmany, konie oraz wieze.
    Bierki sa opisane w dany sposob:
        0   0   0   0   0
        ^   ^   ^   ^   ^
        |   |   trzy ostatnie bity opisuja rodzaj bierki ktory mozna sprawdzic wykorzystujac &7
        |   ten bit odpowiada za informacje czy bierka jest biala sprawdza sie wykorzystujac &8
        ten bit odpowiada z a informacje czy bierka jest czarna sprawdza sie wykorzystujac &16

    Nastepnie do otrzymanego wyniku z wykorzystaniem &7 dodaje sie 30  i otrzymuje wynik, od ktorego
    nalezy rozpoczac skanowanie mozliwych ruchow (w tej samej tablicy!) do momentu kiedy program
    natknie sie na 0.

    Program szachowy ma dodatkowy potencjal poniewaz polowa szachownicy[128] jest niewykorzystana.
    Na wolnej przestrzeni mozna zaimplementowac wartosci danych pol ktore dodatkowo pomoglyby w ocenie
    botowi na jakie pole sie ruszyc. Z powodu goniacego deadline'u nie udalo sie tej opcji zaimplementowac.

*/

int main(){
    ruchy *glowa_main = (ruchy*)malloc(sizeof(ruchy));
    szachownica * sz_main = (szachownica*)malloc(sizeof(szachownica));
    sz_main = UstawSzachownice(sz_main);
    char ruch_main[5];
    char info_main[2];
    char info2_main[2];
    int StronaGracza_main = 0;

    printf("Czy chcesz grać z drugim graczem? Y/N\n");
    scanf("%c", info_main);
    if(strcmp("N", info_main)==0){
        printf("Wybierz kolor bierek: C/B\n");
        scanf("%s", info_main);
        if(strcmp("B", info_main)==0){
            StronaGracza_main = 8;
        }
        else{
            StronaGracza_main = 16;
        }
    }

    int Ocena_main = 0;
    Ocena_main = OcenaGry(sz_main);
    WypiszPlansze(sz_main);
    while(Ocena_main == 0){
        if(StronaGracza_main == 0){
            sz_main->glowaMozliwychRuchow = MozliweRuchy(sz_main);
            printf("Jaki ruch wykonujesz?\n Napisz \"list\" aby wypisac liste dostepnych ruchow.\n");
            scanf("%s", ruch_main);
            sz_main = WykonajRuch(ruch_main, sz_main, sz_main->glowaMozliwychRuchow);
            WypiszPlansze(sz_main);
        }
        else if(sz_main->strona == StronaGracza_main){
            sz_main->glowaMozliwychRuchow = MozliweRuchy(sz_main);
            printf("Jaki ruch wykonujesz?\n Napisz \"list\" aby wypisac liste dostepnych ruchow.\n");
            scanf("%s", ruch_main);
            sz_main = WykonajRuch(ruch_main, sz_main, sz_main->glowaMozliwychRuchow);
            WypiszPlansze(sz_main);
        }
        else {
            
            WypiszPlansze(sz_main);
            sz_main = najlepszyRuch(sz_main, 6, -200, 200);
            sz_main->strona = 16;

        }
        
        Ocena_main = OcenaGry(sz_main);
    }
    
    free(sz_main);
    free(glowa_main);
    
    return 0;
}