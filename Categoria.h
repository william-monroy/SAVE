#include <iostream>

using namespace std;

class Categoria
{
private:
    int id_Categoria;
    string nombre;

public:
    Categoria();
    Categoria(int id_Cat, string nom);
    int getId_Categoria();
    void setId_Categoria(int id_Categoria);
    string getNombre();
    void setNombre(string nombre);
};

Categoria::Categoria(){
    this->id_Categoria = 0;
    this->nombre = "";
}

Categoria::Categoria(int id_Cat, string nom)
{
    this->id_Categoria = id_Cat;
    this->nombre = nom;
}

int Categoria::getId_Categoria()
{
    return this->id_Categoria;
}
void Categoria::setId_Categoria(int id_Categoria)
{
    this->id_Categoria = id_Categoria;
}

string Categoria::getNombre()
{
    return this->nombre;
}
void Categoria::setNombre(string nombre)
{
    this->nombre = nombre;
}