#include <iostream>
#include "recept.h"
#include "alapanyag.h"
#include "memtrace.h"
void Recept::Hozzavalok_kiir()
{
	for (size_t i = 0; i < hozzavalok.size(); ++i)
	{
		if (i == hozzavalok.size() - 1)
		{
			cout << hozzavalok[i].getalapanyag();
			return;
		}
		cout << hozzavalok[i].getalapanyag() << ", ";
	}
}
void Recept::Alapanyag_remove(string torlendo)
{
	for (size_t i = 0; i < hozzavalok.size(); i++)
	{
		if (hozzavalok[i].getalapanyag() == torlendo) {
			hozzavalok.erase(hozzavalok.begin() + i);
		}
	}
}
void Recept::Alapanyag_add(vector<Alapanyag> hozzaadando)
{
	for (size_t i = 0; i < hozzaadando.size(); i++)
	{
		hozzavalok.push_back(hozzaadando[i]);
	}
}