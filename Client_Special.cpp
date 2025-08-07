#include "Client_Special.h"
#include "Exceptions.h"

Client_Special::Client_Special(const std::string& nume, double buget)
	:Client(nume, buget)
{
}

void Client_Special::adauga_adresa(const std::string& adresa)
{
	if (adrese.size() >= 3)
	{
		throw Nr_Maxim_Adrese("Clientul special nu poate avea mai mult de 3 aderse\n");
	}
	adrese.push_back(adresa);
}

void Client_Special::lanseaza_comanda(std::unique_ptr<IComanda> comanda)
{
	istoric.push_back(std::move(comanda));
}

void Client_Special::afiseaza_istoric() const
{
	std::cout << "Istoric comenzi pt clientul special " << this->nume << ":\n";
	for (const auto& comanda : istoric)
	{
		comanda->afiseaza_comanda();
	}
}

void Client_Special::adauga_in_istoric(std::unique_ptr<IComanda> comanda)
{
	istoric.push_back(std::move(comanda));
}
