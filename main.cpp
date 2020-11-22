#include <iostream>
#include <stdlib.h> 

#include "Util.h"

using namespace std;



int main() {

    string SO = "";

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


    pause(SO);
    clear(SO);




    return 0;
}



