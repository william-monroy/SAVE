#ifndef Persona_h
#define Persona_h



#include "Cuenta.h"

class Persona
{
private:
    string nombre;
    string apellido;
    int edad;
    int ine;

public:
    Persona();
    Persona(string nombre, string apellido, int edad, int ine);
    string getNombre();
    void setNombre(string nombre);
    string getApellido();
    void setApellido(string apellido);
    int getEdad();
    void setEdad(int edad);
    int getIne();
    void setIne(int ine);
    void mostrarPersona();
};

Persona::Persona(){
    this->nombre = "";
    this->apellido = "";
    this->edad = 0;
    this->ine = 0;
}

Persona::Persona(string nombre, string apellido, int edad, int ine)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->ine = ine;
}

string Persona::getNombre()
{
    return this->nombre;
}
void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Persona::getApellido()
{
    return this->apellido;
}
void Persona::setApellido(string apellido)
{
    this->apellido = apellido;
}

int Persona::getEdad()
{
    return this->edad;
}
void Persona::setEdad(int edad)
{
    this->edad = edad;
}

int Persona::getIne()
{
    return this->ine;
}
void Persona::setIne(int ine)
{
    this->ine = ine;
}

void Persona::mostrarPersona()
{
    cout << "Nombre: " << this->nombre << endl;
    cout << "Apellido: " << this->apellido << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "INE: " << this->ine << endl;
}



#endif