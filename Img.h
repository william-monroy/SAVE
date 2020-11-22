#include <iostream>
using namespace std;
void printTitulo(){
    
    printf("\t\t\t\t\t███████╗ █████╗ ██╗   ██╗███████╗\n");
    printf("\t\t\t\t\t██╔════╝██╔══██╗██║   ██║██╔════╝\n");
    printf("\t\t\t\t\t███████╗███████║██║   ██║█████╗\n"); 
    printf("\t\t\t\t\t╚════██║██╔══██║╚██╗ ██╔╝██╔══╝\n"); 
    printf("\t\t\t\t\t███████║██║  ██║ ╚████╔╝ ███████╗\n");
    printf("\t\t\t\t\t╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝\n");
    printf("\t\t\t\tSistema de Administracion de Ventas Electronicas\n\n");
 
}

void printMain(){

printf("████            █████████               \n");
printf("█──█            █───█───█               1) \n");
printf("█──█    █████████───█───█               2) \n");
printf("█──█    █───█───█───█───██████████      3) \n");
printf("█──█    █───█───█───█───█──█──█──█      4) \n");
printf("█──█    █───█───█───█───█──█──█──█      5) Salir\n");
printf("█──█    █───█───█───█───█──█──█──█      \n");

}

void printLogin(string &user, string &pass){

printf("████            █████████               \n");
printf("█──█            █───█───█               LOGIN\n");
printf("█──█    █████████───█───█               \n");
printf("█──█    █───█───█───█───██████████      Usuario: ");
cin>>user;
printf("█──█    █───█───█───█───█──█──█──█      Contraseña: ");
cin>>pass;
printf("█──█    █───█───█───█───█──█──█──█      \n");
printf("█──█    █───█───█───█───█──█──█──█      \n");

}