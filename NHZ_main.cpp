#include <iostream>
#include "tarolo.h"
#include "console.h"
#include "alapanyag.h"
#include "recept.h"
#include "gtest_lite.h"
#include "memtrace.h"
void unittest()
{
	/*TESZTEK*/
	TEST(Recept, Receptnev_lekerese) {
		Recept t("vodkaalma", { Alapanyag("vodka"), Alapanyag("almale") });
		const string expected = "vodkaalma";
		const string actual = t.getr();
		EXPECT_EQ(expected, actual) << "Recept nevenek lekerese nem mukodik" << endl;
	}END;
	TEST(Alapanyag, Alapanyagnev_lekerese) {
		Alapanyag alany = Alapanyag("almale");
		const string expected = "almale";
		const string actual = alany.getalapanyag();
		EXPECT_EQ(expected, actual) << "Alapanyag nevenek lekerese nem mukodik" << endl;
	}END;
	TEST(Recept, Recepthozzavaloi_lekerese) {
		Recept t("vodkaalma", { Alapanyag("vodka"), Alapanyag("almale") });
		const vector<Alapanyag> expected = { Alapanyag("vodka"),Alapanyag("almale") };
		const vector<Alapanyag> actual = t.gethozzavalok();
		for (size_t i = 0; i < expected.size(); i++)
		{
			const string expectedstr = expected[i].getalapanyag();
			const string actualstr = actual[i].getalapanyag();
			EXPECT_EQ(expectedstr, actualstr);
		}
	}END;
	int cv = 0;
	while (cv++<=10)
	{
		cout << endl;
	}
	Tarolo test;
	test.Add("nincs", { Alapanyag("lime") });
	Recept vodkaalma("vodkaalma", { Alapanyag("vodka"), Alapanyag("almale") });
	test.Add(vodkaalma);
	cout << "Keressuk meg a 'lime' nev alapanyagot." << endl;
	test.Keres_alapanyag("lime");
	cout << "\nKeressuk meg a 'vodkaalma' nevu receptet." << endl;
	test.Keres_recept("vodkaalma");
	Alapanyag testtorlendo = Alapanyag("lime");
	cout << "\nToroljuk a 'lime' nevu alapanyagot." << endl;
	test.Remove(testtorlendo);
	cout << "\nTorolojuk a 'vodkaalma' nevu recpetet." << endl;
	test.Remove("vodkaalma");
	test.Add("nincs", { Alapanyag("citrom") });// Nem egy konkrét recepthez akarjuk hozzáadni az alapanyagot.
	/*Eddig a sikeres dolgok, innentol receptek/alapanyagok amik nincsenek az adatbazisban*/
	Recept pinacolada("pinacolada", {Alapanyag("rum"), Alapanyag("kokusztej"), Alapanyag("ananaszle")});
	Recept whiskycola("whiskycola", { Alapanyag("whisky"), Alapanyag("cola") });
	test.Add(pinacolada);
	test.Add(whiskycola);
	cout << "\nProbaljuk meg nem letezo alapanyagokat keresni az adatbazisban." << endl;
	test.Keres_alapanyag("bacardi");
	test.Keres_alapanyag("lime");
	cout << "\nProbaljuk meg nem letezo receptet keresni az adatbazisban." << endl;
	test.Keres_recept("mojito");
	Alapanyag hibastorol = Alapanyag("sprite");
	cout << "\nProbaljuk meg nem letezo alapanyagokat torolni az adatbazisban." << endl;
	test.Remove(hibastorol);
	test.Remove("kakao");
	test.Alapanyag_listaz();
	test.Receptek_listaz();
}
int main()
{
#ifndef CPORTA
	Tarolo t;
	t.Fajlolvas();		//receptek es alapanyagok beolvasasa
	cout << "\nFolytatashoz nyomj entert...";
	cin.ignore();
	clear_screen();
	valaszfeldolgozas(t);
#else
	unittest();
#endif
	return 0;
}