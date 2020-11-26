#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <ctime>
#include <math.h>

#ifdef _WIN64
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

#include "Cuenta.h"
#include "Departamento.h"
#include "Cliente.h"
#include "Categoria.h"
#include "Empleado.h"
#include "Producto.h"
#include "Factura.h"
#include "Img.h"
#include "Util.h"

void sleepcp(int milliseconds);

void sleepcp(int milliseconds)
{
#ifdef _WIN64
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

void cargarCuentas(vector<Cuenta> &cuentas)
{
    ifstream archivo;
    archivo.open("cuentas.csv");
    string usr, pas, per, id;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, usr, ',');
        getline(archivo, pas, ',');
        getline(archivo, per, ',');
        getline(archivo, id);
        int perm = atoi(per.c_str());
        int idi = atoi(id.c_str());
        Cuenta temp(usr, pas, perm, idi);
        cuentas.push_back(temp);
    }
    archivo.close();
    /*
    for (int i = 0; i < cuentas.size(); i++)
    {
        cout << "\nCuenta " << i + 1 << endl;
        cuentas.at(i).mostrarCuenta();
    }
    */
}

void cargarEmpleados(vector<Empleado> &empleados)
{
    ifstream archivo;
    archivo.open("empleados.csv");
    string nom, ape, edad, ine, id_Em, id_Dp, carg, usr, pas, per, id;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, nom, ',');
        getline(archivo, ape, ',');
        getline(archivo, edad, ',');
        getline(archivo, ine, ',');
        getline(archivo, id_Em, ',');
        getline(archivo, id_Dp, ',');
        getline(archivo, carg, ',');
        getline(archivo, usr, ',');
        getline(archivo, pas, ',');
        getline(archivo, per, ',');
        getline(archivo, id);
        int edadi = atoi(edad.c_str());
        int inei = atoi(ine.c_str());
        int id_Emi = atoi(id_Em.c_str());
        int id_Dpi = atoi(id_Dp.c_str());
        int peri = atoi(per.c_str());
        int idi = atoi(id.c_str());
        Cuenta tempCuenta(usr, pas, peri, idi);
        Empleado temp(nom, ape, edadi, inei, id_Emi, id_Dpi, carg, tempCuenta);
        empleados.push_back(temp);
    }
    archivo.close();
    /*
    for (int i = 0; i < empleados.size(); i++)
    {
        cout << "\nEmpleado "<<i+1<<endl;
        empleados.at(i).mostrarEmpleado();
        empleados.at(i).getCuenta().mostrarCuenta();
    }
    */
}

void cargarClientes(vector<Cliente> &clientes)
{
    ifstream archivo;
    archivo.open("clientes.csv");
    string nom, ape, edad, ine, id_Cli, usr, pas, per, id;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, nom, ',');
        getline(archivo, ape, ',');
        getline(archivo, edad, ',');
        getline(archivo, ine, ',');
        getline(archivo, id_Cli, ',');
        getline(archivo, usr, ',');
        getline(archivo, pas, ',');
        getline(archivo, per, ',');
        getline(archivo, id);
        int edadi = atoi(edad.c_str());
        int inei = atoi(ine.c_str());
        int id_Clii = atoi(id_Cli.c_str());
        int peri = atoi(per.c_str());
        int idi = atoi(id.c_str());
        Cuenta tempCuenta(usr, pas, peri, idi);
        Cliente temp(nom, ape, edadi, inei, id_Clii, tempCuenta);
        clientes.push_back(temp);
    }
    archivo.close();
    /*
    for (int i = 0; i < clientes.size(); i++)
    {
        cout << "\nCliente "<<i+1<<endl;
        clientes.at(i).mostrarCliente();
        clientes.at(i).getCuenta().mostrarCuenta();
    }
    */
}

void cargarCategorias(vector<Categoria> &categorias)
{
    ifstream archivo;
    archivo.open("categorias.csv");
    string id, nom;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, id, ',');
        getline(archivo, nom);
        int idi = atoi(id.c_str());
        Categoria temp(idi, nom);
        categorias.push_back(temp);
    }
    archivo.close();
    /*
    for (int i = 0; i < categorias.size(); i++)
    {
        cout << "\nCategoria " << i + 1 << endl;
        cout<<"ID: "<<categorias.at(i).getId_Categoria()<<endl;
        cout<<"Nombre: "<<categorias.at(i).getNombre()<<endl;
    }
    */
}

void cargarDepartamentos(vector<Departamento> &departamentos)
{
    ifstream archivo;
    archivo.open("departamentos.csv");
    string id, nom;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, id, ',');
        getline(archivo, nom);
        int idi = atoi(id.c_str());
        Departamento temp(idi, nom);
        departamentos.push_back(temp);
    }
    archivo.close();
    /*
    for (int i = 0; i < departamentos.size(); i++)
    {
        cout << "\nDepartamento " << i + 1 << endl;
        cout<<"ID: "<<departamentos.at(i).getId_Dpto()<<endl;
        cout<<"Nombre: "<<departamentos.at(i).getNombre()<<endl;
    }
    */
}

void cargarProductos(vector<Producto> &productos)
{
    ifstream archivo;
    archivo.open("productos.csv");
    string id_prod, nom, desc, stock, precio, id_cat;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, id_prod, ',');
        getline(archivo, nom, ',');
        getline(archivo, desc, ',');
        getline(archivo, stock, ',');
        getline(archivo, precio, ',');
        getline(archivo, id_cat);
        int id_prodi = atoi(id_prod.c_str());
        int id_cati = atoi(id_cat.c_str());
        double stockd = atof(stock.c_str());
        double preciod = atof(precio.c_str());
        Producto temp(id_prodi, nom, desc, stockd, preciod, id_cati);
        productos.push_back(temp);
    }
    archivo.close();
    /*
    for (int i = 0; i < productos.size(); i++)
    {
        cout << "\nProducto " << i + 1 << endl;
        productos.at(i).mostrarProducto();
    }
    */
}

