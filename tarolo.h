#ifndef TAROLO_H
#define TAROLO_H

#include <iostream>
#include <string>
#include "alapanyag.h"
#include <vector>
#include "recept.h"
#include "memtrace.h"
using namespace std;
class Tarolo
{
public:
	Tarolo() {}
	void Add(Recept&);
	void Add(string, vector<Alapanyag>);
	void Remove(string);
	void Remove(Alapanyag&);
	void Receptek_listaz();
	void Alapanyag_listaz();
	void Keres_alapanyag(string);
	void Keres_recept(string);
	void Fajlkiir();
	void Fajlolvas();
	vector<Alapanyag> getAlapanyagok() { return Alapanyagok; }
	vector<Recept> getReceptek() { return Receptek; }
	~Tarolo() {}

private:
	vector<Recept> Receptek;
	vector<Alapanyag> Alapanyagok;
};
#endif // TAROLO_H