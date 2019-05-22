#include <iostream>
#include <vector>
#include <ctime>
#include "sciezkam.cpp"

using namespace std;

// klasa grafu wykorzystywana w reprezentacji grafu
// jako macierz sąsiedztwa
// macierz - macierz dwuwymiarowa zawierająca ścieżki łączące
//          wierzchołki o indekach macierzy
// Sciezki - tablica zawierająca wszystkie ścieżeki
// Wierzcholki - tablica zawierająca wszystkie wierzchołki
class Grafm {
    Sciezka *** Macierz;
    vector <Sciezka *> Sciezki;
    vector <Wierzcholek *> Wierzcholki;

    public:

    // konstruktor klasy Grafm tworzący macierz o dalej ilości wierszy i kolumn
    // il_wierz - ilość wierzchołków, a zarazem ilość wierszy i kolumn mamiezry
    Grafm(int il_wierz);

    // destruktor klasy Grafm usuwający wszystkie elemenry z macierzy i samą macierz
    ~Grafm();

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
    for(int i = 0; i < Wierzcholki.size(); ++i){        // przejście przez wszystkie wiersze macierzy
        for(int j = 0; j < Wierzcholki.size(); ++j){    // przejście przez wszystkie kolumny macierzy
            cout << Macierz[i][j]->Wartosc() << " ";    // wyświetlanie wagi ścieżki
        }
        cout << endl;
    }
}

Grafm::Grafm(int il_wierz){
    Macierz = new Sciezka ** [il_wierz];    //utworzenie wiersza
    for(int i = 0; i < il_wierz; ++i){      // tworzenie kolumn macierzy
        Macierz[i] = new Sciezka * [il_wierz];
    }
    for(int i = 0; i < il_wierz; ++i){
        for(int j = 0; j < il_wierz; ++j){
            Macierz[i][j] = new Sciezka(new Wierzcholek(i), new Wierzcholek(j), 0, 0);  // wpisywanie do macierzy ścieżek o wartościach 0
        }
    }
    for(int i = 0; i < il_wierz; ++i){      // tworzenie listy wierzchołków
        Wierzcholki.push_back(new Wierzcholek(i));
    }
}

// ilosc - ilość ścieżek, która ma zostać utworzona
void Grafm::Tworzenie_sc(int ilosc){
    srand(time(NULL));
    int proc = 200*ilosc/(Wierz_size()*(Wierz_size()-1));   // obliczenie jaki procent wszystkich możliwych ścieżek ma zostać utworzony
    int wartosc, i, p, k, test, n = Wierzcholki.size() -1;
    if(proc != 100){    // sprawdzenie czy ma to być graf o 100% gęstości
        for(int i=0; i < Wierzcholki.size() - 1; ++i){      // połączenie wszystkich wierzchołków (0-1, 1-2...), aby był to graf pełny
            wartosc = (rand() % 20) + 1;    // losowanie wagi ścieżki
            Sciezki.push_back(new Sciezka(Wierzcholki[i], Wierzcholki[i+1], wartosc, i));
            // zapisywanie ścieżek dwukierunkowych
            Macierz[i][i+1]=Sciezki[i];
            Macierz[i+1][i]=Sciezki[i];
        }
        // tworzenie nowych ścieżek dopełniając do ilości wymaganej
        while(Sciezki.size() < ilosc){
            i = Sciezki.size()-1;
            wartosc = rand() % 20 + 1;  // losowanie wagi ścieżki
            p = rand() % n + 1;         // losowanie indeksu wierzchołka początkowego
            k = rand() % n + 1;         // losowanie indeksu wierzchołka końcowego
            if(p != k){     // sprawdzenie czy indeksy nie są takie same
                if(Macierz[p][k]->Wartosc() == 0){      // jeśli wartość ścieżki w danym miejscu jest "0" to zapisujemy ścieżki dwukierunkowo
                    Sciezki.push_back(new Sciezka(Wierzcholki[p], Wierzcholki[k], wartosc, Sciezki.size()));
                    Macierz[p][k] = Sciezki[Sciezki.size()-1];
                    Macierz[k][p] = Sciezki[Sciezki.size()-1];
                }
            }
        }
    } else {    // jeśli  ma to byś graf pełny uzupełniamy wszystkie ścieżki po kolei losowymi wagami ścieżek
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