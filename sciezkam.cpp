#include <iostream>
#include "wierzcholek.cpp"

using namespace std;

// klasa ścieżki wykorzystywana w reprezentacji grafu
// jako macierz sąsiedztwa
// waga - nieujemna wartość ścieżki
// początek i koniec - wskaźniki na klasę Wierzcholek oznaczające
//     początkowy i końcowy wierzcholek ścieżki
// index - numer ścieżki w liście ścieżek
class Sciezka {
    int waga;
    Wierzcholek * poczatek;
    Wierzcholek * koniec;
    int index;

    public:
    
    // konstruktor ścieżki, nadający wagę i index ścieżki oraz 
    //     ustawiający wskaźniki na wierzchołki początkowy i końcowy
    Sciezka(Wierzcholek * pocz, Wierzcholek * kon, int w, int i){
        poczatek = pocz;
        koniec = kon;
        waga = w;
        index = i;
    }

    // destruktor ścieżki, wywołujący destruktory dla klasy Wierzcholek
    ~Sciezka(){
        delete poczatek;
        delete koniec;
    }

    // funkcja zwracająca index wierzchołka początkowego
    int Pocz(){
        return poczatek->Index();
    }

    // funkcja zwracająca index wierzchołka końcowego
    int Kon(){
        return koniec->Index();
    }

    // funkcja zwracająca wagę ścieżki
    int Wartosc(){
        return waga;
    }
};