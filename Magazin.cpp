#include "Magazin.h"
#include "Exceptions.h"

#include <fstream>
#include <sstream>
#include <algorithm>

Magazin::Magazin() {}

Magazin& Magazin::get_instance()
{
	static Magazin instance;
	return instance;
}

void Magazin::incarca_stoc_din_fisier(const std::string& nume_fisier)
{
	std::ifstream fisier(nume_fisier);

	if (!fisier)
	{
		throw File_Exception("Fisierul nu a putut fi deschis");
		return;
	}

	std::string linie;
	while (std::getline(fisier, linie))
	{
		std::stringstream iss(linie);
		std::string nume;
		float pret;
		int cantitate;

		if (iss >> nume >> pret >> cantitate)
		{
			stoc.emplace_back(nume, pret, cantitate);
			// folosim emplace back pt ca cream obiect nou cu constructor direct in vector
		}
	}
}

bool Magazin::produs_disponibil(const std::string& nume, int cantitate) const
{
	for (const auto& produs : stoc)
	{
		if (produs.get_nume() == nume && produs.get_cantitate() >= cantitate)
		{
			return true;
		}
	}
	return false;
}

float Magazin::get_pret_produs(const std::string& nume) const
{
	for (const auto& produs : stoc)
	{
		if (produs.get_nume() == nume)
		{
			return produs.get_pret();
		}
	}
	return 0;
}

void Magazin::scade_stoc(const std::string& nume, int cantitate)
{
	for (auto& produs : stoc)
	{
		if (produs.get_nume() == nume)
		{
			if (produs.get_cantitate() >= cantitate)
			{
				produs.scade_cantitate(cantitate);
			}
		}
		else
		{
			throw Produs_Exception("Nu exista acest produs");
		}
	}
}

const std::vector<Stoc_Produs>& Magazin::get_stoc() const
{
	return stoc;
}

std::ostream& operator<<(std::ostream& os, const Magazin& magazin)
{
	for (const auto& produs : magazin.stoc)
	{
		os << produs.get_nume() << " - " << produs.get_pret() << " lei, " << produs.get_cantitate() << " buc.\n";
	}
	return os;
}
