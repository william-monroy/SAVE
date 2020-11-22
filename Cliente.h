#ifndef Cliente_h
#define Cliente_h


#include <iostream>
#include "Persona.h"

using namespace std;

class Cliente : public Persona
{
private:
    int id_Cliente;

public:
    Cliente(string nombre, string apellido, int edad, int ine, int id_Cli);
    int getId_Cliente();
    void setId_Cliente(int id_Cliente);
    void mostrarAlumno();
};

Cliente::Cliente(string nombre, string apellido, int edad, int ine, int id_Cli) : Persona(nombre, apellido, edad, ine)
{
    this->id_Cliente = id_Cli;
}

int Cliente::getId_Cliente()
{
    return this->id_Cliente;
}
void Cliente::setId_Cliente(int id_Cliente)
{
    this->id_Cliente = id_Cliente;
}

void Cliente::mostrarAlumno()
{
    cout << "Id Cliente: " << this->id_Cliente << endl;
    mostrarPersona();
}

#endif