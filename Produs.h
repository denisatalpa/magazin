#pragma once
#include <iostream>

class Produs
{
private:
	std::string nume;
	float pret;

public:
	Produs(const std::string& nume, float pret);

	const std::string& get_nume() const;
	float get_pret() const;
};

