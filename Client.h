#pragma once
#include "IClient.h"
#include <iostream>
#include <vector>

class Client :
    public IClient
{
protected:
    std::string nume;
    double buget;

public:
    Client(const std::string& nume, double buget);

	std::string get_nume() const override;
	double get_buget() const override;
	void afieaza_buget() const override;

	virtual void adauga_adresa(const std::string& adresa) override = 0;
	virtual void lanseaza_comanda(std::unique_ptr<IComanda> comanda) override = 0;
	virtual void afiseaza_istoric() const override = 0;

	void actualizeaza_buget(float total) override;
	virtual void adauga_in_istoric(std::unique_ptr<IComanda> comanda) override = 0;

	virtual ~Client() = default;
};

