#pragma once
#include "Produs.h"
class ListaProduse
{	
	static std::vector<Produs> GamaProduse;
	static int GamaNumar;
	int numar;
	std::vector<Produs> produse;
public:
	static void init(std::string);
	ListaProduse();
	ListaProduse(int,std::vector<Produs>&);
	~ListaProduse();
	ListaProduse(const ListaProduse&);
	ListaProduse& operator=(const ListaProduse&);
	friend std::istream& operator>>(std::istream&, ListaProduse&);
	friend std::ostream& operator<<(std::ostream&, ListaProduse&);
	friend class Pizza;
	virtual void citire(std::istream&);
	virtual void afisare(std::ostream&);
	bool addProdus(std::string);
};

