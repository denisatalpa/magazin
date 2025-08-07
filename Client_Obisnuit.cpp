#include "Client_Obisnuit.h"
#include "Exceptions.h"

Client_Obisnuit::Client_Obisnuit(const std::string& nume, double buget)
	:Client(nume, buget)
{
}

void Client_Obisnuit::adauga_adresa(const std::string& adresa)
{
	this->adresa = adresa;
}

void Client_Obisnuit::lanseaza_comanda(std::unique_ptr<IComanda> comanda)
{
	if (comanda->get_tip_comanda() != Tip_Comanda::Simplu)
	{
		throw Tip_Comanda_Invalid("Clientul obisnuit poate plasa doar comenzi simple");
	}

	if (istoric.size() >= 10)
	{
		throw Nr_Maxim_Comenzi("Clientul obisnuit nu poate avea mai mult de 10 comenzi");
	}

	istoric.push_back(std::move(comanda));
}

void Client_Obisnuit::afiseaza_istoric() const
{
	std::cout << "Istoric comenzi pt clientul obisnuit " << this->nume << ":\n";
	for (const auto& comanda : istoric)
	{
		comanda->afiseaza_comanda();
	}
}

void Client_Obisnuit::adauga_in_istoric(std::unique_ptr<IComanda> comanda)
{
	if (istoric.size() >= 10)
	{
		throw Nr_Maxim_Comenzi("Clientul obisnuit nu poate avea mai mult de 10 comenzi");
	}
	istoric.push_back(std::move(comanda));
}
