#include "Catalog_Produs.h"
#include <algorithm> // pt std::sort

Catalog_Produs::Catalog_Produs(const std::vector<Stoc_Produs>& stoc)
{
	for (const auto& s : stoc)
	{
		catalog.emplace_back(s.get_nume(), s.get_pret());
	}
	ordoneaza_alfabetic();
}

void Catalog_Produs::ordoneaza_alfabetic()
{
	std::sort(catalog.begin(), catalog.end(),
		[](const Produs& a, const Produs& b)
		{
			return a.get_nume() < b.get_nume();
		});
	//functie lambda pt sortare
}

void Catalog_Produs::afiseaza_catalog() const
{
	for (const auto& produs : catalog)
	{
		std::cout << produs.get_nume() << ": " << produs.get_pret() << " lei\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Catalog_Produs& cat)
{
	for (const auto& produs : cat.catalog)
	{
		os << produs.get_nume() << ": " << produs.get_pret() << " lei\n";
	}
	return os;
}
