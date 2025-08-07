#pragma once
#include <memory>

#include "IClient.h"
#include "Catalog_Produs.h"
#include "Magazin.h"
#include "Chitanta.h"
#include "Unique_ID_Generator.h"

class Curier
{
private:
	Catalog_Produs catalog;
	Magazin& magazin;

	Curier();

public:
	Curier(const Curier&) = delete;
	Curier& operator=(const Curier&) = delete;

	static Curier& get_instance();

	const Catalog_Produs& get_catalog() const;
	Chitanta proceseaza_comanda(std::unique_ptr<IComanda> comanda, IClient& client);
};

