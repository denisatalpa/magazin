#pragma once
#include "Produs.h"

class Stoc_Produs :
    public Produs
{
private:
    int cantitate;

public:
    Stoc_Produs(const std::string& nume, float pret, int cantitate);

    int get_cantitate() const;
    void scade_cantitate(int nr);
};

