#include <iostream>
#include <algorithm>
#include "graf.cpp"
#include "lista.cpp"
#include "kopiec.cpp"

using namespace std;

void Graf::dijkstra(int poczatek){
    vector <int> nastepniki;            //lista
    vector <Wierzcholek> wierzki;  //lista
    Wierzcholek w(0);
    int *dl = new int [Wierzcholki.size()];
    dl[poczatek] = 0;

    for (int i = 0; i < Wierzcholki.size(); ++i){   //bledne
        if(Macierz[poczatek][i] != NULL){
            dl[i] = Macierz[poczatek][i]->Wartosc();
            //Dodaj dane z macierzy do listy wierzki
            w.Zmiana(i, dl[i]);
            wierzki.push_back(w);
        } else{
            dl[i] = 100000;
            //Dodaj dane z macierzy do listy wierzki
            w.Zmiana(i, dl[i]);
            wierzki.push_back(w);
            cout << "cooc" << w.Index() << endl;
        }
    }

    //tworzymy kopiec
    Stworz(wierzki);

    while (wierzki.empty() != true){
        //przywrocenie wlasnosci kopca
        Stworz(wierzki);

        //!Pobierz pierwszy wierzcholek z kolejki wierzki (ma on najmniejsza wartosc klucza)
        w = wierzki[wierzki.size()-1];

        //!Usun go z kolejki
        Usun(wierzki);

        if(w.Index() != nieskonczonosc){
            cout << "nieskonczonosc " << w.Index() << endl;
            //!Wyznacz liste jego nastepnikow
            nastepniki = Nastepne(w.Index());

            //!Dokonaj relaksacji odleglosci od wierzcholka pierwszego do kazdego nastepnika z tej listy
            for (int i = 0; i < nastepniki.size(); i++){
                dl[nastepniki[i]] = min(dl[nastepniki[i]], dl[w.Index()] + Macierz[w.Index()][nastepniki[i]]->Wartosc());

            }
        }
    }

    for (int i = 0; i < Wierzcholki.size(); i++){
        if (dl[i] < nieskonczonosc){
            cout << "i, dl: " << i << " " << dl[i] << endl;
        } else {
            cout << "x" << endl;
        }
    }
}