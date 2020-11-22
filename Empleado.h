#ifndef Empleado_h
#define Empleado_h

#include <iostream>
#include "Persona.h"

using namespace std;

class Empleado : public Persona
{
private:
    int id_Empleado;
    int id_Dpto;
    string cargo;

public:
    Empleado();
    Empleado(string nombre, string apellido, int edad, int ine, int id_Emp, int id_Dpto, string cargo);
    int getId_Empleado();
    void setId_Empleado(int id_Empleado);
    int getId_Dpto();
    void setId_Dpto(int id_Dpto);
    string getCargo();
    void setCargo(string cargo);
};

Empleado::Empleado() : Persona(){
    this->id_Empleado = 0;
    this->id_Dpto = 0;
    this->cargo = "";
}

Empleado::Empleado(string nombre, string apellido, int edad, int ine, int id_Emp, int id_Dpto, string cargo) : Persona(nombre, apellido, edad, ine)
{
    this->id_Empleado = id_Emp;
    this->id_Dpto = id_Dpto;
    this->cargo = cargo;
}

int Empleado::getId_Empleado()
{
    return this->id_Empleado;
}
void Empleado::setId_Empleado(int id_Empleado)
{
    this->id_Empleado = id_Empleado;
}

int Empleado::getId_Dpto()
{
    return this->id_Dpto;
}
void Empleado::setId_Dpto(int id_Dpto)
{
    this->id_Dpto = id_Dpto;
}

string Empleado::getCargo()
{
    return this->cargo;
}
void Empleado::setCargo(string cargo)
{
    this->cargo = cargo;
}




#endif