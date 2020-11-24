

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
printf("█──█    █████████───█───█               2) Agregar Producto\n");
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

void printMainDatos(){
printf("████            █████████               \n");
printf("█──█            █───█───█               Mis Datos\n");
printf("█──█    █████████───█───█               \n");
printf("█──█    █───█───█───█───██████████      1) Consultar\n");
printf("█──█    █───█───█───█───█──█──█──█      2) Modificar\n");
printf("█──█    █───█───█───█───█──█──█──█      3) Regresar\n");
printf("█──█    █───█───█───█───█──█──█──█      \n");
}

void printMisDatos(int permiso, vector<Empleado> empleados, vector<Cliente> clientes,vector<Departamento> departamentos, int id_persona){
if(permiso==1){
printf("b.            DATOS\n");
printf("88b           \n");
printf("888b.         ");
cout<<"ID: "<<clientes.at(id_persona).getId_Cliente()<<endl;
printf("88888b        ");
cout<<"Nombre: "<<clientes.at(id_persona).getNombre()<<endl;
printf("888888b.      ");
cout<<"Apellido: "<<clientes.at(id_persona).getApellido()<<endl;
printf("8888P\"        ");
cout<<"INE: "<<clientes.at(id_persona).getIne()<<endl;
printf("P\" `8.        ");
cout<<"Edad: "<<clientes.at(id_persona).getEdad()<<endl;
printf("    `8.       ");
cout<<"Usuario: "<<clientes.at(id_persona).getCuenta().getUsuario()<<endl;
printf("     `8       ");
cout<<"Contrasena: "<<clientes.at(id_persona).getCuenta().getPass()<<endl;
}else{
cout << "DATOS\n"<<endl;
printf("b.            ");
cout << "ID: "<< empleados.at(id_persona).getId_Empleado()<<endl;
printf("88b           ");
cout<<"Nombre: "<<empleados.at(id_persona).getNombre()<<endl;
printf("888b.         ");
cout<<"Apellido: "<<empleados.at(id_persona).getApellido()<<endl;
printf("88888b        ");
cout<<"INE: "<<empleados.at(id_persona).getIne()<<endl;
printf("888888b.      ");
cout<<"Edad: "<<empleados.at(id_persona).getEdad()<<endl;
printf("8888P\"        ");
cout<<"Departamento: "<<departamentos.at(empleados.at(id_persona).getId_Dpto()).getNombre()<<endl;
printf("P\" `8.        ");
cout<<"Cargo: "<<empleados.at(id_persona).getCargo()<<endl;
printf("    `8.       ");
cout<<"Usuario: "<<empleados.at(id_persona).getCuenta().getUsuario()<<endl;
printf("     `8       ");
cout<<"Contrasena: "<<empleados.at(id_persona).getCuenta().getPass()<<endl;
}
}

void printCRUD(int permiso, vector<Empleado> empleados, vector<Cliente> clientes, int id_persona){
if(permiso==1){
printf("b.            DATOS\n");
printf("88b           \n");
printf("888b.         ");
cout<<"ID: "<<clientes.at(id_persona).getId_Cliente()<<endl;
printf("88888b        ");
cout<<"1) Modificar Nombre"<<endl;
printf("888888b.      ");
cout<<"2) Modificar Apellido"<<endl;
printf("8888P\"        ");
cout<<"3) Modificar INE"<<endl;
printf("P\" `8.        ");
cout<<"4) Modificar Edad"<<endl;
printf("    `8.       ");
cout<<"5) Modificar Usuario"<<endl;
printf("     `8       ");
cout<<"6) Modificar Contrasena"<<endl;
cout<<"\t\t\t\t\t7) Regresar";
}else{
cout << "DATOS\n"<<endl;
printf("b.            ");
cout << "ID: "<< empleados.at(id_persona).getId_Empleado()<<endl;
printf("88b           ");
cout<<"1) Modificar Nombre"<<endl;
printf("888b.         ");
cout<<"2) Modificar Apellido"<<endl;
printf("88888b        ");
cout<<"3) Modificar INE"<<endl;
printf("888888b.      ");
cout<<"4) Modificar Edad"<<endl;
printf("8888P\"        ");
cout<<"5) Modificar Departamento: "<<endl;
printf("P\" `8.        ");
cout<<"6) Modificar Cargo: "<<endl;
printf("    `8.       ");
cout<<"7) Modificar Usuario"<<endl;
printf("     `8       ");
cout<<"8) Modificar Contrasena"<<endl;
cout<<"\t\t\t\t\t9) Regresar";
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