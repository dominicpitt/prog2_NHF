#include <iostream>
#include <fstream>
#include <sstream>
#include "tarolo.h"
#include "recept.h"
#include "alapanyag.h"
#include "memtrace.h"
void Tarolo::Add(Recept& uj)
{
	Receptek.push_back(uj);
	vector<Alapanyag> temp = uj.gethozzavalok();
	for (size_t i = 0; i < temp.size(); i++)
	{
		bool szerepel = false;
		for (size_t j = 0; j < Alapanyagok.size(); j++)
		{
			if (temp[i].getalapanyag() == Alapanyagok[j].getalapanyag())
			{
				szerepel = true;
				break;
			}
		}
		if (!szerepel)
		{
			Alapanyagok.push_back(temp[i]);
		}
	}
}
void Tarolo::Add(string mihez, vector<Alapanyag> mit)
{
	bool letezik = false;
	for (size_t i = 0; i < mit.size(); i++)
	{
		letezik = false;
		for (size_t j = 0; j < Alapanyagok.size(); j++)
		{
			if (mit[i].getalapanyag() == Alapanyagok[j].getalapanyag())
			{
				letezik = true;
				break;
			}
		}
		if (!letezik)
		{
			Alapanyagok.push_back(mit[i]);
		}
	}
	if (mihez != "nincs")
	{
		for (size_t i = 0; i < Receptek.size(); i++)
		{
			if (Receptek[i].getr() == mihez)
			{
				letezik = true;
				Receptek[i].Alapanyag_add(mit);
			}
		}
		if (!letezik)
		{
			cout << "Nincs ilyen nevu recept az adatbazisban." << endl;
			return;
		}
	}
}
void Tarolo::Remove(string torlendo)
{
	if (Receptek.empty())
	{
		cout << "Meg nincs elmentve recept az adatbazisban." << endl;
		return;
	}
	bool siker = false;
	for (size_t i = 0; i < Receptek.size(); i++)
	{

		if (Receptek[i].getr() == torlendo) {
			siker = true;
			Receptek.erase(Receptek.begin() + i);
		}
	}
	if (siker == false)
	{
		cout << "Nem volt ilyen nevu recept '" << torlendo << "' az adatbazisban, nem volt mit torolni.\n" << endl;;
	}
	else if (siker)
	{
		cout << "Sikeresen toroltuk a '" << torlendo << "' receptet az adatbazisbol.\n" << endl;
	}
}
void Tarolo::Remove(Alapanyag& torlendo)
{
	if (Alapanyagok.empty())
	{
		cout << "Meg nincs elmentve alapanyag az adatbazisban." << endl;
		return;
	}
	bool siker = false;
	for (size_t i = 0; i < Alapanyagok.size(); i++)
	{
		if (Alapanyagok[i].getalapanyag() == torlendo.getalapanyag()) {
			Alapanyagok.erase(Alapanyagok.begin() + i);
			siker = true;
		}
	}

	for (size_t j = 0; j < Receptek.size(); j++)
	{
		Receptek[j].Alapanyag_remove(torlendo.getalapanyag());
	}
	if (siker == false) { cout << "Nem volt ilyen alapanyag '" << torlendo.getalapanyag() << "' az adatbazisban, nem volt mit torolni.\n" << endl; return; }
	cout << "Sikeresen toroltuk '" << torlendo.getalapanyag() << "' alapanyagot.\n" << endl;
}
void Tarolo::Receptek_listaz()
{
	if (Receptek.empty())
	{
		cout << "Meg nincs elmentve recept az adatbazisban." << endl;
		return;
	}
	cout << "Receptek:\n";
	for (size_t i = 0; i < Receptek.size(); i++)
	{
		cout << "\t" << Receptek[i].getr() << ": ";
		Receptek[i].Hozzavalok_kiir();
		cout << endl;
	}
}
void Tarolo::Alapanyag_listaz()
{
	if (Alapanyagok.empty())
	{
		cout << "Meg nincs elmentve alapanyag az adatbazisban." << endl;
		return;
	}
	cout << "Osszes alapanyag:\n\t";
	for (size_t i = 0; i < Alapanyagok.size(); i++)
	{
		if (i == Alapanyagok.size() - 1)
		{
			cout << Alapanyagok[i].getalapanyag();
			cout << endl;
			return;
		}
		cout << Alapanyagok[i].getalapanyag() << ", ";
	}
}
void Tarolo::Keres_alapanyag(string keresendo)
{
	if (Alapanyagok.empty())
	{
		cout << "Meg nincs elmentve alapanyag az adatbazisban." << endl;
		return;
	}
	else
	{
		bool bennevan = false;
		int cnt = 0;
		for (size_t i = 0; i < Receptek.size(); i++)
		{
			vector<Alapanyag> temp = Receptek[i].gethozzavalok();
			for (size_t j = 0; j < temp.size(); j++)
			{

				if (temp[j].getalapanyag() == keresendo)
				{
					cnt++;
					if (cnt == 1) { cout << "A keresett alapanyag '" << keresendo << "' benne van az adatbazisban, az osszes recept amiben szerepel:" << endl; bennevan = true; }
					cout << '\t' << Receptek[i].getr() << ": ";
					Receptek[i].Hozzavalok_kiir();
					cout << endl;
				}
			}
		}
		
		if (cnt==0)
		{
			for (size_t i = 0; i < Alapanyagok.size(); i++)
			{
				if (Alapanyagok[i].getalapanyag() == keresendo)
				{
					cout << "A keresett alapanyag '" << keresendo << "' benne van az adatbazisban, de nincs recepthez kotve." << endl;
					bennevan = true;
				}
			}
		}
		if (!bennevan)
		{
			cout << "Nincs ilyen alapanyag az adatbazisban." << endl;
		}
	}
}
void Tarolo::Keres_recept(string keresendo)
{
	if (Receptek.empty())
	{
		cout << "Meg nincs elmentve Recept az adatbazisban." << endl;
		return;
	}
	int cnt = 0;
	for (size_t i = 0; i < Receptek.size(); i++)
	{
		if (Receptek[i].getr() == keresendo)
		{
			cnt++;
			if (cnt == 1)
			{
				cout << "A keresett recept: '" << Receptek[i].getr() << "', benne van az adatbazisban, hozzavaloi:\n\t";
			}
			Receptek[i].Hozzavalok_kiir();
		}
	}
	if (cnt == 0)
	{
		cout << "Nincs ilyen nevu recept az adatbazisban." << endl;
	}
	cout << endl;
}
void Tarolo::Fajlkiir()
{
	ofstream file("receptek.txt");
	if (file.is_open()) {
		for (size_t i = 0; i < Receptek.size(); i++) {
			file << Receptek[i].getr() << "\t";
			vector<Alapanyag> seged = Receptek[i].gethozzavalok();
			for (size_t j = 0; j < seged.size(); j++)
			{
				file << seged[j].getalapanyag() << "|";
			}
			file << "\n";
		}
		file.close();
		cout << "A receptek sikeresen ki lettek irva a \"receptek.txt\" fajlba." << endl;
	}
	else {
		cout << "Hiba tortent a \"receptek.txt\" fajl megnyitasa soran." << endl;
	}
	ofstream file2("alapanyagok.txt");
	if (file2.is_open()) {
		for (size_t j = 0; j < Alapanyagok.size(); j++) {
			file2 << Alapanyagok[j].getalapanyag() << "|";
		}
		file2.close();
		cout << "Az alapanyagok sikeresen ki lettek irva az \"alapanyagok.txt\" fajlba." << endl;
	}
	else {
		cout << "Hiba tortent a \"alapanyagok.txt\" fajl megnyitasa soran." << endl;
	}
}
void Tarolo::Fajlolvas()
{
	ifstream file("receptek.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			stringstream ss(line);
			string seged;
			getline(ss, seged, '\t');
			Recept recept(seged);
			vector<Alapanyag> hozzavalokAdat;
			while (getline(ss, seged, '|')) {
				hozzavalokAdat.push_back(seged);
			}
			recept.Alapanyag_add(hozzavalokAdat);
			Receptek.push_back(recept);
		}
		file.close();
		cout << "A receptek sikeresen be lettek olvasva a \"receptek.txt\" fajlbol." << endl;
	}
	else {
		cout << "Hiba tortent a \"receptek.txt\" fejl megnyitasa soren vagy meg ures az adatbazis." << endl;
	}
	ifstream file2("alapanyagok.txt");
	if (file2.is_open()) {
		string line;
		while (getline(file2, line, '|')) {

			Alapanyagok.push_back(line);

		}
		file2.close();
		cout << "Az Alapanyagok sikeresen be lettek olvasva a \"alapanyagok.txt\" fajlbol." << endl;
	}
	else {
		cout << "Hiba tortent a \"alapanyagok.txt\" fajl megnyitasa soran vagy meg ures az adatbazis." << endl;
	}
}