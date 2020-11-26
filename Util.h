#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

void clear(string SO)
{
    if (SO == "Windows")
    {
        system("cls");
    }
    else
    {
        system("clear");
    }
}

void pause(string SO)
{
    if (SO == "Windows")
    {
        system("pause");
    }
    else
    {
        cout << "Presione enter para continuar...";
        string temp;
        cin >> temp;
    }
}

void color(int num)
{
    string cmd = "color " + to_string(num);
    char const *cmd2 = cmd.c_str();
    system(cmd2);
}

double valDouble(double num)
{
    num *= 10;
    ceil(num);
    num /= 10;
    return num;
}

string formatStr(string palabra, int maxSize)
{
    int len = palabra.length();
    string salida = palabra;
    if (len < maxSize)
    {
        for (int i = 0; i < maxSize - len; i++)
        {
            salida += " ";
        }
    }
    return salida;
}

template <typename T>
string aStrPrecision(const T a_value, const int n = 6)
{
    ostringstream out;
    out.precision(n);
    out << fixed << a_value;
    return out.str();
}

string leerStr(string txt)
{
    string n;
    cout << txt;
    cin.ignore();
    getline(cin, n, '\n');
    return n;
}

int leerInt(string txt)
{
    int n;
    cout << txt;
    cin>>n;
    return n;
}