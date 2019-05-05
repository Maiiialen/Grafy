#include <iostream>
#include <vector>
#include "kopcowanie.cpp"

using namespace std;

    void Stworz(vector <Wierzcholek> & tab){
        kopcowanie(tab, 0, tab.size());
    }

    void Usun(vector <Wierzcholek> & tab){
        tab.pop_back();
    }
