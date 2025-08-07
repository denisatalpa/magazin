#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <exception>
#include "Magazin.h"
#include "Curier.h"
#include "Client_Obisnuit.h"
#include "Client_Special.h"
#include "Comanda_Simpla.h"
#include "Comanda_Jumbo.h"
#include "Exceptions.h"

int main() {
    try {
        // Incarca stocul magazinului dintr-un fisier (creati "stoc.txt" cu minim 15 produse, ex: Paine 5.5 20)
        Magazin& magazin = Magazin::get_instance();
        magazin.incarca_stoc_din_fisier("stoc.txt");

        // Curierul unic se initializeaza automat cu catalogul de produse de la Magazin
        Curier& curier = Curier::get_instance();

        // Afiseaza catalogul de produse (lambda-sortare)
        std::cout << "===== Catalogul de produse ordonat alfabetic =====\n";
        curier.get_catalog().afiseaza_catalog();
        std::cout << "\n";

        // Creaza un client obisnuit
        Client_Obisnuit client1("Popescu Ana", 1000.0);
        client1.adauga_adresa("Str. Lalelelor 5, Bl. 2, Ap. 12");
        std::cout << "Client obisnuit: " << client1.get_nume() << "\n";
        client1.afieaza_buget();

        // Pregateste o comanda simpla (max 5 produse)
        auto comanda_simpla = std::make_unique<Comanda_Simpla>();
        comanda_simpla->adauga_produs("Tastatura", 2);
        comanda_simpla->adauga_produs("Scanner", 1);
        comanda_simpla->adauga_produs("Mouse", 3);
        
        std::cout << "\nComanda simpla plasata:\n";
        comanda_simpla->afiseaza_comanda();

        // Trimite comanda la curier (move semantics)
        auto chitanta1 = curier.proceseaza_comanda(std::move(comanda_simpla), client1);

        // Afiseaza chitanta si bugetul ramas
        std::cout << "\n===== Chitanta primita de clientul obisnuit =====\n";
        chitanta1.afiseaza_chitanta();
        client1.afieaza_buget();
        std::cout << "-----------------------------------------\n";

        // Afiseaza istoricul clientului obisnuit
        client1.afiseaza_istoric();

        // --------------------------------------------------------

        // Creaza un client special
        Client_Special client2("Ionescu Maria", 5000.0);
        client2.adauga_adresa("Str. Viorelelor 10");
        client2.adauga_adresa("Str. Magnoliilor 23");
        client2.adauga_adresa("Str. Garoafelor 7");
        // urmatoarea linie ar trebui sa arunce exceptie:
        try {
            client2.adauga_adresa("Str. Bujorilor 99");
        }
        catch (const Exception& ex) {
            std::cout << "Exceptie la adaugare adresa: " << ex.get_message() << std::endl;
        }

        std::cout << "\nClient special: " << client2.get_nume() << "\n";
        client2.afieaza_buget();

        // Pregateste o comanda jumbo (oricat de multe produse)
        auto comanda_jumbo = std::make_unique<Comanda_Jumbo>();
        comanda_jumbo->adauga_produs("Sursa", 3);
        comanda_jumbo->adauga_produs("HardDisk", 2);
        comanda_jumbo->adauga_produs("PlacaVideo", 1);
        comanda_jumbo->adauga_produs("SSD", 1);
        
        std::cout << "\nComanda jumbo plasata:\n";
        comanda_jumbo->afiseaza_comanda();

        // Trimite comanda la curier (move semantics)
        auto chitanta2 = curier.proceseaza_comanda(std::move(comanda_jumbo), client2);

        // Afiseaza chitanta si bugetul ramas
        std::cout << "\n===== Chitanta primita de clientul special =====\n";
        chitanta2.afiseaza_chitanta();
        client2.afieaza_buget();
        std::cout << "-----------------------------------------\n";

        // Afiseaza istoricul clientului special
        client2.afiseaza_istoric();

        // --------------------------------------------------------

        // Afiseaza stocul magazinului dupa procesarea comenzilor
        std::cout << "\n===== Stocul magazinului dupa comenzi =====\n";
        std::cout << magazin;

    }
    catch (const Exception& ex) {
        std::cout << "Exceptie: " << ex.get_message() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Exceptie din std: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "Exceptie necunoscuta!\n";
    }

    return 0;
}