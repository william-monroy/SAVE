#include <iostream>

using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int año;

public:
    Fecha();
    Fecha(int dia, int mes, int año);
    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAño();
    void setAño(int año);
    void mostrarFecha();
};

Fecha::Fecha()
{
    this->dia = 0;
    this->mes = 0;
    this->año = 0;
}

Fecha::Fecha(int dia, int mes, int año)
{
    this->dia = dia;
    this->mes = mes;
    this->año = año;
}

int Fecha::getDia()
{
    return this->dia;
}
void Fecha::setDia(int dia)
{
    this->dia = dia;
}

int Fecha::getMes()
{
    return this->mes;
}
void Fecha::setMes(int mes)
{
    this->mes = mes;
}

int Fecha::getAño()
{
    return this->año;
}
void Fecha::setAño(int año)
{
    this->año = año;
}

void Fecha::mostrarFecha()
{
    cout << this->dia << "/" << this->mes << "/" << this->año << endl;
}