#pragma once
#include "Calcul.h"
#include "ListaProduse.h"
const double AD = 5;

class Pizza : public Calcul
{	
	static double adaos;
	ListaProduse ingrediente;
	bool online; //true daca e comanda online 
	int distance; //daca e comandata online
public:
	double getPret();
	Pizza();
	Pizza(ListaProduse&,bool,int);
	~Pizza();
	Pizza(const Pizza&);
	Pizza& operator=(const Pizza&);
	friend std::ostream& operator<<(std::ostream&, Pizza&);
};

