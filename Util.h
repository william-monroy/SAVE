#include <iostream>
#include <stdlib.h>
#include <string>

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
/*
void color(int num){
    string cmd = to_string(num);
    char const *cmd2 = cmd.c_str();
    system(strcat("color ",cmd2));   
}  */
