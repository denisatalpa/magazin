#include "Unique_ID_Generator.h"

Unique_ID_Generator* Unique_ID_Generator::instance = nullptr;

Unique_ID_Generator* Unique_ID_Generator::get_instance()
{
    if (instance == nullptr)
    {
        instance = new Unique_ID_Generator();
    }
    return instance;
}

Unique_ID_Generator::~Unique_ID_Generator()
{
    ID_folosite.clear();
    ID_refolosibile.clear();

    delete instance;
    instance = nullptr;
}

int Unique_ID_Generator::generate_ID()
{
    if (!ID_refolosibile.empty())
    {
        int ID = *ID_refolosibile.begin();
        ID_refolosibile.erase(ID_refolosibile.begin());
        ID_folosite.insert(ID);
        return ID;
    }
    int ID_nou = ID_folosite.empty() ? 1 : (*ID_folosite.rbegin() + 1);
    ID_folosite.insert(ID_nou);
    return ID_nou;
}

void Unique_ID_Generator::delete_ID(int ID)
{
    if (ID_folosite.find(ID) != ID_folosite.end())
    {
        ID_folosite.erase(ID);
        ID_refolosibile.insert(ID);
    }
}
