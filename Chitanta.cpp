#include "Chitanta.h"

Chitanta::Chitanta(int id)
	:comanda_id(id)
{
}

void Chitanta::adauga_linie(const std::string& nume, int cant, float pret, Status status)
{
	float total = 0;
	if (status == Status::ACHIZITIONAT)
	{
		total = cant * pret;
	}

	linii.push_back({ nume, cant, pret, total, status });
	suma_totala += total;
}

void Chitanta::afiseaza_chitanta() const
{
	std::cout << "Chitanta pentru comanda cu ID-ul " << this->comanda_id << std::endl;

	for (const auto& linie : linii)
	{
		std::cout << "  -  " << linie.nume << ": " << linie.cantitate << " buc. x "
			<< linie.pret_unitar << " lei = " << linie.pret_total << " lei ";
		
		switch (linie.status)
		{
		case Status::ACHIZITIONAT:
			std::cout << "(achizitionat)";
			break;

		case Status::INDISPONIBIL:
			std::cout << "(indisponibil)";
			break;

		case Status::BUGET_INSUFICIENT:
			std::cout << "(buget insuficient)";
			break;
		}

		std::cout << "\n";
	}

	std::cout << "Suma totala platita: " << suma_totala << " lei\n";
}
