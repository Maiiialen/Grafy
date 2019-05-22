#include <iostream>
#include "Sciezkal.cpp"

using namespace std;

// deklaracja klasy Lista
class Lista;

// klasa Wezel tworząca węceł w liście jednokierunkowej
// element - wskaźnik na ścieżkę
// nastepny - wskaźnik na następny węzeł
class Wezel {
    Sciezkal* element;
    Wezel* nastepny;
    friend class Lista;     // pozwolenie klasie Lista na dostęp do parametrów klasy Wezel

    public:
    // funkcja in-line, zwracająca wskaźnik na element (ściężkę)
    Sciezkal* Element(){ return element; }

    // funkcja in-line, zwracająca wskaźnik na następny element(ściężkę)
    Wezel* Nastepny(){ return nastepny; }

    // funkcja in-line, ustawiająca wskaźnik na nowy element(ściężkę)
    void Ustaw_elem(Sciezkal* elem){ element = elem; }

    // funkcja in-line, ustawiająca wskaźnik na nowy następny element(ściężkę)
    void Ustaw_nast(Wezel* nast){ nastepny = nast; }
};

// klasa Lista tworząca listę kierunkową, ustawiającą początek listy
// korzysta z klasy Wezel
// poczatek - wskaźnik na pierwszy węzeł w liście
class Lista {
    Wezel* poczatek;

    public:
    
    //konstruktor Listy tworzący wskaźnik na element wskazujący na NULL
    Lista(){
        poczatek = new Wezel();
        poczatek->Ustaw_elem(NULL);
        poczatek->Ustaw_nast(NULL);
    }

    // destruktor klasy Lista usuwającu wszystkie elementy z listy
    ~Lista(){
        while(1){
            if(empty() == 0){
                usun_pierwszy();
            } else {
                break;
            }
        }
    }

    // funkcja sprawdzająca czy lista jets pusta
    bool empty(){
        if(poczatek != NULL)
            return 0;
        return 1;
    }

    // funkcja zwracająca wskaźnik na pierwszy element
    Wezel* pierwszy(){
        return poczatek;
    }

    // funkcja podająca nowy węzeł na początku listy
    // nie wymaga przejścia przez całą listę
    //     ma stałą złożoność obliczeniową
    void dod_na_pocz(Sciezkal* elem){
        Wezel* zmienna = new Wezel;     // stworzenie nowego węzła
        zmienna->element = elem;        //przypisanie mu elementów
        zmienna->nastepny = pierwszy(); //ustawienie wskaźnika na nastepny element na dotychczasowy początkowy
        poczatek = zmienna;             // ustawienie węzła jako początkowy węzeł listy
    }

    // funkcja usówająca pierwszy węzeł z listy
    // nie wymaga przejścia przez całą listę
    //     ma stałą złożoność obliczeniową
    void usun_pierwszy(){
        Wezel* zmienna = poczatek;      //zapisuje wskaźnik na pierwszy element
        poczatek = zmienna->nastepny;   //ustawienie nowego początkowego węzła (dotychczasowy drógi)
        delete zmienna;                 // usónięcie węzła
    }

    // funkcja wyświetlająca na standardowym wyjściu elementów listy
    void Wyswietl_lista(){
        Wezel* zmienna = poczatek;
        while(zmienna->Element() != NULL){      // przejście przez całą listę
            cout << zmienna->Element()->Kon() << " " << zmienna->Element()->Wartosc() << ";   ";
            zmienna = zmienna->Nastepny();
        }
    }
};

// funkcja sprawdzająca czy w liście znajduje się ścieżka 
// opisana danymi paramertami
// list - wskaźnik na badaną listę
// kon - parametr potrzebny do sprawdzenia
bool Czy_istnieje(Lista& list, int kon){
    if(list.empty()){
        return 0;
    } else {
        Wezel* zmienna = list.pierwszy();
        while(zmienna->Nastepny() != NULL){     // przejście przez całą listę
            if(zmienna->Element()->Kon() == kon){   //sprawdzenie czy ścieżki są takie same
                return 1;
            }
            zmienna = zmienna->Nastepny();
        }
    }
    return 0;
}