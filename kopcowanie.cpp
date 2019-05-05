#include <iostream>
#include <vector>
#include "wierzcholek.cpp"

using namespace std;

// Funkcja składowa algorytmu sortowania przez wstawianie
// wejścia: tablica dynamiczna "tab", indeks pierwszego "pierwszy" elementu
//  ilość elementów do posortowania "n", indeks badanego elementu "i"
void tworzenie(vector <Wierzcholek> & tab, int poczatek, int n, int i){
    int largest = i;                                            //"largest" ustanowienie zmiennej jako rodzica
    int r = 2*i + 2, l = 2*i + 1;                               //obliczenie indeksów "dzieci" przed przesunięciem o "początek" przedziału sortowanego z tablicy
    int zmienna;                                                //    przesunięcie następuje dopiero przy porównaniach
    if(l < n && tab[l + poczatek] < tab[largest + poczatek]){   //sprawdzanie czy "l" należy do przedziału i jest większe od "rodzica"
        largest = l;                                            //zmiana indeksu na który wskazuje "largest"
    }
    if (r < n && tab[r + poczatek] < tab[largest + poczatek]){   //sprawdzanie czy "r" należy do przedziału i jest większe od "rodzica"
        largest = r;                                             //zmiana indeksu na który wskazuje "largest"
    }
    if(largest != i){                                            //sprawdzenie czy wartość badana "i" jest nadal największa
        zmienna = tab[largest + poczatek].Odleglosc();                       //zamiana wartości pod indeksami "largest" i "i"
        tab[largest + poczatek] = tab[i + poczatek];
        tab[i + poczatek] = zmienna;
        tworzenie(tab, poczatek, n, largest);                    //rekurencja funkcji dla zmienionych danych wejściowych
    }
}

// Funkcja wykonująca algorytm sortowania przez kopcowanie
// wejścia: tablica dynamiczna "tab", indeks pierwszego "pierwszy"
// i ostatniego "koniec" elementu
void kopcowanie(vector <Wierzcholek> & tab, int poczatek, int koniec){
    int zmienna;
    int n = koniec - poczatek + 1;                              //ilość elementów

    for(int i = n/2 -1; i >= 0; i--){                           //pętla wykonująca się dla elementów o indeksach od połowy do 0
        tworzenie(tab, poczatek, n, i);                         //wywołanie funkcji tworzącej drzewo binarne
    }

    for(int i = n - 1; i > 0; i--){                             //pętla wykonująca się dla całej tablicy
        zmienna = tab[poczatek].Odleglosc();                            //zamiana wartości
        tab[0 + poczatek] = tab[i + poczatek];
        tab[i + poczatek] = zmienna;
        n--;
        tworzenie(tab, poczatek, n, 0);                         //wywołanie funkcji tworzącej drzewo binarne
    }
}

