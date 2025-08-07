#pragma once
#include <string>
#include <memory>
#include "IComanda.h"

class IClient 
{
public:
	virtual std::string get_nume() const = 0;
	virtual double get_buget() const = 0;
	virtual void afieaza_buget() const = 0;

	virtual void adauga_adresa(const std::string& adresa) = 0;
	virtual void lanseaza_comanda(std::unique_ptr<IComanda> comanda) = 0;
	virtual void afiseaza_istoric() const = 0;

	virtual void actualizeaza_buget(float total) = 0;
	virtual void adauga_in_istoric(std::unique_ptr<IComanda> comanda) = 0;

	virtual ~IClient() = default;
};
