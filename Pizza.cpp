#include "Pizza.h"
double Pizza::adaos = AD;
Pizza::Pizza(){}

Pizza::Pizza(ListaProduse& p, bool tip,int dist) : ingrediente(p)
{
	online = tip;
	distance = dist;
}


Pizza::~Pizza(){}

Pizza::Pizza(const Pizza &B) : ingrediente(B.ingrediente)
{
	online = B.online;
	distance = B.distance;
}

Pizza & Pizza::operator=(const Pizza &B)
{
	if (&(*this) != &B)
	{
		online = B.online;
		ingrediente = B.ingrediente;
		distance = B.distance;
	}
	return *this;
}

double Pizza::getPret()
{	
	double S = adaos,aux;
	for (int i = 0; i < ingrediente.numar; i++)
	{
		S+=ingrediente.produse[i].Pret();
	}
	int dist = distance / 10;
	while (dist)
	{
		S += S / 20;
		dist--;
	}
	return S;
	return 0;
}

std::ostream& operator<<(std::ostream& out, Pizza& B)
{	
	out << B.ingrediente;
	out << "Pretul este de: "<< B.getPret()<<"\n\n\n";
	return out;
}