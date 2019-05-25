#include "ListaProduse.h"
std::vector<Produs> ListaProduse::GamaProduse;
int ListaProduse::GamaNumar;

ListaProduse::ListaProduse()
{	
	numar = 0;
}

ListaProduse::ListaProduse(int nr,std::vector<Produs>& v)
{	
	numar = nr;
	produse = v;
}


ListaProduse::~ListaProduse()
{}

ListaProduse::ListaProduse(const ListaProduse &B)
{
	numar = B.numar;
	produse = B.produse;
}

ListaProduse & ListaProduse::operator=(const ListaProduse &B)
{
	if (&(*this) != &B)
	{
		numar = B.numar;
		produse = B.produse;
	}
	return *this;
}

void ListaProduse::citire(std::istream &in)
{
	in >> numar;
	int i;
	std::string *p = new std::string;
	for (i = 0; i < numar; i++)
	{
		in >> *p;
		try
		{
			if (!addProdus(*p))
				throw "Nu avem produsul respectiv. Incercati din nou cu un alt produs din lista noastra.";
		}
		catch (std::string ex)
		{
			std::cout << ex;
		}
			
	}
}

std::istream& operator>>(std::istream& in, ListaProduse& B)
{
	B.citire(in);
	return in;
}

void ListaProduse::afisare(std::ostream &out)
{
	out << "Lista de produse a pizzei contine:\n ";
	for (int i = 0; i < numar; i++)
		out << "\t" << produse[i] << '\n';
}

std::ostream & operator<<(std::ostream &out, ListaProduse &B)
{
	B.afisare(out);
	return out;
}

void ListaProduse::init(std::string src)
{
	std::ifstream in(src);
	in >> GamaNumar;
	Produs *p = new Produs;
	for (int i = 0; i < GamaNumar; i++)
	{	
		in >> *p;
		GamaProduse.push_back(*p);
	}
}

bool ListaProduse::addProdus(std::string denumire)
{	
	bool found = false;
	for (Produs i : produse)
		if (i.denumire == denumire)
		{
			found = true;
			i.cantitate++;
		}
	if (!found)
	{
		for(Produs i : GamaProduse)
			if (i.denumire == denumire)
			{
				found = true;
				i.times = 1;
				produse.push_back(i);
				numar++;
			}
	}
	return found;
}