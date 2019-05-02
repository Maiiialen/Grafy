#include <iostream>
#include <vector>
#include <ctime>
#include "wierzcholek.cpp"
#include "sciezka.cpp"

using namespace std;

class Graf {
    Sciezka *** Macierz;
    vector <Sciezka *> Sciezki;
    vector <Wierzcholek *> Wierzcholki;

    public:

    Graf(int il_wierz){
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

    void Tworzenie_sc(int proc){
        srand(time(NULL));
        int ilosc = proc*Wierzcholki.size()/100, wartosc, p, k, test;
        for(int i=0; i < Wierzcholki.size() - 1; ++i){
            wartosc = (std::rand() % 20) + 0;
            Sciezki.push_back(new Sciezka(Wierzcholki[i], Wierzcholki[i+1], wartosc, i));

            Macierz[Wierzcholki[i]->Index()][Wierzcholki[i+1]->Index()]=Sciezki[i];
            Macierz[Wierzcholki[i+1]->Index()][Wierzcholki[i]->Index()]=Sciezki[i];
        }
        
        for(int i=Sciezki.size() - 1; i < ilosc; ++i){
            wartosc = (std::rand() % 20) + 0;
            p = (std::rand() % (Wierzcholki.size()-1)) + 0;
            k = (std::rand() % (Wierzcholki.size()-1)) + 0;
            if(p != k){
                test=0;
                for(int j = 0; j < Wierzcholki.size(); ++j){
                    if(test==1)
                        break;

                    for(int k = 0; k < Wierzcholki.size(); ++k){
                        if(Macierz[j][k]->Pocz == p && Macierz[j][k]->Kon == k){
                            test=1;
                            break;
                        }
                    }
                }
                if(test==0){
                    Sciezki.push_back(new Sciezka(Wierzcholki[i], Wierzcholki[i+1], wartosc, i));
                }
            }
        }
    }

    void Wyzwietlanie(){
    
    }
};
