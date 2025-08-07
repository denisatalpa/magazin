#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Stoc_Produs.h"

class Curier;

class Magazin
{
private:
	std::vector<Stoc_Produs> stoc;
	Magazin(); // constructor privat pt ca facem singleton

public:
	friend class Curier;

	static Magazin& get_instance(); // acces la instanta unica pt singleton

	void incarca_stoc_din_fisier(const std::string& nume_fisier);
	bool produs_disponibil(const std::string& nume, int cantitate) const;
	float get_pret_produs(const std::string& nume) const;

	void scade_stoc(const std::string& nume, int cantitate);
	const std::vector<Stoc_Produs>& get_stoc() const;

	friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin);
};

