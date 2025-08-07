#pragma once
#include "Client.h"

class Client_Special :
    public Client
{
private:
    std::vector<std::string> adrese;
    std::vector<std::unique_ptr<IComanda>> istoric;

public:
    Client_Special(const std::string& nume, double buget);

    void adauga_adresa(const std::string& adresa) override;
    void lanseaza_comanda(std::unique_ptr<IComanda> comanda) override;
    void afiseaza_istoric() const override;
    void adauga_in_istoric(std::unique_ptr<IComanda> comanda) override;
};

