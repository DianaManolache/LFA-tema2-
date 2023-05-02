#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("../citire.in");

int nr, stare = 0;
char cuv[1001];
bool stfin[1001] = {false};
bool gasit_cuvant = false;

struct gramatica{
    int start, stop;
    char lit;
}v[1001];

void citire()
{
    fin >> nr;

    for(int i = 0; i < nr; i++)
    {
        fin >> v[i].start >> v[i].lit >> v[i].stop;

    }

    fin >> cuv;
    for (int i = 0; i < nr; i++) {
        if (v[i].stop == -1 && v[i].lit == '-') {
            stfin[v[i].start] = true;
        }
    }
}

void backtracking(int poz, int stare_curenta, int parametru)
{
    if (poz == strlen(cuv)) {
        if (stfin[stare_curenta] || v[parametru].stop == -1) {
            gasit_cuvant = true;
        }
        return;
    }

    for (int i = 0; i < nr; i++) {
        if (v[i].start == stare_curenta && v[i].lit == cuv[poz]) {
            backtracking(poz + 1, v[i].stop,i);
        }
    }
}

int main() {

    citire();

    backtracking(0, 0, 0);

    if(gasit_cuvant == true || (cuv[0] =='-' && stfin[0] == true))
        cout << "DA";

    else
        cout <<"NU";

    return 0;
}