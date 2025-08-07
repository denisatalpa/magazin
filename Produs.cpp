#include "Produs.h"

Produs::Produs(const std::string& nume, float pret)
	:nume(nume), pret(pret)
{
}

const std::string& Produs::get_nume() const
{
	return this->nume;
}

float Produs::get_pret() const
{
	return this->pret;
}
