#include "Calcul.h"
#include "ListaProduse.h"
#include "Produs.h"
#include "Pizza.h"
#include "Meniu.h"
using namespace std;

int main()
{	
	ListaProduse Prd;
	ListaProduse::init("ingredients.txt");
	Prd.addProdus("cascaval");
	Prd.addProdus("pui");
	Prd.addProdus("blat");
	Prd.addProdus("sos de rosii");
	Prd.addProdus("vita");
	Prd.addProdus("pui");
	Prd.addProdus("parmezan");
	Pizza A(Prd,1,3);
	cout << A;
	Meniu<int> M;
	M.makePizza("hawai");
	M.makePizza("pui");
	M.makePizza("vegetariana");
	cout << M;
	return 0;
}