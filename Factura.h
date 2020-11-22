#include <iostream>

using namespace std;

#include "Fecha.h"

class Factura
{
private:
    int id_Factura;
    int id_Cliente;
    Fecha fecha_Compra;
    int id_Producto;
    double cantidad;
    double total_a_pagar;

public:
    Factura(int id_Fact, int id_Cli, Fecha fecha_Comp, int id_Prod, double cant, double total);
    int getId_Factura();
    void setId_Factura(int id_Factura);
    int getId_Cliente();
    void setId_Cliente(int id_Cliente);
    Fecha getFecha_Compra();
    void setFecha_Compra(Fecha fecha_Compra);
    int getId_Producto();
    void setId_Producto(int id_Producto);
    double getCantidad();
    void setCantidad(double cantidad);
    double getTotal_a_pagar();
    void setTotal_a_pagar(double total_a_pagar);
};

Factura::Factura(int id_Fact, int id_Cli, Fecha fecha_Comp, int id_Prod, double cant, double total)
{
    this->id_Factura = id_Fact;
    this->id_Cliente = id_Cli;
    this->fecha_Compra = fecha_Comp;
    this->id_Producto = id_Prod;
    this->cantidad = cant;
    this->total_a_pagar = total;
}

int Factura::getId_Factura()
{
    return this->id_Factura;
}
void Factura::setId_Factura(int id_Factura)
{
    this->id_Factura = id_Factura;
}

int Factura::getId_Cliente()
{
    return this->id_Cliente;
}
void Factura::setId_Cliente(int id_Cliente)
{
    this->id_Cliente = id_Cliente;
}

Fecha Factura::getFecha_Compra()
{
    return this->fecha_Compra;
}
void Factura::setFecha_Compra(Fecha fecha_Compra)
{
    this->fecha_Compra = fecha_Compra;
}

int Factura::getId_Producto()
{
    return this->id_Producto;
}
void Factura::setId_Producto(int id_Producto)
{
    this->id_Producto = id_Producto;
}

double Factura::getCantidad()
{
    return this->cantidad;
}
void Factura::setCantidad(double cantidad)
{
    this->cantidad = cantidad;
}

double Factura::getTotal_a_pagar()
{
    return this->total_a_pagar;
}
void Factura::setTotal_a_pagar(double total_a_pagar)
{
    this->total_a_pagar = total_a_pagar;
}
