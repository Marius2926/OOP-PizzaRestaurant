#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
const std::string SourceText("ingredients.txt");
class Produs
{
	std::string denumire;
	int cantitate;
	double pret;
	int times;

public:
	Produs(std::string d=" ",int c=0,double p=0,int times=0);
	~Produs();
	Produs(const Produs&);
	Produs& operator=(const Produs&);
	friend std::istream& operator>>(std::istream&, Produs&);
	friend std::ostream& operator<<(std::ostream&, Produs&);
	friend class ListaProduse;
	double Pret();
};

