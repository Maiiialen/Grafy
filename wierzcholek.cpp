#pragma once
#include <iostream>

using namespace std;

// klasa ścieżki wykorzystywana w reprezentacji grafu
// jako macierz sąsiedztwa i lista sąsiedztwa
// index - numer wierzcholka na liście wierzchołków
// odl - zmienna wykorzystywana w reprezentacji grafu jako macierz
class Wierzcholek {
    int index;
    int odl;

    public:

    // konstruktor wierzchołka, nadający index wierzchołka oraz zmiennej odl
    Wierzcholek(int indx){
        index = indx;
        odl = 0;
    }

    // funkcja zwracająca index wierzchołka
    int Index(){
        return index;
    }

    // funkcja zwracająca odległość od danego wierzchołka
    int Odleglosc(){
        return odl;
    }
    
    // funkcja zmieniająca index i odl wierzchołka
    void Zmiana(int in, int od){
        index = in;
        odl = od;
    }
};