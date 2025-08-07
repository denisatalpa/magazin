#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "Produs.h"
#include "Stoc_Produs.h"

class Catalog_Produs
{
private:
	std::vector<Produs> catalog;

public:
	Catalog_Produs(const std::vector<Stoc_Produs>& stoc);

	void ordoneaza_alfabetic();
	void afiseaza_catalog() const;

	friend std::ostream& operator<<(std::ostream& os, const Catalog_Produs& cat);
	//prin friend ii permitem accees la membri privati ai clasei
};

