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
    sleepcp(500);
    clear(SO);
    printTitulo();

    string usuario, pass, nombre;
    int permiso, id_Persona;

    if (login(usuario, pass, cuentas, permiso, id_Persona))
    {

        int opcion;
        sleepcp(2500);
        //CODIGO DEL PROGRAMA
        clear(SO);
        system("color 6");
        printTitulo();
        nombre = getNombreUsr(permiso, id_Persona, empleados, clientes);
        printBienvenida(nombre);
        sleepcp(2500);
        bool cont = true;
        while (cont)
        {
            clear(SO);
            system("color 3");
            printTitulo();
            printMain(permiso);
            cout << "\t\t\t\t\tOPCION: ";
            cin >> opcion;
            switch (opcion)
            {
            case 1:
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
                            if (permiso == 1)
                            {
                                string nnom, nape, nine, neda, nusr, npss;
                                switch (op)
                                {
                                case 1:
                                    char nom[40];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Nombre Actual: " << clientes.at(id_Persona).getNombre() << endl;
                                    cout << "Nuevo Nombre: ";
                                    cin.getline(nom, 40);
                                    nnom = charToString(nom);

                                    //Escribir cambios en csv

                                    cout << nnom;
                                    pause(SO);
                                    break;
                                case 2:
                                    char ape[50];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Apellido Actual: " << clientes.at(id_Persona).getApellido() << endl;
                                    cout << "Nuevo Apellido: ";
                                    cin.getline(ape, 50);
                                    nape = charToString(ape);

                                    //Escribir cambios en csv

                                    cout << ape;
                                    pause(SO);
                                    break;
                                case 3:
                                    char ine[15];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "INE Actual: " << clientes.at(id_Persona).getIne() << endl;
                                    cout << "Nuevo INE: ";
                                    cin.getline(ine, 15);
                                    nine = charToString(ine);

                                    //Escribir cambios en csv

                                    cout << nine;
                                    pause(SO);
                                    break;
                                case 4:
                                    char eda[3];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Edad Actual: " << clientes.at(id_Persona).getEdad() << endl;
                                    cout << "Nuevo Edad: ";
                                    cin.getline(eda, 3);
                                    neda = charToString(eda);

                                    //Escribir cambios en csv

                                    cout << neda;
                                    pause(SO);
                                    break;
                                case 5:
                                    char usr[15];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Usuario Actual: " << clientes.at(id_Persona).getCuenta().getUsuario() << endl;
                                    cout << "Nuevo Usuario: ";
                                    cin.getline(usr, 10);
                                    nusr = charToString(usr);

                                    //Escribir cambios en csv

                                    cout << nusr;
                                    pause(SO);
                                    break;
                                case 6:
                                    char pss[15];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << clientes.at(id_Persona).getId_Cliente() << endl;
                                    cout << "Password Actual: " << clientes.at(id_Persona).getCuenta().getPass() << endl;
                                    cout << "Nuevo Password: ";
                                    cin.getline(pss, 15);
                                    npss = charToString(pss);

                                    //Escribir cambios en csv

                                    cout << npss;
                                    pause(SO);
                                    break;
                                case 7:
                                    co = false;
                                default:
                                    cout << "ERROR: Opcion Incorrecta\n"
                                         << endl;
                                    pause(SO);
                                    break;
                                }
                            }
                            else
                            {
                                string nnom, nape, nine, neda, ndpt, ncrg, nusr, npss;
                                switch (op)
                                {
                                case 1:
                                    char nom[40];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << empleados.at(id_Persona).getId_Empleado() << endl;
                                    cout << "Nombre Actual: " << empleados.at(id_Persona).getNombre() << endl;
                                    cout << "Nuevo Nombre: ";
                                    cin.getline(nom, 40);
                                    nnom = charToString(nom);

                                    //Escribir cambios en csv

                                    cout << nnom;
                                    pause(SO);
                                    break;
                                case 2:
                                    char ape[50];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                    cout << "Apellido Actual: " << empleados.at(id_Persona).getApellido() << endl;
                                    cout << "Nuevo Apellido: ";
                                    cin.getline(ape, 50);
                                    nape = charToString(ape);

                                    //Escribir cambios en csv

                                    cout << ape;
                                    pause(SO);
                                    break;
                                case 3:
                                    char ine[15];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                    cout << "INE Actual: " << empleados.at(id_Persona).getIne() << endl;
                                    cout << "Nuevo INE: ";
                                    cin.getline(ine, 15);
                                    nine = charToString(ine);

                                    //Escribir cambios en csv

                                    cout << nine;
                                    pause(SO);
                                    break;
                                case 4:
                                    char eda[3];
                                    clear(SO);
                                    printTitulo();
                                    cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                    cout << "Edad Actual: " << empleados.at(id_Persona).getEdad() << endl;
                                    cout << "Nuevo Edad: ";
                                    cin.getline(eda, 3);
                                    neda = charToString(eda);

                                    //Escribir cambios en csv

                                    cout << neda;
                                    pause(SO);
                                    break;

                                case 5:
                                    if (permiso == 3)
                                    {
                                        char dpt[3];
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                        cout << "Departamento Actual: " << empleados.at(id_Persona).getId_Dpto() << endl;
                                        cout << "Nuevo Departamento: ";
                                        cin.getline(dpt, 3);
                                        ndpt = charToString(dpt);

                                        //Escribir cambios en csv

                                        cout << ndpt;
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
                                        char crg[20];
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                        cout << "Cargo Actual: " << empleados.at(id_Persona).getCargo() << endl;
                                        cout << "Nuevo Cargo: ";
                                        cin.getline(crg, 20);
                                        ncrg = charToString(crg);

                                        //Escribir cambios en csv

                                        cout << ncrg;
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
                                        char usr[15];
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                        cout << "Usuario Actual: " << empleados.at(id_Persona).getCuenta().getUsuario() << endl;
                                        cout << "Nuevo Usuario: ";
                                        cin.getline(usr, 10);
                                        nusr = charToString(usr);

                                        //Escribir cambios en csv

                                        cout << nusr;
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
                                        char pss[15];
                                        clear(SO);
                                        printTitulo();
                                        cout << "ID: " << empleados.at(id_Persona).getId_Empleado();
                                        cout << "Password Actual: " << empleados.at(id_Persona).getCuenta().getPass() << endl;
                                        cout << "Nuevo Password: ";
                                        cin.getline(pss, 15);
                                        npss = charToString(pss);

                                        //Escribir cambios en csv

                                        cout << npss;
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
                if(permiso==1){

                }else if(permiso==2){

                }else{

                }
                pause(SO);
                break;
            }
            case 3:
            {
                clear(SO);

                pause(SO);
                break;
            }
            case 4:
            {
                clear(SO);

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
