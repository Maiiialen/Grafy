#include <iostream>
#include <vector>
#include "czaszapis.cpp"

using namespace std;

int main(){
    Grafm gr(10);
    int proc = 25, ilosc = proc*(gr.Wierz_size()*(gr.Wierz_size()-1))/200;
    //gr.Tworzenie_sc(ilosc);
    gr.Wczytanie_z_pliku("test.txt");
    gr.dijkstra(5, 9);
    cout << endl;
    gr.dijkstra(5);
    cout << endl;
    //gr.Wyswietlanie();

}

// kiokokoko