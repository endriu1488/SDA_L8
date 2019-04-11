#include "Header.h"

int main() {
	Nod *a;
	// A(C(D,E(F)),B(G,H))
	// 
	/*	  A
		C	B
      D  E	G H
	      F
	*/
	a = creareArbore();
	
	//cout << "preordine: "; // R S D
	//preordine(a);cout << endl;
	
	cout << "inordine: "; //S R D
	inordine(a);cout << endl; 
	
	cout << "postordine: "; // S D R
	postordine(a);cout << endl;
	
	cout << "adancime: " << adancime(a) << endl;
	
	cout << "numar noduri: " << nrNoduri(a) << endl;
	
	cout <<"numar frunze: "<<nrFrunze(a)<< endl;

	
	
	cout << "maxim: " << ValMax(a) << endl;
	cout << "maxim: " << ValMax2(a) << endl;

	test(a);

	system("pause");
	return 0;
}