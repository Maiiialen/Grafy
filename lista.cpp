#include <iostream>
#include "Sciezkal.cpp"

using namespace std;

class Lista;

class Wezel {
    Sciezkal* element;
    Wezel* nastepny;
    friend class Lista;

    public:
    Sciezkal* Element(){ return element; }

    Wezel* Nastepny(){ return nastepny; }

    void Ustaw_elem(Sciezkal* elem){ element = elem; }

    void Ustaw_nast(Wezel* nast){ nastepny = nast; }
};

class Lista {
    Wezel* poczatek;

    public:
    
    Lista(){
        poczatek = new Wezel();
        poczatek->Ustaw_elem(NULL);
        poczatek->Ustaw_nast(NULL);
    }

    ~Lista(){
        while(1){
            if(empty() == 0){
                usun_pierwszy();
            } else {
                break;
            }
        }
    }

    bool empty(){
        if(poczatek != NULL)
            return 0;
        return 1;
    }

    Wezel* pierwszy(){
        return poczatek;
    }

    void dod_na_pocz(Sciezkal* elem){
        Wezel* zmienna = new Wezel;
        zmienna->element = elem;
        zmienna->nastepny = pierwszy();
        poczatek = zmienna;
    }

    void usun_pierwszy(){
        Wezel* zmienna = poczatek;
        poczatek = zmienna->nastepny;
        delete zmienna;
    }

    void Wyswietl_lista(){
        Wezel* zmienna = poczatek;
        while(zmienna->Element() != NULL){
            cout << zmienna->Element()->Kon() << " " << zmienna->Element()->Wartosc() << ";   ";
            zmienna = zmienna->Nastepny();
        }
    }
};

bool Czy_istnieje(Lista& list, int kon){
    if(list.empty()){
        return 0;
    } else {
        Wezel* zmienna = list.pierwszy();
        while(zmienna->Nastepny() != NULL){
            if(zmienna->Element()->Kon() == kon){
                return 1;
            }
            zmienna = zmienna->Nastepny();
        }
    }
    return 0;
}