#include "Client.h"
#include "Magazin.h"
#include <memory>

Client::Client(const std::string& nume, double buget)
	:nume(nume), buget(buget)
{
}

std::string Client::get_nume() const
{
	return this->nume;
}

double Client::get_buget() const
{
	return this->buget;
}

void Client::afieaza_buget() const
{
	std::cout << "Bugetul clientului " << this->nume << " este: " << this->buget << " lei\n";
}

void Client::actualizeaza_buget(float total)
{
    this->buget -= total;
}
