#include "Header.h"

char car;

void eroare() {
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	_getch();
	exit(1);
}

char readchar() {
	char c;
	do  c = getchar();
	while (c == ' ');
	return c;
}

char citesteNume() {
	char c;
	if (!isalpha(car)) eroare();
	c = car;
	car = readchar();
	return c;
}

Nod* citesteArbore() {
	Nod* rad;
	if (car == '-')
	{
		rad = 0;        
		car = readchar();
	} else {
		rad = (Nod*)malloc(sizeof(Nod));
		rad->data = citesteNume();
		if (car != '(') {
			rad->stg = 0; 
			rad->drt = 0;
		} else { car = readchar();
		rad->stg = citesteArbore();
		if (car != ',') 
			rad->drt = 0; 
		else { car = readchar();
		rad->drt = citesteArbore();
		}         if (car != ')')
			eroare(); 
		car = readchar(); 
		}
	}     
	return rad;
}

Nod* creareArbore() {
	printf("\nIntroduceti arborele:");
	car = readchar();
	return citesteArbore();
}

void inordine(Nod *r)
{
	if (r != 0)
	{
		inordine(r->stg);
		cout << r->data << " ";
		inordine(r->drt);
	}
}
void preordine(Nod *r)
{
	if (r != 0)
	{	
		cout << r->data << " ";
		inordine(r->stg);
		inordine(r->drt);
		
	}
}

void postordine(Nod *r)
{
	if (r != 0)
	{
		inordine(r->stg);
		inordine(r->drt);
		cout << r->data << " ";
	}
}

int adancime(Nod *r)
{
	if (r != 0)
	{
		return 1 + max(adancime(r->stg), adancime(r->drt));
	}
	else
		return 0;
}


int nrFrunze(Nod *r)
{
	if (r == 0)return 0;

	if ((r->stg == 0) && (r->drt == 0))
	{
		return 1;
	}
	else
	{
		return (nrFrunze(r->stg) + nrFrunze(r->drt));
		return 0;
	}

}

char max(char v1, char v2) {
	if (v1 >= v2) return v1; 
	else return v2;
}

char ValMax2(Nod *rad) {
	char vmax;

	vmax = rad->data;           
	if (rad->stg != NULL) 
		vmax = max(vmax, ValMax2(rad->stg)); 
	if (rad->drt != NULL) 
		vmax = max(vmax, ValMax2(rad->drt));
	return vmax;
}

char Max;
// max este variabila globala
void CautaMax(Nod* p)
{
	         if (p!=NULL){
				 if (p->data>Max)
					 Max=p->data;
				 CautaMax(p->stg); 
				 CautaMax(p->drt); 
			 }   
} 

char ValMax(Nod* r) {
	Max = 0;
	CautaMax(r); 
	return Max;
}

void swap(Nod*a, Nod*b) {
	Nod *temp;
	temp = a;
	a = b;
	b = temp;
}

void test(Nod *r) {
	preordine(r);cout << endl;
	swap(r->drt, r->stg);
	preordine(r);cout << endl;
}

int nrNoduri(Nod *r) {
	if (r != 0)
		return 1 + nrNoduri(r->stg) + nrNoduri(r->drt);
	return 0;
}