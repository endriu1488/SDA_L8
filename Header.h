#pragma once
#include <memory>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h> 
#include <ctype.h>
#include <algorithm>

using namespace std;
struct Nod { 
	char data;
	Nod* stg, *drt;
};
void swap(Nod*a, Nod*b);
void eroare();
int nrNoduri(Nod *r);
char readchar();
char citesteNume();
Nod* citesteArbore();
Nod* creareArbore();
void inordine(Nod *r);
void postordine(Nod *r);
int adancime(Nod *r);
int nrFrunze(Nod *r);
void preordine(Nod *r);
char max(char v1, char v2);
char ValMax2(Nod *rad);
void CautaMax(Nod* p);
char ValMax(Nod* r);
void test(Nod *r);

