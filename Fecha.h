#include <iostream>

using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int ano;

public:
    Fecha();
    Fecha(int dia, int mes, int ano);
    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAno();
    void setAno(int ano);
    void mostrarFecha();
};

Fecha::Fecha()
{
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
}

Fecha::Fecha(int dia, int mes, int ano)
{
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
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

int Fecha::getAno()
{
    return this->ano;
}
void Fecha::setAno(int ano)
{
    this->ano = ano;
}

void Fecha::mostrarFecha()
{
    cout << this->dia << "/" << this->mes << "/" << this->ano << endl;
}