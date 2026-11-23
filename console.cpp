#include <iostream>
#include "console.h"
#include "memtrace.h"
#include "recept.h"
#include "alapanyag.h"
using namespace std;
void info()
{
	clear_screen();
	ifstream file("info.txt");
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
	cout << endl;
	cin.ignore();
	return;
}
void Menu() {
	cout << "=========================" << endl;
	cout << " ITALRECEPTEK MENU" << endl;
	cout << "=========================" << endl;
	cout << " 0. Informacio" << endl;
	cout << " 1. Uj alapanyag felvetele" << endl;//Uj alapanyag
	cout << " 2. Uj recept felvetele" << endl; //Uj recept
	cout << " 3. Recept alapanyagai" << endl; //Recept keres
	cout << " 4. Alapanyag Keres" << endl; //Alapanyag keres
	cout << " 5. Receptek kilistazasa" << endl; //Alapanyag keres
	cout << " 6. Alapanyagok kilistazasa" << endl;//Alapanyag_listaz
	cout << " 7. Recept torlese" << endl;//Recept torol
	cout << " 8. Alapanyag torlese" << endl;//Alapanyag torol
	cout << " 9. Kilepes" << endl;
	cout << "=========================" << endl;
	cout << "Valasszon egy lehetoseget (1-9): ";
}
void valaszfeldolgozas(Tarolo t) {
	bool exit = true;
	string receptnev; vector<Alapanyag> alapanyagnevek; string seged; Alapanyag alapanyag;
	Recept r(receptnev, alapanyagnevek);
	while (exit)
	{

		Menu();
		int valasz;
		while (!(cin >> valasz)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Csak szamot adhatsz meg! Probald ujra: ";
		}
		bool vege = true;
		switch (valasz) {
		case 0:	//info
			info();
			cin.ignore();
			clear_screen();
			break;
		case 1:		//uj alapanyag
			clear_screen();
			cout << "Adja meg a recept nevet, amihez kivan hozzaadni, ha csak az adatbazisba kivanja menteni akkor adja meg a ('nincs') szot: " << endl;
			cin.clear();
			cin >> receptnev;
			cout << "Adja az alapanyagot vagy alapanyagokat amiket kivan berakni az adatbazisba, egyesevel enter lenyomasaval adja meg(ha vegzet 'done' szot adja meg): " << endl;
			while (vege) {
				cin >> seged;
				if (seged == "done") {
					vege = false;
					break;
				}
				alapanyagnevek.push_back(seged);
			}
			t.Add(receptnev, alapanyagnevek);
			alapanyagnevek.clear();
			cout << "\nFolytatashoz nyomj entert...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore();
			clear_screen();
			break;
		case 2:		//uj recept
			clear_screen();
			cout << "Adja meg az uj recept nevet: ";
			cin >> receptnev;
			cout << "\nAdja az alapanyagot vagy alapanyagokat amiket kivan berakni az adatbazisba, egyesevel enter lenyomasaval adja meg(ha vegzet 'done' szot adja meg): " << endl;
			while (vege) {
				cin >> seged;
				if (seged == "done") {
					vege = false;
					Recept r(receptnev, alapanyagnevek);
					t.Add(r);
				}
				alapanyagnevek.push_back(seged);
			}
			alapanyagnevek.clear();
			cout << "\nFolytatashoz nyomj entert...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore();
			clear_screen();
			break;
		case 3:		//recept keres
			clear_screen();
			cout << "Adja meg a recept nevet, amit kivan megkeresni: " << endl;
			cin >> receptnev;
			t.Keres_recept(receptnev);
			cout << "\nFolytatashoz nyomj entert...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore();
			clear_screen();
			break;
		case 4:		//alapanyag keres
			clear_screen();
			cout << "Adja meg az alapanyag nevet, amit kivan megkeresni: " << endl;
			cin >> seged;
			t.Keres_alapanyag(seged);
			cout << "\nFolytatashoz nyomj entert...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore();
			clear_screen();
			break;
		case 5:		//recetpek listaz
			clear_screen();
			t.Receptek_listaz();
			cout << "\nFolytatashoz nyomj entert...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore();
			clear_screen();
			break;
		case 6:		//alapanyagokat listaz
			clear_screen();
			t.Alapanyag_listaz();
			cout << "\nFolytatashoz nyomj entert...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore();
			clear_screen();
			break;
		case 7:		//recept torles
			clear_screen();
			cout << "Adja meg a recept nevet, amit kivan torolni az adatbazisbol: " << endl;
			cin >> receptnev;
			t.Remove(receptnev);
			cout << "\nFolytatashoz nyomj entert...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore();
			clear_screen();
			break;
		case 8:		//alapanyag torles
			clear_screen();
			cout << "Adja meg az alapanyag nevet, amit kivan torolni az adatbazibol: " << endl;
			cin >> seged;
			alapanyag = seged;
			t.Remove(alapanyag);
			cout << "\nFolytatashoz nyomj entert...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore();
			clear_screen();
			break;
		case 9:		//kilepes es adatbazis fajba mentese
			clear_screen();
			t.Fajlkiir();
			exit = false;
			cout << "\n>>>Kilepes!<<<" << endl;
			break;
		default:
			cout << "Ervenytelen valasztas. Kerem, probalja ujra." << endl;
			break;
		}
	}
}
void clear_screen()
{
#ifdef WINDOWS
	system("cls");
#else
	system("clear");
#endif
}