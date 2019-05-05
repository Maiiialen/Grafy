#pragma once
#include <iostream>

using namespace std;

class Wierzcholek {
    int index;
    int odl;

    public:

    Wierzcholek(int indx){
        index = indx;
        odl = 0;
    }

    int Index(){
        return index;
    }

    int Odleglosc(){
        return odl;
    }
    
    void Zmiana(int in, int od){
        index = in;
        odl = od;
    }

    //!Przeciazamy operator mniejszosci dla klasy cWierzcholek
    friend bool operator < (const Wierzcholek &p1, const Wierzcholek &p2){
        return(p1.odl > p2.odl);
    }
};