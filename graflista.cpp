#include <iostream>
#include <vector>
#include <ctime>
#include "lista.cpp"

using namespace std;

class Grafl {
    Lista* Tablica;
    vector <Wierzcholek *> Wierzcholki;

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
    return Wierzcholki.size(); 
}

void Grafl::Wyswietlanie(){
    for(int i = 0; i < Wierz_size(); ++i){
        cout << "i: " << i << ", r: ";
        Tablica[i].Wyswietl_lista();
        cout << endl;
    }
}

Grafl::Grafl(int il_wierz){
    Tablica = new Lista [il_wierz];
    for(int i = 0; i < il_wierz; ++i){
        Wierzcholki.push_back(new Wierzcholek(i));
    }
}

void Grafl::Tworzenie_sc(int ilosc){
    srand(time(NULL));
    int proc = 200*ilosc/(Wierz_size()*(Wierz_size()-1));
    int wartosc, p, k, test, ilosc_sc=0;
    if(proc != 100){
        //sprawdzenie czy graf ma byc grafem pelnym
        for(int i=0; i < Wierz_size() - 1; ++i){
            //petla wykonujaca sie Wierz_size()-1 razy
            ++ilosc_sc;
            wartosc = (rand() % 20) + 1;

            Tablica[i].dod_na_pocz(new Sciezkal(Wierzcholki[i+1], wartosc));
            Tablica[i+1].dod_na_pocz(new Sciezkal(Wierzcholki[i], wartosc));
        }

        while(ilosc_sc < ilosc){
            p = rand() % Wierz_size()-1 + 1;
            k = rand() % Wierz_size()-1 + 1;
            if(p != k){
                if(!Czy_istnieje(Tablica[p], k)){
                    wartosc = rand() % 20 + 1;
                    ++ilosc_sc;

                    Tablica[p].dod_na_pocz(new Sciezkal(Wierzcholki[k], wartosc));
                    Tablica[k].dod_na_pocz(new Sciezkal(Wierzcholki[p], wartosc));
                }
            }
        }
    } else {
        for(int z = 0; z < Wierz_size(); ++z){
            for(int c = 0; c < Wierz_size(); ++c){
                if(z != c){
                    if(!Czy_istnieje(Tablica[z], c)){
                        wartosc = rand() % 20 + 1;
                        Tablica[z].dod_na_pocz(new Sciezkal(Wierzcholki[c], wartosc));
                        Tablica[c].dod_na_pocz(new Sciezkal(Wierzcholki[z], wartosc));
                    }
                }
            }
        }
    }
}
