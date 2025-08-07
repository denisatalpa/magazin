#pragma once
#include "Client.h"

class Client_Obisnuit :
    public Client
{
private:
    std::string adresa;
    std::vector<std::unique_ptr<IComanda>> istoric;

public:
    Client_Obisnuit(const std::string& nume, double buget);

    void adauga_adresa(const std::string& adresa) override;
    void lanseaza_comanda(std::unique_ptr<IComanda> comanda) override;
    void afiseaza_istoric() const override;
    void adauga_in_istoric(std::unique_ptr<IComanda> comanda) override;
};

