#include <iostream>
#include <algorithm>
#include <climits>
#include "graflista.cpp"

using namespace std;

int Grafl::minodl(int dl[], bool odwiedzone[]){
    int male = INT_MAX, indx;
    for(int i = 0; i < Wierz_size(); ++i){
        if(odwiedzone[i] == 0 && dl[i] <= male){
            male = dl[i];
            indx = i;
        }
    }
    return indx;
}






void Grafl::dijkstra(int pocz){
    int poczatek = pocz, zmienna;
    bool *odwiedzone = new bool [Wierz_size()];
    int *dl = new int [Wierz_size()];
    Wezel* wezel_tymczasowy = new Wezel;;

    for (int i = 0; i < Wierz_size(); ++i){
        dl[i] = INT_MAX;
        odwiedzone[i] = 0;
    }
    dl[pocz] = 0;


    for(int i = 0; i < Wierz_size(); ++i){
        zmienna = minodl(dl, odwiedzone);
        odwiedzone[zmienna] = 1;
        wezel_tymczasowy = Tablica[zmienna].pierwszy();
        while(wezel_tymczasowy->Element() != NULL){
            if(!odwiedzone[wezel_tymczasowy->Element()->Kon()] && wezel_tymczasowy->Element()->Wartosc() && dl[zmienna] != INT_MAX && dl[zmienna] + wezel_tymczasowy->Element()->Wartosc() < dl[wezel_tymczasowy->Element()->Kon()]){
                dl[wezel_tymczasowy->Element()->Kon()] = dl[zmienna] + wezel_tymczasowy->Element()->Wartosc();
            }
            wezel_tymczasowy = wezel_tymczasowy->Nastepny();
        }
        
    }
    /*
    for (int i = 0; i < Wierzcholki.size(); ++i){
        cout << "i, dl: " << i << " " << dl[i] << endl;
    }
    */
}






void Grafl::dijkstra(int pocz, int kon){
    int poczatek = pocz, zmienna;
    bool *odwiedzone = new bool [Wierz_size()];
    int *dl = new int [Wierz_size()];
    Wezel* wezel_tymczasowy = new Wezel;;

    for (int i = 0; i < Wierz_size(); ++i){
        dl[i] = INT_MAX;
        odwiedzone[i] = 0;
    }
    dl[pocz] = 0;


    for(int i = 0; i < Wierz_size(); ++i){
        zmienna = minodl(dl, odwiedzone);
        odwiedzone[zmienna] = 1;
        wezel_tymczasowy = Tablica[zmienna].pierwszy();
        while(wezel_tymczasowy->Element() != NULL){
            if(!odwiedzone[wezel_tymczasowy->Element()->Kon()] && wezel_tymczasowy->Element()->Wartosc() && dl[zmienna] != INT_MAX && dl[zmienna] + wezel_tymczasowy->Element()->Wartosc() < dl[wezel_tymczasowy->Element()->Kon()]){
                dl[wezel_tymczasowy->Element()->Kon()] = dl[zmienna] + wezel_tymczasowy->Element()->Wartosc();
            }
            if(odwiedzone[wezel_tymczasowy->Element()->Kon()] == 1){
                break;
            }
            wezel_tymczasowy = wezel_tymczasowy->Nastepny();
        }
        
    }

    //cout << "i, dl: " << kon << " " << dl[kon] << endl;
}