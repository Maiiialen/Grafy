#include <iostream>
#include <vector>
#include <ctime>
#include "lista.cpp"

using namespace std;

class Grafl {
    Lista* Tablica;
    vector <Sciezkal *> Sciezki;
    vector <Wierzcholek *> Wierzcholki;
    int ilosc_wierzcholkow;

    public:

    Grafl(int il_wierz);
    void Tworzenie_sc(int proc);
    void Wyswietlanie();
    int Wierz_size();
    void Wczytanie_z_pliku(string nazwa);
    void dijkstra(int poczatek);
    void dijkstra(int pocz, int koniec);
    void kopcowanie(vector <int> &tab, int poczatek, int koniec);
    int minodl(int dl[], bool odwiedzone[]);
};

int Grafl::Wierz_size(){
    return ilosc_wierzcholkow; 
}
/*
void Grafl::Wyswietlanie(){
    for(int i = 0; i < Wierz_size(); ++i){
        for(int j = 0; j < Wierz_size(); ++j){
            cout << Tablica[i][j]->Wartosc() << " ";
        }
        cout << endl;
    }
}*/

Grafl::Grafl(int il_wierz){
    Tablica = new Lista [il_wierz];
    ilosc_wierzcholkow = il_wierz;
    for(int i = 0; i < il_wierz; ++i){
        Wierzcholki.push_back(new Wierzcholek(i));
    }
}
/*
void Grafl::Tworzenie_sc(int ilosc){
    srand(time(NULL));
    int proc = 200*ilosc/(Wierz_size()*(Wierz_size()-1));
    int wartosc, i, p, k, test, n = Wierz_size() -1;
    if(proc != 100){
        for(int i=0; i < Wierz_size() - 1; ++i){
            wartosc = (rand() % 20) + 1;
            Sciezki.push_back(new Sciezkal(Wierzcholki[i], Wierzcholki[i+1], wartosc, i));

            Tablica[i][i+1]=Sciezki[i];
            Tablica[i+1][i]=Sciezki[i];
        }

        while(Sciezki.size() < ilosc){
            i = Sciezki.size()-1;
            wartosc = rand() % 20 + 1;
            p = rand() % n + 1;
            k = rand() % n + 1;
            if(p != k){
                if(Tablica[p][k]->Wartosc() == 0){
                    Sciezki.push_back(new Sciezkal(Wierzcholki[p], Wierzcholki[k], wartosc, Sciezki.size()));
                    Tablica[p][k] = Sciezki[Sciezki.size()-1];
                    Tablica[k][p] = Sciezki[Sciezki.size()-1];
                }
            }
        }
    } else {
        for(int z = 0; z < Wierz_size(); ++z){
            for(int c = 0; c < Wierz_size(); ++c){
                if(z != c && Tablica[z][c]->Wartosc() == 0){
                    Sciezki.push_back(new Sciezkal(Wierzcholki[z], Wierzcholki[c], rand() % 20 + 1, Sciezki.size()));
                    Tablica[z][c] = Sciezki[Sciezki.size()-1];
                    Tablica[c][z] = Sciezki[Sciezki.size()-1];
                }
            }
        }
    }
}*/