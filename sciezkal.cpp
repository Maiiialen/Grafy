#include <iostream>
#include "wierzcholek.cpp"

using namespace std;

class Sciezkal {
    int waga;
    Wierzcholek * koniec;

    public:
    
    Sciezkal(Wierzcholek * kon, int w){
        koniec = kon;
        waga = w;
    }

    int Kon(){
        return koniec->Index();
    }

    int Wartosc(){
        return waga;
    }
};