#include <iostream>

using namespace std;

template <typename E>
class Lista;

template <typename E>
class Wezel {
    E element;
    Wezel<E>* nastepny;
    friend class Lista<E>;

    public:
    E Element(){ return element; }

    Wezel Nastepny(){ return nastepny; }

    void Ustaw_elem(E elem){ element = elem; }

    void Ustaw_nast(E nast){ nastepny = nast; }
};

template <typename E>
class Lista {
    Wezel<E>* poczatek;

    public:
    
    Lista(){
        poczatek = new Wezel<E>();
        poczatek->Ustaw_elem(NULL);
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

    bool empty() const{
        if(poczatek->nastepny != NULL)
            return 0;
        return 1;
    }

    const E& pierwszy() const{
        return poczatek;
    }

    void dod_na_pocz(const E& elem){
        Wezel<E>* zmienna = new Wezel<E>;
        zmienna->element = elem;
        zmienna->nastepny = pierwszy;
        pierwszy = zmienna;
    }

    void usun_pierwszy(){
        Wezel<E>* zmienna = pierwszy;
        pierwszy = zmienna->nastepny;
        delete zmienna;
    }
};