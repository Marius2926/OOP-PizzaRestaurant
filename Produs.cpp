#include "Produs.h"


Produs::Produs(std::string d,int c,double p,int times) : denumire(d)
{	
	this->cantitate = c;
	this->pret = p;
	this->times = 1;
}


Produs::~Produs(){}


Produs::Produs(const Produs& B)
{
		this->denumire = B.denumire;
		this->cantitate = B.cantitate;
		this->pret = B.pret;
		this->times = B.times;
}

Produs& Produs:: operator=(const Produs& B)
{
	if (&(*this) != &B)
	{
		denumire = B.denumire;
		cantitate = B.cantitate;
		pret = B.pret;
		times = B.times;
	}
	return *this;
}

std::istream& operator>>(std::istream &in, Produs &A)
{
	in >> A.denumire >> A.cantitate >> A.pret;
	return in;
}

std::ostream& operator<<(std::ostream &out, Produs &A)
{
	out << A.denumire << " " << A.cantitate << "g " << A.pret << "lei/100g\n";
	return out;
}

double Produs::Pret()
{
	double aux = cantitate / 100;
	return aux * times*pret;
}