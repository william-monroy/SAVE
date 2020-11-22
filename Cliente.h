#ifndef Cliente_h
#define Cliente_h


#include <iostream>
#include "Persona.h"
#include "Cuenta.h"

using namespace std;

class Cliente : public Persona
{
private:
    int id_Cliente;
    Cuenta cuenta;

public:
    Cliente();
    Cliente(string nombre, string apellido, int edad, int ine, int id_Cli, Cuenta cuenta);
    int getId_Cliente();
    void setId_Cliente(int id_Cliente);
    Cuenta getCuenta();
    void setCuenta(Cuenta cuenta);
    void mostrarCliente();
};

Cliente::Cliente(): Persona(){
    Cuenta temp;
    this->id_Cliente = 0;
    this->cuenta=temp;
}

Cliente::Cliente(string nombre, string apellido, int edad, int ine, int id_Cli, Cuenta cuenta) : Persona(nombre, apellido, edad, ine)
{
    this->id_Cliente = id_Cli;
    this->cuenta=cuenta;
}

int Cliente::getId_Cliente()
{
    return this->id_Cliente;
}
void Cliente::setId_Cliente(int id_Cliente)
{
    this->id_Cliente = id_Cliente;
}

Cuenta Cliente::getCuenta() {
	return this->cuenta;
}
void Cliente::setCuenta(Cuenta cuenta) {
	this->cuenta = cuenta;
}

void Cliente::mostrarCliente()
{
    cout << "Id Cliente: " << this->id_Cliente << endl;
    mostrarPersona();
}


#endif