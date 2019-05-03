#include <iostream>
#include <vector>
#include <ctime>
#include "sciezka.cpp"

using namespace std;

class Graf {
    Sciezka *** Macierz;
    vector <Sciezka *> Sciezki;
    vector <Wierzcholek *> Wierzcholki;

    public:

    Graf(int il_wierz);
    void Tworzenie_sc(int proc);
    void Wyswietlanie();
};

void Graf::Wyswietlanie(){
    for(int i = 0; i < Wierzcholki.size(); ++i){
        for(int j = 0; j < Wierzcholki.size(); ++j){
            if(Macierz[i][j] != NULL){
                cout << Macierz[i][j]->Wartosc() << " ";    //czy nie NULL
            } else {
                cout << "x ";
            }
        }
        cout << endl;
    }
}

Graf::Graf(int il_wierz){
    Macierz = new Sciezka ** [il_wierz];
    for(int i = 0; i < il_wierz; ++i){
        Macierz[i] = new Sciezka * [il_wierz];
    }
    for(int i = 0; i < il_wierz; ++i){
        for(int j = 0; j < il_wierz; ++j){
            Macierz[i][j] = NULL;
        }
    }
    for(int i = 0; i < il_wierz; ++i){
        Wierzcholki.push_back(new Wierzcholek(i));
    }
}

void Graf::Tworzenie_sc(int proc){
    srand(time(NULL));
    int ilosc = proc*(Wierzcholki.size()*(Wierzcholki.size()-1))/200, wartosc, i, p, k, test, n = Wierzcholki.size() -1;
    if(proc != 100){
        for(int i=0; i < Wierzcholki.size() - 1; ++i){
            wartosc = (rand() % 20) + 0;
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
                if(Macierz[p][k] == NULL){
                    Sciezki.push_back(new Sciezka(Wierzcholki[p], Wierzcholki[k], wartosc, i));
                    Macierz[p][k]=Sciezki[i-1];
                    Macierz[k][p]=Sciezki[i-1];
                }
            }
        }
    } else {
        for(int z = 0; z < Wierzcholki.size(); ++z){
            for(int c = 0; c < Wierzcholki.size(); ++c){
                if(z != c && Macierz[z][c] == NULL){
                    Sciezki.push_back(new Sciezka(Wierzcholki[z], Wierzcholki[c], rand() % 20 + 1, Sciezki.size()));
                    Macierz[z][c] = Sciezki[Sciezki.size()-1];
                    Macierz[c][z] = Sciezki[Sciezki.size()-1];
                }
            }
        }
    }
}