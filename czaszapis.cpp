#include <iostream>
#include <fstream>
#include "graf.cpp"

using namespace std;

void Graf::Wczytanie_z_pliku(string nazwa){
    fstream plik;                       //utworzenie zmiennej dostępu do pliku
    int il_kraw, il_wierz, pierwszy, pocz, kon, waga;
    plik.open(nazwa, ios::in);  //otworzenie pliku w opcji czytania
    if(plik.good() == true ){          //sprawdzenie czy otworzenie/utworzenie pliku się powiodło
        plik >> il_kraw >> il_wierz >> pierwszy;
        Graf gr(il_wierz);
        for(int i = 0; i < il_kraw; ++i){
            plik >> pocz >> kon >> waga;
            Sciezki.push_back(new Sciezka(Wierzcholki[pocz], Wierzcholki[kon], waga, Sciezki.size()));
            Macierz[pocz][kon]=Sciezki[Sciezki.size()-1];
            Macierz[kon][pocz]=Sciezki[Sciezki.size()-1];
        }
    }
    plik.close(); 
}
