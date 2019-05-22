#include <iostream>
#include <vector>
#include <ctime>
#include "lista.cpp"

using namespace std;

// klasa grafu wykorzystywana w reprezentacji grafu
// jako macierz sąsiedztwa
// macierz - macierz dwuwymiarowa zawierająca ścieżki łączące
//          wierzchołki o indekach macierzy
// tablica - tablica list
// Wierzcholki - tablica zawierająca wszystkie wierzchołki
class Grafl {
    Lista* Tablica;
    vector <Wierzcholek *> Wierzcholki;

    public:

    // konstruktor klasy Grafm tworzący tablicę o dalej długości
    // il_wierz - ilość wierzchołków, a zarazem ilość wierszy i kolumn mamiezry
    Grafl(int il_wierz);

    // funkcja tworząca ścieżki grafu pełnego
    void Tworzenie_sc(int proc);

    // wyświetlanie macierzy na wyjściu standarsowym
    void Wyswietlanie();

    // funkcja zwracaająca ilość wierzchołków
    int Wierz_size();

    // funkcja wczytująca ścieżki z pliku i zapisująca je w macierzy
    void Wczytanie_z_pliku(string nazwa);

    // algorytm dijkstry szykający najkrótszych ścieżek do wszstkich pozostałych elementów
    // poczatek - wierzchołek początkowy, do którego szukamy najkrótszych ścieżek
    void dijkstra(int poczatek);

    // algorytm dijkstry szykający najkrótszej ścieżki między danymi wierzchołkami
    // poczatek - wierzchołek początkowy, do którego szukamy najkrótszej ścieżeki
    // koniec - wierzchołek końcowy, do którego szukamy najkrótszej ścieżeki
    void dijkstra(int pocz, int koniec);

    // funkcja zwracająca index najbliższego wierzchołka do sprawdzanego
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

// ilosc - ilość ścieżek, która ma zostać utworzona
void Grafl::Tworzenie_sc(int ilosc){
    srand(time(NULL));
    int proc = 200*ilosc/(Wierz_size()*(Wierz_size()-1));   // obliczenie jaki procent wszystkich możliwych ścieżek ma zostać utworzony
    int wartosc, p, k, test, ilosc_sc=0;
    if(proc != 100){    // sprawdzenie czy ma to być graf o 100% gęstości
        for(int i=0; i < Wierz_size() - 1; ++i){
            //petla wykonujaca sie Wierz_size()-1 razy
            ++ilosc_sc;
            wartosc = (rand() % 20) + 1;    // losowanie wagi ścieżki

            // zapisywanie ścieżek dwukierunkowych
            Tablica[i].dod_na_pocz(new Sciezkal(Wierzcholki[i+1], wartosc));
            Tablica[i+1].dod_na_pocz(new Sciezkal(Wierzcholki[i], wartosc));
        }
        // tworzenie nowych ścieżek dopełniając do ilości wymaganej
        while(ilosc_sc < ilosc){
            p = rand() % Wierz_size()-1 + 1;         // losowanie indeksu wierzchołka początkowego
            k = rand() % Wierz_size()-1 + 1;         // losowanie indeksu wierzchołka końcowego
            if(p != k){
                if(!Czy_istnieje(Tablica[p], k)){
                    wartosc = rand() % 20 + 1;  // losowanie wagi ścieżki
                    ++ilosc_sc;

                    // zapisywanie ścieżek dwukierunkowych
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
                        wartosc = rand() % 20 + 1;  // losowanie wagi ścieżki
                        // zapisywanie ścieżek dwukierunkowych
                        Tablica[z].dod_na_pocz(new Sciezkal(Wierzcholki[c], wartosc));
                        Tablica[c].dod_na_pocz(new Sciezkal(Wierzcholki[z], wartosc));
                    }
                }
            }
        }
    }
}
