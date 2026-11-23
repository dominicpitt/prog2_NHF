#include <iostream>
#include "tarolo.h"
#include "console.h"
#include "memtrace.h"

int main()
{
	/*TESZTEK*/
	Tarolo proba;
	Recept vodkaalma("vodkaalma", { Alapanyag("vodka"), Alapanyag("almale") });
	proba.Add(vodkaalma);
	proba.Receptek_listaz();
	Recept vodkanarancs("vodkanarancs", { Alapanyag("vodka"), Alapanyag("fanta") });
	proba.Add(vodkanarancs);
	proba.Add("vodkanarancs", { Alapanyag("lime") });
	proba.Receptek_listaz();
	proba.Alapanyag_listaz();
	proba.Keres_alapanyag("lime");
	proba.Keres_recept("vodkaalma");
	Alapanyag probatorlendo = Alapanyag("lime");
	proba.Remove(probatorlendo);
	proba.Remove("vodkaalma");
	proba.Add("nincs", {Alapanyag("citrom")});// Nem egy konkrét recepthez akarjuk hozzáadni az alapanyagot.
	proba.Receptek_listaz();
	proba.Alapanyag_listaz();
	/*Eddig a sikeres dolgok, innentol receptek/alapanyagok amik nincsenek az adatbazisban*/
	Recept pinacolada("pinacolada", { Alapanyag("rum"), Alapanyag("kokusztej"), Alapanyag("ananaszle") });
	Recept whiskycola("whiskycola", { Alapanyag("whisky"), Alapanyag("cola") });
	proba.Add(pinacolada);
	proba.Add(whiskycola);
	proba.Receptek_listaz();
	proba.Alapanyag_listaz();
	proba.Keres_alapanyag("bacardi");
	proba.Keres_alapanyag("citrom");
	proba.Keres_recept("mojito");
	Alapanyag hibastorol = Alapanyag("sprite");
	proba.Remove(hibastorol);
	proba.Remove("kakao");
	system("cls");
}
