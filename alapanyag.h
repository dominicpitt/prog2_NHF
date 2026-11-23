#ifndef ALAPANYAG_H
#define ALAPANYAG_H
#include <iostream>
#include "memtrace.h"
using namespace std;

class Alapanyag
{
    string alapanyag;
public:
    Alapanyag(string str="") :alapanyag(str) {}
    string getalapanyag() const { return alapanyag; }
    ~Alapanyag() { alapanyag.clear(); }
};
#endif //ALAPANYAG_H