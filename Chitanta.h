#pragma once
#include <iostream>
#include <vector>
#include <string>

enum class Status { ACHIZITIONAT, INDISPONIBIL, BUGET_INSUFICIENT };

struct Linie_Chitanta
{
	std::string nume;
	int cantitate;
	float pret_unitar;
	float pret_total;
	Status status;
};


class Chitanta
{
private:
	int comanda_id;
	std::vector<Linie_Chitanta> linii;
	float suma_totala = 0;

public:
	Chitanta(int id);

	void adauga_linie(const std::string& nume, int cant, float pret, Status status);
	void afiseaza_chitanta() const;
};

