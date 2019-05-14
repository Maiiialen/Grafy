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

void czasy(){
    int proc[] = {25, 50, 75, 100};
    int ilosc[] = {10, 50, 100, 500, 1000};
    int il;

    for(int i = 0; i < 5; ++i){
        Grafm* gr = new Grafm(ilosc[i]);

        for(int j = 0; j < 4; ++j){
            zapis_nazwy("macierz_" + to_string(ilosc[i]) + "_" + to_string(proc[j]) + " ");     // zapis nazwy, ilości elementów i stopnia posortowania do pliku
            for(int k = 0; k < 100; ++k){
                il = proc[j]*(gr->Wierz_size()*(gr->Wierz_size()-1))/200;
                gr->Tworzenie_sc(il);
                chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();        //zczytanie chwili rozpoczęcia testu funkcji
                gr->dijkstra(j);
                chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();        //zczytanie chwili zakończenia testu funkcji
                chrono::duration<double> time = t2 - t1;
                zapis(time);
            }
        }
    }
    for(int i = 0; i < 5; ++i){
        cout << "tuuu" << endl;

        for(int j = 0; j < 4; ++j){
            zapis_nazwy("lista_" + to_string(ilosc[i]) + "_" + to_string(proc[j]) + " ");     // zapis nazwy, ilości elementów i stopnia posortowania do pliku

            for(int k = 0; k < 100; ++k){
                Grafl* gr = new Grafl(ilosc[i]);
                il = proc[j]*(gr->Wierz_size()*(gr->Wierz_size()-1))/200;
                gr->Tworzenie_sc(il);
                chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();        //zczytanie chwili rozpoczęcia testu funkcji
                gr->dijkstra(j);
                chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();        //zczytanie chwili zakończenia testu funkcji
                chrono::duration<double> time = t2 - t1;
                zapis(time);
                delete gr;
            }
        }
    }
}

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