void cargarFacturas(vector<Factura> &facturas)
{
    ifstream archivo;
    archivo.open("facturas.csv");
    string id_fact, id_cli, dd, mm, aa, id_prod, cant, tot;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, id_fact, ',');
        getline(archivo, id_cli, ',');
        getline(archivo, dd, ',');
        getline(archivo, mm, ',');
        getline(archivo, aa, ',');
        getline(archivo, id_prod, ',');
        getline(archivo, cant, ',');
        getline(archivo, tot);
        int id_facti = atoi(id_fact.c_str());
        int id_clii = atoi(id_cli.c_str());
        int ddi = atoi(dd.c_str());
        int mmi = atoi(mm.c_str());
        int aai = atoi(aa.c_str());
        int id_prodi = atoi(id_prod.c_str());
        double cantd = atof(cant.c_str());
        double totd = atof(tot.c_str());
        Fecha ftemp(ddi, mmi, aai);
        Factura temp(id_facti, id_clii, ftemp, id_prodi, cantd, totd);
        facturas.push_back(temp);
    }
    archivo.close();
    /*
    for (int i = 0; i < facturas.size(); i++)
    {
        cout << "\nFactura " << i + 1 << endl;
        cout << "ID: " << facturas.at(i).getId_Factura()<< endl;
        cout << "Cliente: " << facturas.at(i).getId_Cliente()<< endl;
        facturas.at(i).getFecha_Compra().mostrarFecha();
        cout << "Producto: " << facturas.at(i).getId_Producto()<< endl;
        cout << "Cantidad: " << facturas.at(i).getCantidad()<< endl;
        cout << "Total: " << facturas.at(i).getTotal_a_pagar()<< endl;
    }
    */
}

bool login(string &user, string &pass, vector<Cuenta> cuentas, int &permiso, int &id_Persona)
{
    bool cont = true;
    printLogin(user, pass);
    bool encontrado = false;
    for (int i = 0; i < cuentas.size(); i++)
    {
        if (cuentas.at(i).getUsuario() == user)
        {
            if (cuentas.at(i).getPass() == pass)
            {
                encontrado = true;
                permiso = cuentas.at(i).getPermiso();
                id_Persona = cuentas.at(i).getId_Persona();
                cout << "Datos correctos" << endl;
                i = cuentas.size();
                return true;
            }
            else
            {
                cout << "Contraseña incorrecta" << endl;
                permiso = 0;
                id_Persona = 0;
                return false;
            }
        }
        else if (i == cuentas.size() - 1 && encontrado == false)
        {
            cout << "La cuenta no existe" << endl;
            permiso = 0;
            id_Persona = 0;
            return false;
        }
    }
}

string getNombreUsr(int permiso, int id_Persona, vector<Empleado> empleados, vector<Cliente> clientes)
{
    string temp;
    if (permiso == 2 || permiso == 3)
    {
        for (int i = 0; i < empleados.size(); i++)
        {
            if (empleados.at(i).getId_Empleado() == id_Persona)
            {
                temp = empleados.at(i).getNombre();
                temp += " " + empleados.at(i).getApellido();
                i = empleados.size();
            }
        }
    }
    else
    {
        for (int j = 0; j < clientes.size(); j++)
        {
            if (clientes.at(j).getId_Cliente() == id_Persona)
            {
                temp = clientes.at(j).getNombre();
                temp += " " + clientes.at(j).getApellido();
                j = clientes.size();
            }
        }
    }
    return temp;
}

string charToString(char c[])
{
    int array_size = sizeof(c) / sizeof(char);
    string j = "";
    int i = 0;
    while (i < array_size)
    {
        j = j + c[i];
        i++;
    }
    return j;
}

void obtenerFecha(Fecha &fechaActual)
{
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int dd = now->tm_mday;
    int mm = now->tm_mon + 1;
    int aa = now->tm_year + 1900;
    fechaActual.setDia(dd);
    fechaActual.setMes(mm);
    fechaActual.setAno(aa);
}

void actualizarProductos(vector<Producto> productos)
{
    ofstream csvProd;
    csvProd.open("productos.csv");
    for (int i = 0; i < productos.size(); i++)
    {
        if (i < productos.size() - 1)
        {
            csvProd << productos.at(i).getId_Producto() << "," << productos.at(i).getNombre() << "," << productos.at(i).getDescripcion() << "," << productos.at(i).getStock() << "," << productos.at(i).getPrecio() << "," << productos.at(i).getId_Cate() << endl;
        }
        else
        {
            csvProd << productos.at(i).getId_Producto() << "," << productos.at(i).getNombre() << "," << productos.at(i).getDescripcion() << "," << productos.at(i).getStock() << "," << productos.at(i).getPrecio() << "," << productos.at(i).getId_Cate();
        }
    }
    csvProd.close();
}

void actualizarClientes(vector<Cliente> clientes)
{
    ofstream csvClientes;
    csvClientes.open("clientes.csv");
    for (int i = 0; i < clientes.size(); i++)
    {
        if (i < clientes.size() - 1)
        {
            csvClientes << clientes.at(i).getNombre() << "," << clientes.at(i).getApellido() << "," << clientes.at(i).getEdad() << "," << clientes.at(i).getIne() << "," << clientes.at(i).getId_Cliente() << "," << clientes.at(i).getCuenta().getUsuario() << "," << clientes.at(i).getCuenta().getPass() << "," << clientes.at(i).getCuenta().getPermiso() << "," << clientes.at(i).getCuenta().getId_Persona() << endl;
        }
        else
        {
            csvClientes << clientes.at(i).getNombre() << "," << clientes.at(i).getApellido() << "," << clientes.at(i).getEdad() << "," << clientes.at(i).getIne() << "," << clientes.at(i).getId_Cliente() << "," << clientes.at(i).getCuenta().getUsuario() << "," << clientes.at(i).getCuenta().getPass() << "," << clientes.at(i).getCuenta().getPermiso() << "," << clientes.at(i).getCuenta().getId_Persona();
        }
    }
    csvClientes.close();
}

