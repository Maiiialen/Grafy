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
    int ilosc = proc*(Wierzcholki.size()*(Wierzcholki.size()-1))/200, wartosc, p, k, test, n = Wierzcholki.size() -1;
    for(int i=0; i < Wierzcholki.size() - 1; ++i){
        wartosc = (rand() % 20) + 0;
        Sciezki.push_back(new Sciezka(Wierzcholki[i], Wierzcholki[i+1], wartosc, i));

        Macierz[i][i+1]=Sciezki[i];
        Macierz[i+1][i]=Sciezki[i];
    }
    
    for(int i=Sciezki.size() - 2; i < ilosc;){
        
        wartosc = rand() % 20 + 1;
        p = rand() % n + 1;
        k = rand() % n + 1;
        if(p != k){
            test=0;
            for(int j = 0; j < Wierzcholki.size()-1; ++j){
                if(test==1)
                    break;

                for(int z = 0; z < Wierzcholki.size()-1; ++z){
                    if(Macierz[j][z] != NULL){
                        if(Macierz[j][z]->Pocz() == p && Macierz[j][z]->Kon() == k){
                            test=1;
                            cout << "korok " << p << " " << k << " : " << j << " " << z << endl;
                            break;
                        }
                    }
                }
            }
            if(test==0){
                cout << "koook " << p << " " << k << endl;
                ++i;
                Sciezki.push_back(new Sciezka(Wierzcholki[i], Wierzcholki[i+1], wartosc, i));
                Macierz[p][k]=Sciezki[Sciezki.size()-1];
                Macierz[k][p]=Sciezki[Sciezki.size()-1];
            }
        }
    }
    
}