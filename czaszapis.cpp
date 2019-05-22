#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "dijkstramacierz.cpp"
#include "dijkstra_lista.cpp"

using namespace std;

// Funkcja zapisująca do pliku pierwszą nazwę, która znajduję się jako pierwsza
//  w linii, dzięki czemu po odwróceniu tabelu w excelu będzie tytułem kolumny
// wejścia: napis "nazwa"
void zapis_nazwy(string nazwa){
    fstream plik;                       //utworzenie zmiennej dostępu do pliku
    plik.open( "pamsi6.txt", ios::app);  //otworzenie pliku w opcji dopisania
    if( plik.good() == true ){          //sprawdzenie czy otworzenie/utworzenie pliku się powiodło
        plik << endl;                   //wpisanie do pliku
        plik << nazwa << " ";
    }
    plik.close();                       //zamknięcie pliku
}

// Funkcja zapisująca do pliku zmierzone czasy działania funkcji sortujących,
//  oddziela je znakami spacji, aby móc je wczytać do programu Excel
// wejścia: czas otrzymany z pomiarów "time"
void zapis(chrono::duration<double> time){
    fstream plik;                       //utworzenie zmiennej dostępu do pliku
    plik.open( "pamsi6.txt", ios::app);  //otworzenie pliku w opcji dopisania
    if( plik.good() == true ){          //sprawdzenie czy otworzenie/utworzenie pliku się powiodło
        plik << " ";                    //wpisanie do pliku
        plik << time.count();
        plik.close();                   //zamknięcie pliku
    }
}

// Funkcja wykonująca testy we wszystkich nadanych przypadkach
//  i dla wszystkich badanych fuckcji
void czasy(){
    int proc[] = {25, 50, 75, 100};             // tablica gętości grafów
    int ilosc[] = {10, 50, 100, 500, 1000};     // tablica ilości wierzchołków w grafach
    int il;                                     // ilość ścieżek w grafie

    for(int i = 0; i < 5; ++i){   // pętla przechodząca przez ilosc[], zmienia ilość wierzchołków w grafie
        Grafm* gr = new Grafm(ilosc[i]);    // tworzenie grafu o reprezentacji jako macierz sąsiedztwa

        for(int j = 0; j < 4; ++j){     // pętla przechodząca przez proc[], zmienia gęstość grafu
            zapis_nazwy("macierz_" + to_string(ilosc[i]) + "_" + to_string(proc[j]) + " ");     // zapis nazwy, ilości elementów i stopnia posortowania do pliku
            for(int k = 0; k < 100; ++k){   // pętla wykonująca powtórzenie 100 razy
                il = proc[j]*(gr->Wierz_size()*(gr->Wierz_size()-1))/200;   // ustalenie ilości ścieżek
                gr->Tworzenie_sc(il);       // funkcja tworząca graf pełny o dalen ilości ścieżek
                chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();        //zczytanie chwili rozpoczęcia testu funkcji
                gr->dijkstra(j);    // wykonanie algorytmu dijkstry
                chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();        //zczytanie chwili zakończenia testu funkcji
                chrono::duration<double> time = t2 - t1;
                zapis(time);
            }
        }
    }
    for(int i = 0; i < 5; ++i){   // pętla przechodząca przez ilosc[], zmienia ilość wierzchołków w grafie
        cout << "tuuu" << endl;

        for(int j = 0; j < 4; ++j){     // pętla przechodząca przez proc[], zmienia gęstość grafu
            zapis_nazwy("lista_" + to_string(ilosc[i]) + "_" + to_string(proc[j]) + " ");     // zapis nazwy, ilości elementów i stopnia posortowania do pliku

            for(int k = 0; k < 100; ++k){   // pętla wykonująca powtórzenie 100 razy
                Grafl* gr = new Grafl(ilosc[i]);    // utworzenie nowego grafu przedstawionego jako lista sąsiedztwa
                il = proc[j]*(gr->Wierz_size()*(gr->Wierz_size()-1))/200;   // ustalenie ilości ścieżek
                gr->Tworzenie_sc(il);       // funkcja tworząca graf pełny o dalen ilości ścieżek
                chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();        //zczytanie chwili rozpoczęcia testu funkcji
                gr->dijkstra(j);    // wykonanie algorytmu dijkstry
                chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();        //zczytanie chwili zakończenia testu funkcji
                chrono::duration<double> time = t2 - t1;
                zapis(time);
                delete gr;  // usówanie grafu
            }
        }
    }
}

// funkcja wczytująca graf opisany na macierzy z pliku tekstowego
// zgodnie z wytycznymi w opisie projektu
// wejścia: nazwa pliku
void Grafm::Wczytanie_z_pliku(string nazwa){
    fstream plik;                      //utworzenie zmiennej dostępu do pliku
    int il_kraw, il_wierz, pierwszy, pocz, kon, waga;
    plik.open(nazwa, ios::in);  //otworzenie pliku w opcji czytania
    if(plik.good() == true ){          //sprawdzenie czy otworzenie/utworzenie pliku się powiodło
        plik >> il_kraw >> il_wierz >> pierwszy;    // wczytanie ilości krawędzi, wierzchołków i elementu dla którego szukamy ścieżek
        Grafm gr(il_wierz);     // utworzenie grafu
        for(int i = 0; i < il_kraw; ++i){
            plik >> pocz >> kon >> waga;        // zczytywanie z pliku parametrów ścieżek
            Sciezki.push_back(new Sciezka(Wierzcholki[pocz], Wierzcholki[kon], waga, Sciezki.size()));  // dodawanie nowych ścieżek do listy
            Macierz[pocz][kon]=Sciezki[Sciezki.size()-1];   // uzupełnianie macierzy o nową ścieżkę
            Macierz[kon][pocz]=Sciezki[Sciezki.size()-1];   // uzupełnianie macierzy o tę samą ścieżkę w drógą stronę
        }
    }
    plik.close();
}

// funkcja wczytująca graf opisany na listach z pliku tekstowego
// zgodnie z wytycznymi w opisie projektu
// wejścia: nazwa pliku
void Grafl::Wczytanie_z_pliku(string nazwa){
    fstream plik;                      //utworzenie zmiennej dostępu do pliku
    int il_kraw, il_wierz, pierwszy, pocz, kon, waga;    // wczytanie ilości krawędzi, wierzchołków i elementu dla którego szukamy ścieżek
    plik.open(nazwa, ios::in);  //otworzenie pliku w opcji czytania
    if(plik.good() == true ){          //sprawdzenie czy otworzenie/utworzenie pliku się powiodło
        plik >> il_kraw >> il_wierz >> pierwszy;
        Grafl gr(il_wierz);     // utworzenie grafu
        for(int i = 0; i < il_kraw; ++i){
            plik >> pocz >> kon >> waga;        // zczytywanie z pliku parametrów ścieżek
            Tablica[pocz].dod_na_pocz(new Sciezkal(Wierzcholki[kon], waga));   // uzupełnianie listy o nową ścieżkę
            Tablica[kon].dod_na_pocz(new Sciezkal(Wierzcholki[pocz], waga));   // uzupełnianie listy o tę samą ścieżkę w drógą stronę
        }
    }
    plik.close();
}
