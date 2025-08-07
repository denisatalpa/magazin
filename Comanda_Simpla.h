#pragma once
#include "Comanda.h"

class Comanda_Simpla :
    public Comanda
{
public:
    Comanda_Simpla() = default;
    Comanda_Simpla(int id, const std::vector<Produs_Comanda>& produse_input);
    Comanda_Simpla(int id, std::vector<Produs_Comanda>&& produse_input);

    Tip_Comanda get_tip_comanda() const override;

    void adauga_produs(const std::string& nume, int cantitate) override;
    void afiseaza_comanda() const override;
};

