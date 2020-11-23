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

void printMain(int permiso){
if (permiso==1){
printf("████            █████████               \n");
printf("█──█            █───█───█               1) Mis Datos\n");
printf("█──█    █████████───█───█               2) Lista de Productos\n");
printf("█──█    █───█───█───█───██████████      3) Detalle de Compra\n");
printf("█──█    █───█───█───█───█──█──█──█      4) Pagar\n");
printf("█──█    █───█───█───█───█──█──█──█      5) Salir\n");
printf("█──█    █───█───█───█───█──█──█──█      \n");
} else if(permiso==2){
printf("████            █████████               \n");
printf("█──█            █───█───█               1) Mis Datos\n");
printf("█──█    █████████───█───█               2) Clientes\n");
printf("█──█    █───█───█───█───██████████      3) Productos\n");
printf("█──█    █───█───█───█───█──█──█──█      4) Nueva Venta\n");
printf("█──█    █───█───█───█───█──█──█──█      5) Salir\n");
printf("█──█    █───█───█───█───█──█──█──█      \n");
}else{
printf("████            █████████               \n");
printf("█──█            █───█───█               1) Mis Datos\n");
printf("█──█    █████████───█───█               2) Clientes\n");
printf("█──█    █───█───█───█───██████████      3) Empleados\n");
printf("█──█    █───█───█───█───█──█──█──█      4) Productos\n");
printf("█──█    █───█───█───█───█──█──█──█      5) Salir\n");
printf("█──█    █───█───█───█───█──█──█──█      \n");
}
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

void printBienvenida(string nom){

printf("████            █████████               \n");
printf("█──█            █───█───█               \n");
printf("█──█    █████████───█───█               BIENVENIDO!!!\n");
printf("█──█    █───█───█───█───██████████      ");
cout<<nom<<endl;
printf("█──█    █───█───█───█───█──█──█──█      \n");
printf("█──█    █───█───█───█───█──█──█──█      \n");
printf("█──█    █───█───█───█───█──█──█──█      \n");

}