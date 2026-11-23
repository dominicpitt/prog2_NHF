#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <fstream>
#include "recept.h"
#include "tarolo.h"
#include "memtrace.h"
using namespace std;

void info();

void Menu();

void valaszfeldolgozas(Tarolo t);
void clear_screen();
#endif // CONSOLE_H