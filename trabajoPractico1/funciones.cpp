#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
#include "funciones.h"
#include "usuario.h"
#include "entrenamiento.h"



void validaOpcion(char o[], bool *f){
int opcion=atoi(o); //Aca paso la cadena a numeros
        switch (opcion){
        case 1:{
            menuUsuarios();//Accede al submenu de usuarios.
        }
            break;
        case 2:{
            menuEntrenamiento();//Accede al submenu entrenamiento
        }
            break;
        case 3:{
            //menuReportes();

        }
            break;
        case 4:menuConfiguracion();
            break;
        case 5:cout<<"               Gracias por acceder a LARA" << endl;
                 cout<<endl;
                 cout<<"                ¡Te esperamos pronto!"     << endl;
                 *f=true;
            break;
        default:
            cout <<"-----------------------------------------------------------------------------------"<< endl;
            cout <<"         La opción ingresada no es correcta. Porfavor ingrese una opción válida    "<< endl;
            cout <<"-----------------------------------------------------------------------------------"<< endl;
            system("pause");
            break;
        }
}

//Submenu Usuarios
void menuUsuarios(){
    bool volver=false;
    char opcion[1];
    int opcionElegida;
    while(!volver){
            system("cls");
            cout <<endl;
            cout << "           USUARIOS         "<< endl;
            cout << "-----------------------------------------------"<< endl;
            cout <<endl;
            cout <<"  1. Nuevo usuario"<< endl;
            cout <<"  2. Modificar Usuario"<< endl;
            cout <<"  3. Listar usuario por ID"<< endl;
            cout <<"  4. Listar todos los usuarios"<< endl;
            cout <<"  5. Eliminar usuario" << endl;
            cout <<"  6. Volver al menú principal" << endl;
            cout <<endl;
            cout <<"Seleccione una opción: ";
            cin >> opcion;
            opcionElegida=atoi(opcion);
            system("cls");
                switch (opcionElegida){
            case 1:{
                Usuario reg; ///Creo un registro
                reg= cargar_usuario(); ///Cargo un registro con datos de usuario nuevo
                if (reg.nac.dia > 0){
                    if (guardar_usuario(reg)){
                    cout<<endl<<"¡El usuario fue registrado exitosamente!"<<endl<<endl;
                    mostrar_usuario(reg);
                    }
                    else{
                    cout<<endl<<"¡El usuario no pudo ser registrado!"<<endl<<endl;
                    }
                }
                system("pause");
            }
                break;
            case 2:
                modificar_usuario();
                break;
            case 3:
                listar_usuarios_x_id();
                system("pause");
                break;
            case 4:
                listar_usuarios();
                break;
            case 5:
                eliminar_usuario();
                break;
            case 6:volver=true;
                break;
            default:
                cout <<"-----------------------------------------------------------------------------------"<< endl;
                cout <<"         La opción ingresada no es correcta. Porfavor ingrese una opción válida    "<< endl;
                cout <<"-----------------------------------------------------------------------------------"<< endl;
                system("pause");
                break;
            }
    }
}

//Submenu Configuracion. Le agregué la funcion de setear la informacion.
void menuConfiguracion(){
bool volver=false;
char opcion[1];
int opcionElegida;
while(!volver){
        system("cls");
        cout <<endl;
        cout << "           CONFIGURACION         "<< endl;
        cout << "-----------------------------------------------"<< endl;
        cout <<endl;
        cout <<"  1. Eliminar TODO"<< endl;
        cout <<"  2. Volver a Menú principal" << endl;
        cout <<"Seleccione una opción: ";
        cin >> opcion;
        opcionElegida=atoi(opcion);
        system("cls");
            switch (opcionElegida){
        case 1:{
            cout << "¿Seguro que desea eliminar TODO?: ";
            cin >> opcion;
            opcionSetearTodo(opcion);
        }
            break;
        case 2:
            volver=true;
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout <<"-----------------------------------------------------------------------------------"<< endl;
            cout <<"         La opción ingresada no es correcta. Porfavor ingrese una opción válida    "<< endl;
            cout <<"-----------------------------------------------------------------------------------"<< endl;
            system("pause");
            break;
        }
    }

}
//Seteo de archivo de usuarios. No elimina el archivo, solo lo deja en 0. En realidad va en usuarios.cpp
void opcionSetearTodo(char *o){
    if (*o == 'S'){
    //fopen(archivoUsuarios,"wb");
    cout << "Eliminando..." << endl;    //Aca estaba jugando un poco jajaja
    system("pause");
    cout << "Datos eliminados con exitos" << endl;

    }else{
        system("cls");
        cout << "Se cancela seteo de información" << endl;
        system("pause");
        }

}

//Armo la funcion gotoxy, parece que este compilador no lo trae por defecto.
/**
void gotoxy(int x, int y){
COORD coordenada;

coordenada.X = x;
coordenada.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenada);
}*/

//Prototipo de menu con fechas direccionables. Muy verde todavia
/*void menu_con_flecha(){
int tecla;
int opcionSeleccionada=0;
gotoxy(1,6 + opcionSeleccionada);

cout << "--> ";

tecla = getch();
} **/

//Submenu Entrenamiento
void menuEntrenamiento(){
    bool volver=false;
    char opcion[1];
    int opcionElegida;
    while(!volver){
             system("cls");
            cout <<endl;
            cout << "           ENTRENAMIENTO         "<< endl;
            cout << "-----------------------------------------------"<< endl;
            cout <<endl;
            cout <<"  1. Nuevo entrenamiento"<< endl;
            cout <<"  2. Modificar entrenamiento"<< endl;
            cout <<"  3. Listar entrenamiento por ID"<< endl;
            cout <<"  4. Listar entrenamiento por ID Usuario"<< endl;
            cout <<"  5. Listar todos los entrenamientos" << endl;
            cout <<"  6. Volver al menú principal" << endl;
            cout <<endl;
            cout <<"Seleccione una opción: ";
            cin >> opcion;
            opcionElegida=atoi(opcion);
            system("cls");
                switch (opcionElegida){
            case 1:{
                Entrenamiento reg; ///Creo un registro
                reg=cargar_entrenamiento();

                if (guardar_entrenamiento(reg)){
                    cout<<"El entrenamiento se pudo guardar con exito"<<endl;
                }
                else{
                    cout<<"El entrenamiento no se pudo guardar."<<endl;
                }
                system("pause");
            }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:{
                listar_entrenamientos();
                system("pause");
            }
                break;
            case 6:volver=true;
                break;
            default:
                cout <<"-----------------------------------------------------------------------------------"<< endl;
                cout <<"         La opción ingresada no es correcta. Porfavor ingrese una opción válida    "<< endl;
                cout <<"-----------------------------------------------------------------------------------"<< endl;
                system("pause");
                break;
            }
    }
}
