#include "Comanda_Jumbo.h"

Comanda_Jumbo::Comanda_Jumbo(int id, const std::vector<Produs_Comanda>& produse_input)
{
	this->id = id;
	this->produse = produse_input;
}

Comanda_Jumbo::Comanda_Jumbo(int id, std::vector<Produs_Comanda>&& produse_input)
{
	this->id = id;
	this->produse = std::move(produse_input);
}

Tip_Comanda Comanda_Jumbo::get_tip_comanda() const
{
	return Tip_Comanda::Jumbo;
}

void Comanda_Jumbo::afiseaza_comanda() const
{
	std::cout << "Comanda Jumbo ID: " << this->id << "\n";
	for (const auto& produs : produse)
	{
		std::cout << " - " << produs.nume << " x " << produs.cantitate << " buc.\n";
	}
}
