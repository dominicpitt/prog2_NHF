#ifndef RECEPT_H
#define RECEPT_H

#include "alapanyag.h"
#include <iostream>
#include <string>
#include <vector>
#include "memtrace.h"
using namespace std;
class Recept
{
public:
    Recept(string recept_neve = 0, vector<Alapanyag> hozzavalo = {}) : recept(recept_neve), hozzavalok(hozzavalo) {};
    void Hozzavalok_kiir();
    void Alapanyag_remove(string);
    void Alapanyag_add(vector<Alapanyag>);
    string getr() { return recept; }
    vector<Alapanyag> gethozzavalok() const { return hozzavalok; }
    ~Recept() { }
private:
    string recept;
    vector<Alapanyag> hozzavalok;
};
#endif // RECEPT_H