void actualizarEmpleados(vector<Empleado> empleados)
{
    ofstream csvEmpleados;
    csvEmpleados.open("empleados.csv");
    for (int i = 0; i < empleados.size(); i++)
    {
        if (i < empleados.size() - 1)
        {
            csvEmpleados << empleados.at(i).getNombre() << "," << empleados.at(i).getApellido() << "," << empleados.at(i).getEdad() << "," << empleados.at(i).getIne() << "," << empleados.at(i).getId_Empleado() << "," << empleados.at(i).getId_Dpto() << "," << empleados.at(i).getCargo() << "," << empleados.at(i).getCuenta().getUsuario() << "," << empleados.at(i).getCuenta().getPass() << "," << empleados.at(i).getCuenta().getPermiso() << "," << empleados.at(i).getCuenta().getId_Persona() << endl;
        }
        else
        {
            csvEmpleados << empleados.at(i).getNombre() << "," << empleados.at(i).getApellido() << "," << empleados.at(i).getEdad() << "," << empleados.at(i).getIne() << "," << empleados.at(i).getId_Empleado() << "," << empleados.at(i).getId_Dpto() << "," << empleados.at(i).getCargo() << "," << empleados.at(i).getCuenta().getUsuario() << "," << empleados.at(i).getCuenta().getPass() << "," << empleados.at(i).getCuenta().getPermiso() << "," << empleados.at(i).getCuenta().getId_Persona();
        }
    }
    csvEmpleados.close();
}

