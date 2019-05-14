#include <iostream>
#include <algorithm>
#include <climits>
#include "graflista.cpp"

using namespace std;

int Grafl::minodl(int dl[], bool odwiedzone[]){
    int male = INT_MAX, indx;   //ustawia odleglosc na nieskonczonosc i tworzy zmienna na indeks
    for(int i = 0; i < Wierz_size(); ++i){      //przechodzi przez wszystkie wierzcholki
        if(odwiedzone[i] == 0 && dl[i] <= male){    //jesli nie jest uwzgledniony i odleglosc mniejsza od aktualnie najmniejszej
            male = dl[i];   //to najmniejsza odleglosc to wlasnie ta
            indx = i;   //i zapisuje jego indeks
        }
    }
    return indx;    //zwraca indeks najblizszego nieuwzglednionego
}






void Grafl::dijkstra(int pocz){
    int poczatek = pocz, zmienna;
    bool *odwiedzone = new bool [Wierz_size()]; //tworzy tablice okreslajaca ktore wierzcholki sa w drzewie najkrtoszej sciezki
    int *dl = new int [Wierz_size()];   //tworzy tablice przechowujaca najmniejsze odleglosci
    Wezel* wezel_tymczasowy = new Wezel;;
    //ustawia poczatkowo wartosci
    for (int i = 0; i < Wierz_size(); ++i){ //dla wszystkich wierzcholkow
        dl[i] = INT_MAX;    //odleglosc od zrodla to nieskonczonosc
        odwiedzone[i] = 0;  //nie sa uwzglednione w drzewie najkrotszej sciezki
    }
    dl[pocz] = 0;   //odleglosc od zrodla to 0 (wierzcholek zostanie wybrany pierwszy)

    //szukanie tras i odleglosci
    for(int i = 0; i < Wierz_size(); ++i){
        zmienna = minodl(dl, odwiedzone);   //znajdz najblizszy zrodla, nie uwzgledniony wierzcholek
        odwiedzone[zmienna] = 1;    //odznacz jako uwzgledniony
        wezel_tymczasowy = Tablica[zmienna].pierwszy();
        while(wezel_tymczasowy->Element() != NULL){ //dla wszystkich sasiadujacych wierzcholkow
            //jesli nie jest uwzgledniony i polaczenie ma wage i odleglosc do wybranego to nie nieskonczonosc i odleglosc do wybranego + odleglosc do sasiadujacego < odleglosc bezposrednia
            if(!odwiedzone[wezel_tymczasowy->Element()->Kon()] && wezel_tymczasowy->Element()->Wartosc() && dl[zmienna] != INT_MAX && dl[zmienna] + wezel_tymczasowy->Element()->Wartosc() < dl[wezel_tymczasowy->Element()->Kon()]){
                dl[wezel_tymczasowy->Element()->Kon()] = dl[zmienna] + wezel_tymczasowy->Element()->Wartosc();  //to odleglosc do wierzcholka = odleglosc do wybrango + odleglosc do sasiadujacego
            }
            wezel_tymczasowy = wezel_tymczasowy->Nastepny();
        }
        
    }
    /*
    for (int i = 0; i < Wierzcholki.size(); ++i){
        cout << "i, dl: " << i << " " << dl[i] << endl;
    }
    */
}






void Grafl::dijkstra(int pocz, int kon){
    int poczatek = pocz, zmienna;
    bool *odwiedzone = new bool [Wierz_size()];
    int *dl = new int [Wierz_size()];
    Wezel* wezel_tymczasowy = new Wezel;;

    for (int i = 0; i < Wierz_size(); ++i){
        dl[i] = INT_MAX;
        odwiedzone[i] = 0;
    }
    dl[pocz] = 0;


    for(int i = 0; i < Wierz_size(); ++i){
        zmienna = minodl(dl, odwiedzone);
        odwiedzone[zmienna] = 1;
        wezel_tymczasowy = Tablica[zmienna].pierwszy();
        while(wezel_tymczasowy->Element() != NULL){
            if(!odwiedzone[wezel_tymczasowy->Element()->Kon()] && wezel_tymczasowy->Element()->Wartosc() && dl[zmienna] != INT_MAX && dl[zmienna] + wezel_tymczasowy->Element()->Wartosc() < dl[wezel_tymczasowy->Element()->Kon()]){
                dl[wezel_tymczasowy->Element()->Kon()] = dl[zmienna] + wezel_tymczasowy->Element()->Wartosc();
            }
            if(odwiedzone[wezel_tymczasowy->Element()->Kon()] == 1){    //jesli znaleziono trase do konkretnie szukanego wierzcholka
                break;  //to skoncz
            }
            wezel_tymczasowy = wezel_tymczasowy->Nastepny();
        }
        
    }

    //cout << "i, dl: " << kon << " " << dl[kon] << endl;
}