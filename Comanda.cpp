#include "Comanda.h"

Comanda::Comanda(int id, const std::vector<Produs_Comanda>& prod)
	:id(id), produse(prod)
{
}

Comanda::Comanda(int id, std::vector<Produs_Comanda>&& prod)
	:id(id), produse(std::move(prod))
{
}

int Comanda::get_id() const
{
	return this->id;
}

void Comanda::set_id(int id_nou)
{
	this->id = id_nou;
}

void Comanda::adauga_produs(const std::string& nume, int cantitate)
{
	produse.push_back({ nume, cantitate });
}

const std::vector<Produs_Comanda>& Comanda::get_produse() const
{
	return produse;
}

void Comanda::afiseaza_comanda() const
{
	std::cout << "Comanda ID: " << this->id << "\n";
	for (const auto& produs : produse)
	{
		std::cout << " - " << produs.nume << " x " << produs.cantitate << " buc.\n";
	}
}
