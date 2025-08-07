#include "Stoc_Produs.h"

Stoc_Produs::Stoc_Produs(const std::string& nume, float pret, int cantitate)
	:Produs(nume, pret), cantitate(cantitate)
{
}

int Stoc_Produs::get_cantitate() const
{
	return this->cantitate;
}

void Stoc_Produs::scade_cantitate(int nr)
{
	cantitate -= nr;
}
