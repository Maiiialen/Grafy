#include <iostream>
#include <algorithm>
#include <climits>
#include "Grafmacierz.cpp"

using namespace std;

int Grafm::minodl(int dl[], bool odwiedzone[]){
    int male = INT_MAX, indx;
    for(int i = 0; i < Wierz_size(); ++i){
        if(odwiedzone[i] == 0 && dl[i] <= male){
            male = dl[i];
            indx = i;
        }
    }
    return indx;
}

void Grafm::dijkstra(int pocz){
    int poczatek = pocz, zmienna;
    bool *odwiedzone = new bool [Wierz_size()];
    int *dl = new int [Wierz_size()];

    for (int i = 0; i < Wierz_size(); ++i){
        dl[i] = INT_MAX;
        odwiedzone[i] = 0;
    }
    dl[pocz] = 0;


    for(int i = 0; i < Wierz_size(); ++i){
        zmienna = minodl(dl, odwiedzone);
        odwiedzone[zmienna] = 1;
        for(int j = 0; j < Wierz_size(); ++j){
            if(!odwiedzone[j] && Macierz[zmienna][j]->Wartosc() && dl[zmienna] != INT_MAX && dl[zmienna] + Macierz[zmienna][j]->Wartosc() < dl[j]){
                dl[j] = dl[zmienna] + Macierz[zmienna][j]->Wartosc();
            }
        }
    }
    /*
    for (int i = 0; i < Wierzcholki.size(); ++i){
        cout << "i, dl: " << i << " " << dl[i] << endl;
    }
    */
}

void Grafm::dijkstra(int pocz, int koniec){
    int poczatek = pocz, zmienna;
    bool *odwiedzone = new bool [Wierz_size()];
    int *dl = new int [Wierz_size()];

    for (int i = 0; i < Wierz_size(); ++i){
        dl[i] = INT_MAX;
        odwiedzone[i] = 0;
    }
    dl[pocz] = 0;


    for(int i = 0; i < Wierz_size(); ++i){
        zmienna = minodl(dl, odwiedzone);
        odwiedzone[zmienna] = 1;
        for(int j = 0; j < Wierz_size(); ++j){
            if(!odwiedzone[j] && Macierz[zmienna][j]->Wartosc() && dl[zmienna] != INT_MAX && dl[zmienna] + Macierz[zmienna][j]->Wartosc() < dl[j]){
                dl[j] = dl[zmienna] + Macierz[zmienna][j]->Wartosc();
            }
        }
        if(odwiedzone[koniec] == 1){
            break;
        }
    }

    //cout << "i, dl: " << koniec << " " << dl[koniec] << endl;
}