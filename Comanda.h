#pragma once
#include "IComanda.h"
#include <iostream>
#include <vector>
#include <string>

class Comanda :
    public IComanda
{
protected:
    int id = 0;
    std::vector<Produs_Comanda> produse;

public:
    Comanda() = default;
    Comanda(int id, const std::vector<Produs_Comanda>& prod);
    Comanda(int id, std::vector<Produs_Comanda>&& prod);

    virtual Tip_Comanda get_tip_comanda() const override = 0;

    int get_id() const override;
    void set_id(int id_nou) override;
    
    void adauga_produs(const std::string& nume, int cantitate) override;
    const std::vector<Produs_Comanda>& get_produse() const override;

    void afiseaza_comanda() const override;

    virtual ~Comanda() = default;
};

