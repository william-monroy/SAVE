#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <fstream>

#ifdef _WIN64
    #include <windows.h>
#else
    #include <unistd.h>
#endif


#include "Util.h"
#include "Img.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Categoria.h"
#include "Departamento.h"
#include "Factura.h"
#include "Producto.h"

using namespace std;

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
    cout << "Cargando cuentas..." << endl;
    sleepcp(1000);
    cout << "OK..." << endl;
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
    string nom,ape,edad,ine,id_Em,id_Dp,carg,usr,pas,per,id;
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
        getline(archivo, pas ,',');
        getline(archivo, per ,',');
        getline(archivo, id);
        int edadi = atoi(edad.c_str());
        int inei = atoi(ine.c_str());
        int id_Emi = atoi(id_Em.c_str());
        int id_Dpi = atoi(id_Dp.c_str());
        int peri= atoi(per.c_str());
        int idi = atoi(id.c_str());
        Cuenta tempCuenta(usr,pas,peri,idi);
        Empleado temp(nom,ape,edadi,inei,id_Emi,id_Dpi,carg,tempCuenta);
        empleados.push_back(temp);
    }
    cout << "Cargando Empleados..." << endl;
    sleepcp(1000);
    cout << "OK..." << endl;
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
    string nom,ape,edad,ine,id_Cli,usr,pas,per,id;
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
        getline(archivo, pas ,',');
        getline(archivo, per ,',');
        getline(archivo, id);
        int edadi = atoi(edad.c_str());
        int inei = atoi(ine.c_str());
        int id_Clii = atoi(id_Cli.c_str());
        int peri= atoi(per.c_str());
        int idi = atoi(id.c_str());
        Cuenta tempCuenta(usr,pas,peri,idi);
        Cliente temp(nom,ape,edadi,inei,id_Clii,tempCuenta);
        clientes.push_back(temp);
    }
    cout << "Cargando clientes..." << endl;
    sleepcp(1000);
    cout << "OK..." << endl;
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
    string id,nom;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, id, ',');
        getline(archivo, nom);
        int idi = atoi(id.c_str());
        Categoria temp(idi,nom);
        categorias.push_back(temp);
    }
    cout << "Cargando categorias..." << endl;
    sleepcp(1000);
    cout << "OK..." << endl;
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
    string id,nom;
    while (!archivo.eof())
    {
        string linea;
        linea.replace(linea.length(), 1, "");
        getline(archivo, id, ',');
        getline(archivo, nom);
        int idi = atoi(id.c_str());
        Departamento temp(idi,nom);
        departamentos.push_back(temp);
    }
    cout << "Cargando departamentos..." << endl;
    sleepcp(1000);
    cout << "OK..." << endl;
    /*
    for (int i = 0; i < departamentos.size(); i++)
    {
        cout << "\nDepartamento " << i + 1 << endl;
        cout<<"ID: "<<departamentos.at(i).getId_Dpto()<<endl;
        cout<<"Nombre: "<<departamentos.at(i).getNombre()<<endl;
    }
    */
}


bool login(string &user, string &pass, vector<Cuenta> cuentas)
{
    bool cont = true;

    printLogin(user, pass);
    bool encontrado = false;
    for (int i = 0; i < cuentas.size(); i++)
    {   
        if(cuentas.at(i).getUsuario() == user){
            if(cuentas.at(i).getPass() == pass){
                encontrado=true;
                i=cuentas.size();
                cout << "Datos correctos"<<endl;
                return true;
            }else{
                cout << "Contraseña incorrecta"<<endl;
                return false;
            }
        }else if(i==cuentas.size()-1){
            cout<<"La cuenta no existe"<<endl;
            return false;
        }
    }
}

int main()
{
    system("color 2");
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
    cargarCuentas(cuentas);
    cargarEmpleados(empleados);
    cargarCategorias(categorias);
    cargarClientes(clientes);
    cargarDepartamentos(departamentos);


    string usuario, pass;

    if(login(usuario, pass, cuentas)){

        //CODIGO DEL PROGRAMA
        clear(SO);
        system("color 6");
        printTitulo();
        


    }
    

    return 0;
}
