#include <iostream>
#include <stdlib.h> 
#include <Windows.h>
#include <vector>

#include "Util.h"
#include "Img.h"
#include "Cliente.h"
#include "Empleado.h"

using namespace std;



int main() {
    system("color 2");
    string SO = "";
    SetConsoleOutputCP(CP_UTF8);
    #if defined(_WIN64)
        cout << "Estoy en Windows de 64 bits.\n" << endl;
        SO = "Windows";
    #elif defined(__linux__)
        cout << "Estoy en Linux." << endl;
        SO = "Linux";
    #elif defined(__MACH__)
        cout << "Estoy en Mac." << endl;
        SO = "Mac";
    #endif
    system("color 2");
    printTitulo();
    printEmpresa();
    
    
















    return 0;
}



