#include <iostream>
#include "wierzcholek.cpp"

using namespace std;

// klasa ścieżki wykorzystywana w reprezentacji grafu
// jako lista sąsiedztwa
// waga - nieujemna wartość ścieżki
// koniec - wskaźnik na klasę Wierzcholek oznaczający
//     końcowy wierzcholek ścieżki
class Sciezkal {
    int waga;
    Wierzcholek * koniec;

    public:

    // konstruktor ścieżki, nadający wagę ścieżki oraz 
    //     ustawiający wskaźnik na wierzchołek końcowy
    Sciezkal(Wierzcholek * kon, int w){
        koniec = kon;
        waga = w;
    }

    // destruktor ścieżki, wywołujący destruktor dla klasy Wierzcholek
    ~Sciezkal(){
        delete koniec;
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