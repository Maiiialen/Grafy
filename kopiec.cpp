#include <iostream>
#include <vector>
#include "kopcowanie.cpp"

using namespace std;

class Kopiec {

    public:

    void Stworz(vector <int> & tab){
        kopcowanie(tab, 0, tab.size());
    }

    void Usun_pierwszy(vector <int> & tab){
        kopcowanie(tab, 0, tab.size());
    }
};