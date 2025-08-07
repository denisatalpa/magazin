#include "Curier.h"
#include "Comanda_Simpla.h"
#include "Comanda_Jumbo.h"
#include "Exceptions.h"

Curier::Curier()
	:magazin(Magazin::get_instance()), catalog(magazin.get_stoc())
{
}

Curier& Curier::get_instance()
{
	static Curier instance;
	return instance;
}

const Catalog_Produs& Curier::get_catalog() const
{
	return catalog;
}

Chitanta Curier::proceseaza_comanda(std::unique_ptr<IComanda> comanda, IClient& client)
{
	int id = Unique_ID_Generator::get_instance()->generate_ID();
	comanda->set_id(id);

	Chitanta chitanta(id);
	float total = 0.0f;

	auto produse = comanda->get_produse();

	for (const auto& p : produse)
	{
		float pret = magazin.get_pret_produs(p.nume);

		if (!magazin.produs_disponibil(p.nume, p.cantitate))
		{
			chitanta.adauga_linie(p.nume, p.cantitate, pret, Status::INDISPONIBIL);
			continue;
		}

		float cost = p.cantitate * pret;

		if (total + cost > client.get_buget())
		{
			chitanta.adauga_linie(p.nume, p.cantitate, pret, Status::BUGET_INSUFICIENT);
			continue;
		}

		magazin.scade_stoc(p.nume, p.cantitate);
		chitanta.adauga_linie(p.nume, p.cantitate, pret, Status::ACHIZITIONAT);
		total += cost;
	}

	client.actualizeaza_buget(total);
	client.adauga_in_istoric(std::move(comanda));

	return chitanta;
}
