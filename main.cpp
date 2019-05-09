#include <iostream>
#include <vector>
#include "czaszapis.cpp"

using namespace std;

int main(){
    Grafm* gr = new Grafm(10);
    int proc = 25, ilosc = proc*(gr->Wierz_size()*(gr->Wierz_size()-1))/200;
    gr->Tworzenie_sc(ilosc);
    //gr.Wyswietlanie();
    //gr.Wczytanie_z_pliku("test.txt");
    gr->dijkstra(1, 7);
    cout << endl;
    gr->dijkstra(0);
    delete gr;

    cout << "a" << endl;
    cout << "cos " << gr->Wierz_size() << endl;
    cout << "b" << endl;

    Wierzcholek* wierz = new Wierzcholek(1);
    cout << "a " << wierz->Index();
    delete[] wierz;
    cout << "b " << wierz->Index();
}

// kiokokoko