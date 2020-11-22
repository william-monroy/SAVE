#include <iostream>

using namespace std;

class Departamento
{
private:
    int id_Dpto;
    string nombre;

public:
    Departamento(int id_Dpto, string nombre);
    int getId_Dpto();
    void setId_Dpto(int id_Dpto);
    string getNombre();
    void setNombre(string nombre);
};

Departamento::Departamento(int id_Dpto, string nombre)
{
}

int Departamento::getId_Dpto()
{
    return this->id_Dpto;
}
void Departamento::setId_Dpto(int id_Dpto)
{
    this->id_Dpto = id_Dpto;
}

string Departamento::getNombre()
{
    return this->nombre;
}
void Departamento::setNombre(string nombre)
{
    this->nombre = nombre;
}
