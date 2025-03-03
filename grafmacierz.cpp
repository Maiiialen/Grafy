#include <iostream>
#include <vector>
#include <ctime>
#include "sciezkam.cpp"

using namespace std;

class Grafm {
    Sciezka *** Macierz;
    vector <Sciezka *> Sciezki;
    vector <Wierzcholek *> Wierzcholki;

    public:

    Grafm(int il_wierz);
    ~Grafm();
    void Tworzenie_sc(int proc);
    void Wyswietlanie();
    int Wierz_size();
    void Wczytanie_z_pliku(string nazwa);
    void dijkstra(int poczatek);
    void dijkstra(int pocz, int koniec);
    int minodl(int dl[], bool odwiedzone[]);
};

Grafm::~Grafm(){
    for(int i = 0; i < Wierz_size(); ++i){
        for(int j = 0; j < Wierz_size(); ++j){
            delete Macierz[i][j];
        }
    }
    for(int i = 0; i < Wierz_size(); ++i){
        delete Macierz[i];
    }
    delete Macierz;
}

int Grafm::Wierz_size(){
    return Wierzcholki.size(); 
}

void Grafm::Wyswietlanie(){
    for(int i = 0; i < Wierzcholki.size(); ++i){
        for(int j = 0; j < Wierzcholki.size(); ++j){
            cout << Macierz[i][j]->Wartosc() << " ";
        }
        cout << endl;
    }
}

Grafm::Grafm(int il_wierz){
    Macierz = new Sciezka ** [il_wierz];
    for(int i = 0; i < il_wierz; ++i){
        Macierz[i] = new Sciezka * [il_wierz];
    }
    for(int i = 0; i < il_wierz; ++i){
        for(int j = 0; j < il_wierz; ++j){
            Macierz[i][j] = new Sciezka(new Wierzcholek(i), new Wierzcholek(j), 0, 0);
        }
    }
    for(int i = 0; i < il_wierz; ++i){
        Wierzcholki.push_back(new Wierzcholek(i));
    }
}

void Grafm::Tworzenie_sc(int ilosc){
    srand(time(NULL));
    int proc = 200*ilosc/(Wierz_size()*(Wierz_size()-1));
    int wartosc, i, p, k, test, n = Wierzcholki.size() -1;
    if(proc != 100){
        for(int i=0; i < Wierzcholki.size() - 1; ++i){
            wartosc = (rand() % 20) + 1;
            Sciezki.push_back(new Sciezka(Wierzcholki[i], Wierzcholki[i+1], wartosc, i));

            Macierz[i][i+1]=Sciezki[i];
            Macierz[i+1][i]=Sciezki[i];
        }

        while(Sciezki.size() < ilosc){
            i = Sciezki.size()-1;
            wartosc = rand() % 20 + 1;
            p = rand() % n + 1;
            k = rand() % n + 1;
            if(p != k){
                if(Macierz[p][k]->Wartosc() == 0){
                    Sciezki.push_back(new Sciezka(Wierzcholki[p], Wierzcholki[k], wartosc, Sciezki.size()));
                    Macierz[p][k] = Sciezki[Sciezki.size()-1];
                    Macierz[k][p] = Sciezki[Sciezki.size()-1];
                }
            }
        }
    } else {
        for(int z = 0; z < Wierzcholki.size(); ++z){
            for(int c = 0; c < Wierzcholki.size(); ++c){
                if(z != c && Macierz[z][c]->Wartosc() == 0){
                    Sciezki.push_back(new Sciezka(Wierzcholki[z], Wierzcholki[c], rand() % 20 + 1, Sciezki.size()));
                    Macierz[z][c] = Sciezki[Sciezki.size()-1];
                    Macierz[c][z] = Sciezki[Sciezki.size()-1];
                }
            }
        }
    }
}