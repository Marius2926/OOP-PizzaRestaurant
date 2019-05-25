#pragma once
#include "ListaProduse.h"
#include "Pizza.h"

template <class T> class Meniu
{	
	T index;
	std::vector<Pizza*> vanzari;
	std::vector<Pizza*> vegetariana;
public:
	Meniu()
	{
		index = 0;
	}
	~Meniu() {}
	void makePizza(std::string tip)
	{	
		index++;
		ListaProduse *p=new ListaProduse;
		Pizza* np;
		if (tip == "pui")
		{
			(*p).addProdus("pui");
			(*p).addProdus("blat");
			(*p).addProdus("sos");
			(*p).addProdus("cascaval");
			np = new Pizza((*p), true,42);
			vanzari.push_back(np);
		}
		if (tip == "specialitate")
		{
			(*p).addProdus("pui");
			(*p).addProdus("blat");
			(*p).addProdus("sos");
			(*p).addProdus("vita");
			(*p).addProdus("cascaval");
			(*p).addProdus("gorgonzola");
			(*p).addProdus("parmezan");
			np = new Pizza((*p), true,25);
			vanzari.push_back(np);
		}
		if (tip == "hawai")
		{
			(*p).addProdus("pui");
			(*p).addProdus("blat");
			(*p).addProdus("sos");
			(*p).addProdus("ananas");
			np = new Pizza((*p), true,24);
			vanzari.push_back(np);
		}
		if (tip == "vegetariana")
		{
			(*p).addProdus("ardei");
			(*p).addProdus("blat");
			(*p).addProdus("sos");
			(*p).addProdus("rosii");
			np = new Pizza((*p), true,13);
			vegetariana.push_back(np);
		}
	}
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, Meniu<T> M)
	{	
		out << "Pizzele care nu sunt vegetariene:\n";
		for(int i=0;i<M.vanzari.size();i++)
		{
			out << *M.vanzari[i];
		}
		out << "Pizzele care sunt vegetariene:\n";
		for (int i = 0; i < M.vegetariana.size(); i++)
		{
			out << *M.vegetariana[i];
		}
		return out;
	}
};



template <> class Meniu<int>
{
	int index;
	std::vector<Pizza*> vanzari;
	std::vector<Pizza*> vegetariana;
public:
	Meniu()
	{
		index = 0;
	}
	~Meniu() {}
	void makePizza(std::string tip)
	{	
		try {
			index++;
			if (index < 0)
				throw("Index negativ la clasa meniu. Nu s-a creat pizza.");
		}
		catch (std::string ex)
		{
			std::cout << "\n" << ex << "\n";
			throw;
		}
		ListaProduse *p = new ListaProduse;
		Pizza* np;
		if (tip == "pui")
		{
			(*p).addProdus("pui");
			(*p).addProdus("blat");
			(*p).addProdus("sos");
			(*p).addProdus("cascaval");
			np = new Pizza((*p), true,15);
			vanzari.push_back(np);
		}
		if (tip == "specialitate")
		{
			(*p).addProdus("pui");
			(*p).addProdus("blat");
			(*p).addProdus("sos");
			(*p).addProdus("vita");
			(*p).addProdus("cascaval");
			(*p).addProdus("gorgonzola");
			(*p).addProdus("parmezan");
			np = new Pizza((*p), true,6);
			vanzari.push_back(np);
		}
		if (tip == "hawai")
		{
			(*p).addProdus("pui");
			(*p).addProdus("blat");
			(*p).addProdus("sos");
			(*p).addProdus("ananas");
			np = new Pizza((*p), true,9);
			vanzari.push_back(np);
		}
		if (tip == "vegetariana")
		{
			(*p).addProdus("ardei");
			(*p).addProdus("blat");
			(*p).addProdus("sos");
			(*p).addProdus("rosii");
			np = new Pizza((*p), true,23);
			vegetariana.push_back(np);
		}
	}
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, Meniu<T> M)
	{
		out << "Pizzele care nu sunt vegetariene:\n";
		for (int i = 0; i < M.vanzari.size(); i++)
		{
			out << *M.vanzari[i];
		}
		out << "Pizzele care sunt vegetariene:\n";
		for (int i = 0; i < M.vegetariana.size(); i++)
		{
			out << *M.vegetariana[i];
		}
		return out;
	}
};