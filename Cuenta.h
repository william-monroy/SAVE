#include <iostream>

using namespace std;

class Cuenta
{
private:
    string usuario;
    string pass;
    int permiso;
    int id_Persona;

public:
    Cuenta();
    Cuenta(string user, string pass, int perm, int id_Pers);
    string getUsuario();
    void setUsuario(string usuario);
    string getPass();
    void setPass(string pass);
    int getPermiso();
    void setPermiso(int permiso);
    int getId_Persona();
    void setId_Persona(int id_Persona);
};

Cuenta::Cuenta()
{
    this->usuario = "";
    this->pass = "";
    this->permiso = 0;
    this->id_Persona = 0;
}

Cuenta::Cuenta(string user, string pass, int perm, int id_Pers)
{
    this->usuario = user;
    this->pass = pass;
    this->permiso = perm;
    this->id_Persona = id_Pers;
}

string Cuenta::getUsuario()
{
    return this->usuario;
}
void Cuenta::setUsuario(string usuario)
{
    this->usuario = usuario;
}

string Cuenta::getPass()
{
    return this->pass;
}
void Cuenta::setPass(string pass)
{
    this->pass = pass;
}

int Cuenta::getPermiso()
{
    return this->permiso;
}
void Cuenta::setPermiso(int permiso)
{
    this->permiso = permiso;
}

int Cuenta::getId_Persona()
{
    return this->id_Persona;
}
void Cuenta::setId_Persona(int id_Persona)
{
    this->id_Persona = id_Persona;
}
