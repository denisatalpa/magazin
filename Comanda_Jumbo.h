#pragma once
#include "Comanda.h"

class Comanda_Jumbo :
    public Comanda
{
public:
    Comanda_Jumbo() = default;
    Comanda_Jumbo(int id, const std::vector<Produs_Comanda>& produse_input);
    Comanda_Jumbo(int id, std::vector<Produs_Comanda>&& produse_input);

    Tip_Comanda get_tip_comanda() const override;

    void afiseaza_comanda() const override;
};

