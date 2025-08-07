#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>


struct Produs_Comanda
{
	std::string nume;
	int cantitate;
};

enum class Tip_Comanda
{
	Simplu,
	Jumbo
};

class IComanda
{
public:
	virtual Tip_Comanda get_tip_comanda() const = 0;

	virtual int get_id() const = 0;
	virtual void set_id(int id) = 0;

	virtual void adauga_produs(const std::string& nume, int cantitate) = 0;
	virtual const std::vector<Produs_Comanda>& get_produse() const = 0;
	
	virtual void afiseaza_comanda() const = 0;

	virtual ~IComanda() = default;
};