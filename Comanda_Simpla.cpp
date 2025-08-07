#include "Comanda_Simpla.h"
#include "Exceptions.h"

Comanda_Simpla::Comanda_Simpla(int id, const std::vector<Produs_Comanda>& produse_input)
{
	if (produse_input.size() > 5)
	{
		throw Cantitate_Depasita_Exception("Comanda simpla nu poate avea mai mult de 5 produse");
	}
	this->id = id;
	this->produse = produse_input;
}

Comanda_Simpla::Comanda_Simpla(int id, std::vector<Produs_Comanda>&& produse_input)
{
	if (produse_input.size() > 5)
	{
		throw Cantitate_Depasita_Exception("Comanda simpla nu poate avea mai mult de 5 produse");
	}
	this->id = id;
	this->produse = std::move(produse_input);
}

Tip_Comanda Comanda_Simpla::get_tip_comanda() const
{
	return Tip_Comanda::Simplu;
}

void Comanda_Simpla::adauga_produs(const std::string& nume, int cantitate)
{
	if (produse.size() >= 5)
	{
		throw Cantitate_Depasita_Exception("Comanda simpla nu poate avea mai mult de 5 produse");
	}
	produse.push_back({ nume, cantitate });
}

void Comanda_Simpla::afiseaza_comanda() const
{
	std::cout << "Comanda Simpla ID: " << this->id << "\n";
	for (const auto& produs : produse)
	{
		std::cout << " - " << produs.nume << " x " << produs.cantitate << " buc.\n";
	}
}
