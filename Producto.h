#include <iostream>

using namespace std;

class Producto
{
private:
    int id_Producto;
    string nombre;
    string descripcion;
    double stock;
    double precio;
    int id_Cate;

public:
    Producto(int id_Prod, string nom, string desc, double stock, double precio, int id_Cate);
    int getId_Producto();
    void setId_Producto(int id_Producto);
    string getNombre();
    void setNombre(string nombre);
    string getDescripcion();
    void setDescripcion(string descripcion);
    double getStock();
    void setStock(double stock);
    double getPrecio();
    void setPrecio(double precio);
    int getId_Cate();
    void setId_Cate(int id_Cate);
};

Producto::Producto(int id_Prod, string nom, string desc, double stock, double precio, int id_Cate)
{
}

int Producto::getId_Producto()
{
    return this->id_Producto;
}
void Producto::setId_Producto(int id_Producto)
{
    this->id_Producto = id_Producto;
}

string Producto::getNombre()
{
    return this->nombre;
}
void Producto::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Producto::getDescripcion()
{
    return this->descripcion;
}
void Producto::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

double Producto::getStock()
{
    return this->stock;
}
void Producto::setStock(double stock)
{
    this->stock = stock;
}

double Producto::getPrecio()
{
    return this->precio;
}
void Producto::setPrecio(double precio)
{
    this->precio = precio;
}

int Producto::getId_Cate()
{
    return this->id_Cate;
}
void Producto::setId_Cate(int id_Cate)
{
    this->id_Cate = id_Cate;
}