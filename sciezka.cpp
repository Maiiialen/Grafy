#include <iostream>
#include "wierzcholek.cpp"

using namespace std;

class Sciezka {
    int waga;
    Wierzcholek * poczatek;
    Wierzcholek * koniec;
    int index;

    public:
    Sciezka(Wierzcholek * pocz, Wierzcholek * kon, int w, int i){
        poczatek = pocz;
        koniec = kon;
        waga = w;
        index = i;
    }

    int Pocz(){
        return poczatek->Index();
    }

    int Kon(){
        return koniec->Index();
    }

    int Wartosc(){
        return waga;
    }
};