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
    Cuenta cuenta;

public:
    Empleado();
    Empleado(string nombre, string apellido, int edad, int ine, int id_Emp, int id_Dpto, string cargo, Cuenta cuenta);
    int getId_Empleado();
    void setId_Empleado(int id_Empleado);
    int getId_Dpto();
    void setId_Dpto(int id_Dpto);
    string getCargo();
    void setCargo(string cargo);
    Cuenta getCuenta();
    void setCuenta(Cuenta cuenta);
    void mostrarEmpleado();
};

Empleado::Empleado() : Persona(){
    Cuenta temp;
    this->id_Empleado = 0;
    this->id_Dpto = 0;
    this->cargo = "";
    this->cuenta = temp;
}

Empleado::Empleado(string nombre, string apellido, int edad, int ine, int id_Emp, int id_Dpto, string cargo, Cuenta cuenta) : Persona(nombre, apellido, edad, ine)
{
    this->id_Empleado = id_Emp;
    this->id_Dpto = id_Dpto;
    this->cargo = cargo;
    this->cuenta = cuenta;
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
    this->id_Dpto=id_Dpto;
}

string Empleado::getCargo()
{
    return this->cargo;
}
void Empleado::setCargo(string cargo)
{
    this->cargo = cargo;
}

Cuenta Empleado::getCuenta() {
	return this->cuenta;
}
void Empleado::setCuenta(Cuenta cuenta) {
	this->cuenta = cuenta;
}

void Empleado::mostrarEmpleado()
{
    cout << "Id Empleado: " << this->id_Empleado << endl;
    cout << "Id Departamento: " << this->id_Dpto <<endl;
    cout << "Cargo: " << this->cargo << endl;
    mostrarPersona();
}

#endif