#include <iostream>
#include <fstream>
#include "dijkstramacierz.cpp"
#include "dijkstra_lista.cpp"

using namespace std;

void Grafm::Wczytanie_z_pliku(string nazwa){
    fstream plik;                      //utworzenie zmiennej dostępu do pliku
    int il_kraw, il_wierz, pierwszy, pocz, kon, waga;
    plik.open(nazwa, ios::in);  //otworzenie pliku w opcji czytania
    if(plik.good() == true ){          //sprawdzenie czy otworzenie/utworzenie pliku się powiodło
        plik >> il_kraw >> il_wierz >> pierwszy;
        Grafm gr(il_wierz);
        for(int i = 0; i < il_kraw; ++i){
            plik >> pocz >> kon >> waga;
            Sciezki.push_back(new Sciezka(Wierzcholki[pocz], Wierzcholki[kon], waga, Sciezki.size()));
            Macierz[pocz][kon]=Sciezki[Sciezki.size()-1];
            Macierz[kon][pocz]=Sciezki[Sciezki.size()-1];
        }
    }
    plik.close();
}

void Grafl::Wczytanie_z_pliku(string nazwa){
    fstream plik;                      //utworzenie zmiennej dostępu do pliku
    int il_kraw, il_wierz, pierwszy, pocz, kon, waga;
    plik.open(nazwa, ios::in);  //otworzenie pliku w opcji czytania
    if(plik.good() == true ){          //sprawdzenie czy otworzenie/utworzenie pliku się powiodło
        plik >> il_kraw >> il_wierz >> pierwszy;
        Grafl gr(il_wierz);
        for(int i = 0; i < il_kraw; ++i){
            plik >> pocz >> kon >> waga;
            Tablica[pocz].dod_na_pocz(new Sciezkal(Wierzcholki[kon], waga));
            Tablica[kon].dod_na_pocz(new Sciezkal(Wierzcholki[pocz], waga));
        }
    }
    plik.close();
}