int main()
{
    color(2);
    cout << endl;
    string SO = "";
    SetConsoleOutputCP(CP_UTF8);
#if defined(_WIN64)
    cout << "Estoy en Windows de 64 bits.\n"
         << endl;
    SO = "Windows";
#elif defined(__linux__)
    cout << "Estoy en Linux." << endl;
    SO = "Linux";
#elif defined(__MACH__)
    cout << "Estoy en Mac." << endl;
    SO = "Mac";
#endif
    clear(SO);
    printTitulo();
    vector<Cuenta> cuentas;
    vector<Empleado> empleados;
    vector<Categoria> categorias;
    vector<Cliente> clientes;
    vector<Departamento> departamentos;
    vector<Producto> productos;
    vector<Factura> facturas;
    Fecha fechaActual;
    obtenerFecha(fechaActual);
    cout << fechaActual.getDia() << "/" << fechaActual.getMes() << "/" << fechaActual.getAno() << endl
         << endl;
    cout << "Cargando cuentas..." << endl;
    cargarCuentas(cuentas);
    sleepcp(500);
    cout << "OK..." << endl;
    cout << "Cargando Empleados..." << endl;
    cargarEmpleados(empleados);
    sleepcp(500);
    cout << "OK..." << endl;
    cout << "Cargando categorias..." << endl;
    cargarCategorias(categorias);
    sleepcp(500);
    cout << "OK..." << endl;
    cout << "Cargando clientes..." << endl;
    cargarClientes(clientes);
    sleepcp(500);
    cout << "OK..." << endl;
    cout << "Cargando departamentos..." << endl;
    cargarDepartamentos(departamentos);
    sleepcp(500);
    cout << "OK..." << endl;
    cout << "Cargando productos..." << endl;
    cargarProductos(productos);
    sleepcp(500);
    cout << "OK..." << endl;
    cout << "Cargando facturas..." << endl;
    cargarFacturas(facturas);
    sleepcp(500);
    cout << "OK..." << endl;
    sleepcp(500);
    clear(SO);
    printTitulo();

    string usuario, pass, nombre;
    int permiso, id_Persona;
    int id_Fact = facturas.at(facturas.size() - 1).getId_Factura() + 1;
    bool carrito = false;
    bool pagado = false;
    if (login(usuario, pass, cuentas, permiso, id_Persona))
    {

        int opcion;
        sleepcp(2500);
        //CODIGO DEL PROGRAMA
        clear(SO);
        color(6);
        printTitulo();
        nombre = getNombreUsr(permiso, id_Persona, empleados, clientes);
        printBienvenida(nombre);
        sleepcp(2500);
        bool cont = true;
        while (cont)
        {
            clear(SO);
            color(3);
            printTitulo();
            printMain(permiso);
            cout << "\t\t\t\t\tOPCION: ";
            cin >> opcion;
            switch (opcion)
            {
            case 1: // CLIENTE - VENDEDOR - ADMINISTRADOR & MIS DATOS
            {
                bool c = true;
                while (c)
                {
                    clear(SO);
                    printTitulo();
                    printMainDatos();
                    int o;
                    cout << "\t\t\t\t\tOPCION: ";
                    cin >> o;
                    switch (o)
                    {
                    case 1:
                    {
                        clear(SO);
                        printTitulo();
                        printMisDatos(permiso, empleados, clientes, departamentos, id_Persona);
                        pause(SO);
                        break;
                    }
                    case 2:
                    {
                        bool co = true;
                        while (co)
                        {
                            clear(SO);
                            printTitulo();
                            printCRUD(permiso, empleados, clientes, id_Persona);
                            int op;
                            cout << "\t\t\t\t\tOPCION: ";
                            cin >> op;
                            if (permiso == 1) // CAMBIAR MIS DATOS PARA CLIENTES
                            {
                                string nnom, nape, nusr, npss;
                                switch (op)
                                {
                                case 1:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Nombre Actual: " << clientes.at(id_Persona).getNombre() << endl;
                                    nnom = leerStr("Nuevo Nombre: ");

                                    clientes.at(id_Persona).setNombre(nnom);

                                    actualizarClientes(clientes);

                                    pause(SO);
                                    break;
                                }
                                case 2:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Apellido Actual: " << clientes.at(id_Persona).getApellido() << endl;
                                    nape = leerStr("Nuevo Apellido: ");

                                    clientes.at(id_Persona).setApellido(nape);

                                    actualizarClientes(clientes);

                                    pause(SO);
                                    break;
                                }
                                case 3:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "INE Actual: " << clientes.at(id_Persona).getIne() << endl;
                                    int nine = leerInt("Nuevo INE: ");

                                    clientes.at(id_Persona).setIne(nine);

                                    actualizarClientes(clientes);

                                    pause(SO);
                                    break;
                                }
                                case 4:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Edad Actual: " << clientes.at(id_Persona).getEdad() << endl;
                                    int neda = leerInt("Nueva Edad: ");

                                    clientes.at(id_Persona).setEdad(neda);

                                    actualizarClientes(clientes);

                                    pause(SO);
                                    break;
                                }
                                case 5:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Usuario Actual: " << clientes.at(id_Persona).getCuenta().getUsuario() << endl;
                                    nusr = leerStr("Nuevo Usuario: ");

                                    Cuenta tempusr(nusr, clientes.at(id_Persona).getCuenta().getPass(), clientes.at(id_Persona).getCuenta().getPermiso(), clientes.at(id_Persona).getCuenta().getId_Persona());

                                    clientes.at(id_Persona).setCuenta(tempusr);

                                    pause(SO);
                                    break;
                                }
                                case 6:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Password Actual: " << clientes.at(id_Persona).getCuenta().getPass() << endl;
                                    npss = leerStr("Nuevo Password: ");

                                    Cuenta tempps(clientes.at(id_Persona).getCuenta().getUsuario(), npss, clientes.at(id_Persona).getCuenta().getPermiso(), clientes.at(id_Persona).getCuenta().getId_Persona());

                                    clientes.at(id_Persona).setCuenta(tempps);

                                    pause(SO);
                                    break;
                                }
                                case 7:
                                {
                                    co = false;
                                    break;
                                }
                                default:
                                {
                                    cout << "ERROR: Opcion Incorrecta\n"
                                         << endl;
                                    pause(SO);
                                    break;
                                }
                                }
                            }
                            else // CAMBIAR MIS DATOS PARA VENDEDOR O ADMINISTRADOR
                            {
                                string nnom, nape, ncrg, nusr, npss;
                                switch (op)
                                {
                                case 1:
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << empleados.at(id_Persona).getId_Empleado() << endl;
                                    cout << "Nombre Actual: " << empleados.at(id_Persona).getNombre() << endl;
                                    nnom = leerStr("Nuevo Nombre: ");

                                    empleados.at(id_Persona).setNombre(nnom);

                                    actualizarEmpleados(empleados);

                                    cout << nnom;
                                    pause(SO);
                                    break;
                                case 2:
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                    cout << "Apellido Actual: " << empleados.at(id_Persona).getApellido() << endl;
                                    nape = charToString("Nuevo Apellido: ");

                                    empleados.at(id_Persona).setApellido(nape);

                                    actualizarEmpleados(empleados);

                                    pause(SO);
                                    break;
                                case 3:
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                    cout << "INE Actual: " << empleados.at(id_Persona).getIne() << endl;
                                    int nine = leerInt("Nuevo INE: ");

                                    empleados.at(id_Persona).setIne(nine);

                                    actualizarEmpleados(empleados);

                                    pause(SO);
                                    break;
                                case 4:
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                    cout << "Edad Actual: " << empleados.at(id_Persona).getEdad() << endl;
                                    int neda = leerInt("Nuevo Edad: ");

                                    empleados.at(id_Persona).setEdad(neda);

                                    actualizarEmpleados(empleados);

                                    pause(SO);
                                    break;

                                case 5:
                                    if (permiso == 3)
                                    {
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                        cout << "Departamento Actual: " << empleados.at(id_Persona).getId_Dpto() << endl;
                                        int ndpt = leerInt("Nuevo Departamento: ");

                                        empleados.at(id_Persona).setId_Dpto(ndpt);

                                        actualizarEmpleados(empleados);

                                        pause(SO);
                                    }
                                    else
                                    {
                                        cout << "No tiene permisos necesarios para esta accion." << endl;
                                    }
                                    pause(SO);
                                    break;
                                case 6:
                                    if (permiso == 3)
                                    {
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                        cout << "Cargo Actual: " << empleados.at(id_Persona).getCargo() << endl;
                                        ncrg = leerStr("Nuevo Cargo: ");

                                        empleados.at(id_Persona).setCargo(ncrg);

                                        actualizarEmpleados(empleados);

                                        pause(SO);
                                    }
                                    else
                                    {
                                        cout << "No tiene permisos necesarios para esta accion." << endl;
                                    }
                                    pause(SO);
                                    break;
                                case 7:
                                    if (permiso == 3)
                                    {
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                        cout << "Usuario Actual: " << empleados.at(id_Persona).getCuenta().getUsuario() << endl;
                                        nusr = leerStr("Nuevo Usuario: ");

                                        Cuenta tempEmpl(nusr, empleados.at(id_Persona).getCuenta().getPass(), empleados.at(id_Persona).getCuenta().getPermiso(), empleados.at(id_Persona).getCuenta().getId_Persona());
                                        empleados.at(id_Persona).setCuenta(tempEmpl);

                                        actualizarEmpleados(empleados);

                                        pause(SO);
                                    }
                                    else
                                    {
                                        cout << "No tiene permisos necesarios para esta accion." << endl;
                                    }
                                    pause(SO);
                                    break;
                                case 8:
                                    if (permiso == 3)
                                    {
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                        cout << "Password Actual: " << empleados.at(id_Persona).getCuenta().getPass() << endl;
                                        npss = leerStr("Nuevo Password: ");

                                        Cuenta tempEmpl(empleados.at(id_Persona).getCuenta().getUsuario(), npss, empleados.at(id_Persona).getCuenta().getPermiso(), empleados.at(id_Persona).getCuenta().getId_Persona());
                                        empleados.at(id_Persona).setCuenta(tempEmpl);

                                        actualizarEmpleados(empleados);
                                    }
                                    else
                                    {
                                        cout << "No tiene permisos necesarios para esta accion." << endl;
                                    }
                                    pause(SO);
                                    break;
                                case 9:
                                    co = false;
                                    break;
                                default:
                                    cout << "ERROR: Opcion Incorrecta\n"
                                         << endl;
                                    pause(SO);
                                    break;
                                }
                            }
                        }
                    }
                    case 3:
                    {
                        c = false;
                        break;
                    }
                    default:
                    {
                        cout << "ERROR: Opcion Incorrecta\n"
                             << endl;
                        pause(SO);
                        break;
                    }
                    }
                }

                break;
            }
            case 2:
            {
                clear(SO);
                if (permiso == 1) // CLIENTE & AGREGAR PRODUCTOS
                {
                    cout << "=============================================" << endl;
                    cout << "===============MENU DE COMPRAS===============" << endl;
                    cout << "=============================================\n"
                         << endl;
                    cout << "Seleccione categoria:" << endl;
                    for (int i = 0; i < categorias.size(); i++)
                    {
                        cout << to_string(i + 1) << " ) " << categorias.at(i).getNombre() << endl;
                    }
                    cout << "\nOPCION: ";
                    int opcate;
                    cin >> opcate;
                    clear(SO);
                    cout << "=============================================" << endl;
                    cout << "===============MENU DE COMPRAS===============" << endl;
                    cout << "=============================================\n"
                         << endl;
                    cout << "ID    NOMBRE DEL PRODUCTO                  STOCK       PRECIO" << endl;
                    string d1, d2, d3, d4;
                    int len;
                    for (int i = 0; i < productos.size(); i++)
                    {
                        len = to_string(productos.at(i).getId_Producto()).length();
                        d1 = to_string(productos.at(i).getId_Producto());
                        if (len < 4)
                        {
                            for (int i = 0; i < 4 - len; i++)
                            {
                                d1 += " ";
                            }
                        }

                        len = productos.at(i).getNombre().length();
                        d2 = productos.at(i).getNombre();
                        if (len < 35)
                        {
                            for (int i = 0; i < 35 - len; i++)
                            {
                                d2 += " ";
                            }
                        }
                        len = aStrPrecision(productos.at(i).getStock(), 2).length();
                        d3 = aStrPrecision(valDouble(productos.at(i).getStock()), 2);
                        if (len < 10)
                        {
                            for (int i = 0; i < 10 - len; i++)
                            {
                                d3 += " ";
                            }
                        }
                        len = aStrPrecision(valDouble(productos.at(i).getPrecio()), 2).length();
                        d4 = aStrPrecision(valDouble(productos.at(i).getPrecio()), 2);
                        if (len < 10)
                        {
                            for (int i = 0; i < 10 - len; i++)
                            {
                                d4 += " ";
                            }
                        }
                        if (opcate - 1 == productos.at(i).getId_Cate())
                        {
                            cout << d1 << "  " << d2 << "  " << d3 << "  " << d4 << endl;
                        }
                    }
                    cout << endl
                         << "Codigo de Producto: ";
                    int codi, cant;
                    cin >> codi;
                    clear(SO);
                    cout << "=============================================" << endl;
                    cout << "===============MENU DE COMPRAS===============" << endl;
                    cout << "=============================================\n"
                         << endl;
                    cout << "ID: " << productos.at(codi).getId_Producto() << endl;
                    cout << "Nombre: " << productos.at(codi).getNombre() << endl;
                    cout << "Descripcion: " << productos.at(codi).getDescripcion() << endl;
                    cout << "Precio: " << productos.at(codi).getPrecio() << endl
                         << endl;
                    cout << "Cantidad: ";
                    cin >> cant;
                    //Validacion stock
                    if (productos.at(codi).getStock() >= cant && productos.at(codi).getStock() != 0)
                    {
                        carrito = true;
                        double prec = productos.at(codi).getPrecio() * cant;
                        cout << endl
                             << endl
                             << "TOTAL: " << prec << endl
                             << endl;

                        productos.at(codi).setStock(productos.at(codi).getStock() - cant);
                        //*********************************************************
                        //         MODIFICACION DEL ARCHIVO DE PRODUCTOS
                        //*********************************************************
                        actualizarProductos(productos);
                        //*********************************************************

                        Factura temp(id_Fact, id_Persona, fechaActual, codi, cant, prec);
                        facturas.push_back(temp);
                        //*********************************************************
                        //        ESCRITURA EN EL ARCHIVO DE LA FALTURA
                        //*********************************************************
                        ofstream archivo;
                        archivo.open("facturas.csv");
                        for (int i = 0; i < facturas.size(); i++)
                        {
                            if (i < facturas.size() - 1)
                            {
                                archivo << facturas.at(i).getId_Factura() << "," << facturas.at(i).getId_Cliente() << "," << facturas.at(i).getFecha_Compra().getDia() << "," << facturas.at(i).getFecha_Compra().getMes() << "," << facturas.at(i).getFecha_Compra().getAno() << "," << facturas.at(i).getId_Producto() << "," << facturas.at(i).getCantidad() << "," << facturas.at(i).getTotal_a_pagar() << endl;
                            }
                            else
                            {
                                archivo << facturas.at(i).getId_Factura() << "," << facturas.at(i).getId_Cliente() << "," << facturas.at(i).getFecha_Compra().getDia() << "," << facturas.at(i).getFecha_Compra().getMes() << "," << facturas.at(i).getFecha_Compra().getAno() << "," << facturas.at(i).getId_Producto() << "," << facturas.at(i).getCantidad() << "," << facturas.at(i).getTotal_a_pagar();
                            }
                        }
                        archivo.close();
                        //*********************************************************
                    }
                    else if (productos.at(codi).getStock() == 0)
                    {
                        cout << "Este producto se ha agotado" << endl
                             << endl;
                    }
                    else
                    {
                        cout << "Cantidad no disponible" << endl
                             << endl;
                    }
                }
                else
                {
                    clear(SO);
                    bool conticli = true;
                    while (conticli)
                    {
                        clear(SO);
                        printTitulo();
                        printCRUDp("Clientes");
                        int opclientes;
                        cout << "\t\t\t\t\tOPCION: ";
                        cin >> opclientes;
                        switch (opclientes)
                        {
                        case 1:
                        {
                            //Consultar
                            clear(SO);
                            cout << "==============================================================================================" << endl;
                            cout << "==================================== CONSULTA DE CLIENTES ====================================" << endl;
                            cout << "==============================================================================================\n"
                                 << endl;
                            cout << "ID    NOMBRE                APELLIDO              INE        EDAD  USUARIO     PASSWORD" << endl;
                            for (int i = 0; i < clientes.size(); i++)
                            {
                                string dat1 = to_string(clientes.at(i).getId_Cliente());
                                string dat2 = clientes.at(i).getNombre();
                                string dat3 = clientes.at(i).getApellido();
                                string dat4 = to_string(clientes.at(i).getIne());
                                string dat5 = to_string(clientes.at(i).getEdad());
                                string dat6 = clientes.at(i).getCuenta().getUsuario();
                                string dat7 = clientes.at(i).getCuenta().getPass();
                                cout << formatStr(dat1, 4) << "  " << formatStr(dat2, 20) << "  " << formatStr(dat3, 20) << "  " << formatStr(dat4, 9) << "  " << formatStr(dat5, 4) << "  " << formatStr(dat6, 10) << "  " << formatStr(dat7, 10) << endl;
                            }
                            cout << endl;
                            pause(SO);
                            break;
                        }
                        case 2:
                        {
                            //Modificar
                            clear(SO);
                            int id_cliente;
                            cout << "==============================================================================================" << endl;
                            cout << "==================================== CONSULTA DE CLIENTES ====================================" << endl;
                            cout << "==============================================================================================\n"
                                 << endl;
                            cout << "ID    NOMBRE                APELLIDO              INE        EDAD  USUARIO     PASSWORD" << endl;
                            for (int i = 0; i < clientes.size(); i++)
                            {
                                string dat1 = to_string(clientes.at(i).getId_Cliente());
                                string dat2 = clientes.at(i).getNombre();
                                string dat3 = clientes.at(i).getApellido();
                                string dat4 = to_string(clientes.at(i).getIne());
                                string dat5 = to_string(clientes.at(i).getEdad());
                                string dat6 = clientes.at(i).getCuenta().getUsuario();
                                string dat7 = clientes.at(i).getCuenta().getPass();
                                cout << formatStr(dat1, 4) << "  " << formatStr(dat2, 20) << "  " << formatStr(dat3, 20) << "  " << formatStr(dat4, 9) << "  " << formatStr(dat5, 4) << "  " << formatStr(dat6, 10) << "  " << formatStr(dat7, 10) << endl;
                            }
                            cout << endl;
                            cout << "ID Cliente: ";
                            cin >> id_cliente;
                            bool modCliecont = true;
                            while (modCliecont)
                            {
                                clear(SO);
                                modfCliente(clientes, id_cliente);
                                int opcModcli;
                                cout << "\t\t\t\t\tOPCION: ";
                                cin >> opcModcli;
                                string nnom, nape, nine, neda, nusr, npss;
                                switch (opcModcli)
                                {
                                case 1:
                                {
                                    clear(SO);
                                    printTitulo();

                                    cout << "ID: " << clientes.at(id_cliente).getId_Cliente() << endl;
                                    cout << "Nombre Actual: " << clientes.at(id_cliente).getNombre() << endl;
                                    nnom = leerStr("Nuevo Nombre: ");

                                    clientes.at(id_cliente).setNombre(nnom);

                                    actualizarClientes(clientes);

                                    pause(SO);
                                    break;
                                }
                                case 2:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_cliente).getId_Cliente() << endl;
                                    cout << "Apellido Actual: " << clientes.at(id_cliente).getApellido() << endl;
                                    nape = leerStr("Nuevo Apellido: ");

                                    clientes.at(id_cliente).setApellido(nape);

                                    actualizarClientes(clientes);

                                    pause(SO);
                                    break;
                                }
                                case 3:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_cliente).getId_Cliente() << endl;
                                    cout << "INE Actual: " << clientes.at(id_cliente).getIne() << endl;
                                    int nine = leerInt("Nuevo INE: ");

                                    clientes.at(id_cliente).setIne(nine);

                                    actualizarClientes(clientes);

                                    pause(SO);
                                    break;
                                }
                                case 4:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_cliente).getId_Cliente() << endl;
                                    cout << "Edad Actual: " << clientes.at(id_cliente).getEdad() << endl;
                                    int neda = leerInt("Nueva Edad: ");

                                    clientes.at(id_cliente).setEdad(neda);

                                    actualizarClientes(clientes);

                                    pause(SO);
                                    break;
                                }
                                case 5:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_cliente).getId_Cliente() << endl;
                                    cout << "Usuario Actual: " << clientes.at(id_cliente).getCuenta().getUsuario() << endl;
                                    nusr = leerStr("Nuevo Usuario: ");

                                    Cuenta tempusr(nusr, clientes.at(id_cliente).getCuenta().getPass(), clientes.at(id_cliente).getCuenta().getPermiso(), clientes.at(id_cliente).getCuenta().getId_Persona());

                                    clientes.at(id_cliente).setCuenta(tempusr);

                                    pause(SO);
                                    break;
                                }
                                case 6:
                                {
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_cliente).getId_Cliente() << endl;
                                    cout << "Password Actual: " << clientes.at(id_cliente).getCuenta().getPass() << endl;
                                    npss = leerStr("Nuevo Password: ");

                                    Cuenta tempps(clientes.at(id_cliente).getCuenta().getUsuario(), npss, clientes.at(id_cliente).getCuenta().getPermiso(), clientes.at(id_cliente).getCuenta().getId_Persona());

                                    clientes.at(id_cliente).setCuenta(tempps);

                                    pause(SO);
                                    break;
                                }
                                case 7:
                                {
                                    modCliecont = false;
                                    break;
                                }
                                default:
                                {
                                    cout << "ERROR: Opcion Incorrecta\n"
                                         << endl;
                                    pause(SO);
                                    break;
                                }
                                }
                            }
                            pause(SO);
                            break;
                        }
                        case 3:
                        {
                            //regresar
                            conticli = false;

                            break;
                        }
                        default:
                        {
                            cout << endl
                                 << "ERROR: Opcion incorrecta." << endl
                                 << endl;
                            pause(SO);
                            break;
                        }
                        }
                    }
                }
                pause(SO);
                break;
            }
            case 3:
            {
                clear(SO);
                if (permiso == 1) // CLIENTE & DETALLE COMPRA
                {
                    if (carrito)
                    {
                        cout << "=================================================================================" << endl;
                        cout << "================================DETALLE DE COMPRA================================" << endl;
                        cout << "=================================================================================" << endl
                             << endl;
                        cout << "ID    NOMBRE                               PRECIO      CANTIDAD    SUB_TOTAL";
                        for (int i = 0; i < facturas.size(); i++)
                        {
                            if (facturas.at(id_Fact).getId_Factura() == facturas.at(i).getId_Factura())
                            {
                                string detId = to_string(facturas.at(i).getId_Factura());
                                string detNom = productos.at(facturas.at(i).getId_Producto()).getNombre();
                                string detPrec = aStrPrecision(productos.at(facturas.at(i).getId_Producto()).getPrecio(), 2);
                                string detCant = aStrPrecision(facturas.at(i).getCantidad(), 2);
                                string detSubTot = aStrPrecision(facturas.at(i).getTotal_a_pagar(), 2);
                                cout << formatStr(detId, 4) << "  " << formatStr(detNom, 35) << "  " << formatStr(detPrec, 10) << "  " << formatStr(detCant, 10) << "  " << formatStr(detSubTot, 14) << endl;
                            }
                        }
                        cout << endl;
                    }
                    else
                    {
                        cout << "No ha agregado productos a su orden" << endl
                             << endl;
                    }
                }
                else
                {
                    if (permiso == 2) // VENDEDOR NUEVA VENTA
                    {
                        cout << "Funcion disponible pronto" << endl; //*************************************************
                    }
                    else // ADMINISTRADOR MODIFICAR EMPLEADOS
                    {
                        cout << "Funcion disponible pronto" << endl; //*************************************************
                    }
                }

                pause(SO);
                break;
            case 4:
            {
                clear(SO);
                if (permiso == 1) // CLIENTE & PAGAR
                {
                    if (carrito)
                    {
                        cout << "========================================================================" << endl;
                        cout << "==============================MENU DE PAGO==============================" << endl;
                        cout << "========================================================================" << endl
                             << endl;
                        cout << "Id Factura: " << facturas.at(id_Fact).getId_Factura() << endl;
                        cout << "     Fecha: ";
                        fechaActual.mostrarFecha();
                        cout << "   Cliente: " << clientes.at(id_Persona).getNombre() << " " << clientes.at(id_Persona).getApellido() << endl;
                        cout << "       INE: " << clientes.at(id_Persona).getIne() << endl;
                        cout << "--------------------------------------------------------------------------" << endl;
                        double totFinal = 0;
                        for (int i = 0; i < facturas.size(); i++)
                        {
                            if (facturas.at(id_Fact).getId_Factura() == facturas.at(i).getId_Factura())
                            {
                                totFinal += facturas.at(i).getTotal_a_pagar();
                            }
                        }
                        cout << "TOTAL A PAGAR: " << totFinal << endl
                             << endl;
                        cout << "¡Gracias por su preferencia!" << endl
                             << endl;
                        pause(SO);
                        id_Fact++;
                        facturas.clear();
                        cargarFacturas(facturas);
                    }
                }
                else // VENDEDOR Y ADMIN & PRODUCTOS
                {
                    bool contiprod = true;
                    while (contiprod)
                    {
                        clear(SO);
                        printTitulo();
                        printCRUDcompleto("Productos");
                        int opprod;
                        cout << "\t\t\t\t\tOPCION: ";
                        cin >> opprod;
                        switch (opprod)
                        {
                        //****************************************************************
                        case 1: // CONSULTAR PRODUCTOS
                        {
                            //Consultar
                            clear(SO);
                            cout << "===============================================================================================" << endl;
                            cout << "==================================== CONSULTA DE PRODUCTOS ====================================" << endl;
                            cout << "===============================================================================================\n"
                                 << endl;
                            cout << "ID    NOMBRE                DESCRIPCION                STOCK         PRECIO        ID_CATEGORIA" << endl;
                            for (int i = 0; i < productos.size(); i++)
                            {
                                string dat1 = to_string(productos.at(i).getId_Producto());
                                string dat2 = productos.at(i).getNombre();
                                string dat3 = productos.at(i).getDescripcion();
                                string dat4 = aStrPrecision(productos.at(i).getStock(), 2);
                                string dat5 = aStrPrecision(productos.at(i).getPrecio(), 2);
                                string dat6 = to_string(productos.at(i).getId_Cate());
                                cout << formatStr(dat1, 4) << "  " << formatStr(dat2, 35) << "  " << formatStr(dat3, 35) << "  " << formatStr(dat4, 12) << "  " << formatStr(dat5, 12) << "  " << formatStr(dat6, 12) << endl;
                            }
                            cout << endl;
                            pause(SO);
                            break;
                        }
                        case 2: // AGREGAR PRODUCTOS
                        {
                            if (permiso == 2)
                            {
                                cout << "No tiene permisos para esta accion." << endl
                                     << endl;
                            }
                            else
                            {
                                //***************************************************************************************
                            }
                        }
                        case 3: //MODIFICAR PRODUCTOS
                        {
                            //Modificar
                            clear(SO);
                            if (permiso == 2)
                            {
                                cout << "No tiene permisos para esta accion." << endl
                                     << endl;
                            }
                            else
                            {
                                int id_producto;
                                cout << "===============================================================================================" << endl;
                                cout << "==================================== CONSULTA DE PRODUCTOS ====================================" << endl;
                                cout << "===============================================================================================\n"
                                     << endl;
                                cout << "ID    NOMBRE                               DESCRIPCION                          STOCK         PRECIO        ID_CATEGORIA" << endl;
                                for (int i = 0; i < productos.size(); i++)
                                {
                                    string dat1 = to_string(productos.at(i).getId_Producto());
                                    string dat2 = productos.at(i).getNombre();
                                    string dat3 = productos.at(i).getDescripcion();
                                    string dat4 = aStrPrecision(productos.at(i).getStock(), 2);
                                    string dat5 = aStrPrecision(productos.at(i).getPrecio(), 2);
                                    string dat6 = to_string(productos.at(i).getId_Cate());
                                    cout << formatStr(dat1, 4) << "  " << formatStr(dat2, 35) << "  " << formatStr(dat3, 35) << "  " << formatStr(dat4, 12) << "  " << formatStr(dat5, 12) << "  " << formatStr(dat6, 12) << endl;
                                }
                                cout << endl;
                                cout << "ID Producto: ";
                                cin >> id_producto;
                                bool modProdcont = true;
                                while (modProdcont)
                                {
                                    clear(SO);
                                    modfProd(productos, id_producto);
                                    int opcModprod;
                                    cout << "\t\t\t\t\tOPCION: ";
                                    cin >> opcModprod;
                                    string nnom, nape, nine, neda, nusr, npss;
                                    switch (opcModprod)
                                    {
                                    case 1:
                                    {
                                        char nom[40];
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << productos.at(id_producto).getId_Producto() << endl;
                                        cout << "Nombre Actual: " << productos.at(id_producto).getNombre() << endl;
                                        cout << "Nuevo Nombre: ";
                                        cin.getline(nom, 40);
                                        nnom = charToString(nom);

                                        //Escribir cambios en csv

                                        cout << nnom << endl;
                                        pause(SO);
                                        break;
                                    }
                                    case 2:
                                    {
                                        char desc[50];
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << productos.at(id_producto).getId_Producto() << endl;
                                        cout << "Descripcion Actual: " << productos.at(id_producto).getDescripcion() << endl;
                                        cout << "Nueva Descripcion: ";
                                        cin.getline(desc, 50);
                                        string ndesc = charToString(desc);

                                        //Escribir cambios en csv

                                        cout << ndesc << endl;
                                        pause(SO);
                                        break;
                                    }
                                    case 3:
                                    {
                                        char stock[15];
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << productos.at(id_producto).getId_Producto() << endl;
                                        cout << "Stock Actual: " << productos.at(id_producto).getStock() << endl;
                                        cout << "Nuevo Stock: ";
                                        cin.getline(stock, 15);
                                        string nstock = charToString(stock);

                                        //Escribir cambios en csv

                                        cout << nstock << endl;
                                        pause(SO);
                                        break;
                                    }
                                    case 4:
                                    {
                                        char prc[10];
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << productos.at(id_producto).getId_Producto() << endl;
                                        cout << "Precio Actual: " << productos.at(id_producto).getPrecio() << endl;
                                        cout << "Nuevo Precio: ";
                                        cin.getline(prc, 10);
                                        string nprc = charToString(prc);

                                        //Escribir cambios en csv

                                        cout << nprc << endl;
                                        pause(SO);
                                        break;
                                    }
                                    case 5:
                                    {
                                        clear(SO);
                                        int id_cat;
                                        cout << "ID: " << productos.at(id_producto).getId_Producto() << endl;
                                        cout << "Categoria Actual: " << categorias.at(productos.at(id_producto).getId_Cate()).getNombre() << endl;
                                        cout << "Nuevo Categoria: " << endl
                                             << endl;
                                        cout << "==========================================" << endl;
                                        cout << "================CATEGORIAS================" << endl;
                                        cout << "==========================================\n"
                                             << endl;
                                        cout << "ID    NOMBRE" << endl;
                                        for (int i = 0; i < categorias.size(); i++)
                                        {
                                            string id_c = to_string(categorias.at(i).getId_Categoria());
                                            string nom_c = categorias.at(i).getNombre();
                                            cout << formatStr(id_c, 4) << "  " << formatStr(nom_c, 20) << endl;
                                        }
                                        cout << endl;
                                        cout << "ID Categoria: ";
                                        cin >> id_cat;

                                        //Escribir cambios en csv

                                        cout << id_cat << endl;
                                        pause(SO);
                                        break;
                                    }
                                    case 6:
                                    {
                                        modProdcont = false;
                                        break;
                                    }
                                    default:
                                    {
                                        cout << "ERROR: Opcion Incorrecta\n"
                                             << endl;
                                        pause(SO);
                                        break;
                                    }
                                    }
                                }
                            }
                            pause(SO);
                            break;
                        }
                        case 4: // ELIMINAR PRODUCTOS

                        case 5: //regresar

                            contiprod = false;

                            break;

                        default:
                        {
                            cout << endl
                                 << "ERROR: Opcion incorrecta." << endl
                                 << endl;
                            pause(SO);
                            break;
                        }
                            //****************************************************************
                        }
                        //
                    }
                }
                pause(SO);
                break;
            }
            case 5:
            {
                cont = false;
            }
            default:
            {
                break;
            }
            }
                if (permiso == 1)
                {
                }
                else if (permiso == 2)
                {
                }
                else
                {
                }
            }
        }

        return 0;
    }
}
