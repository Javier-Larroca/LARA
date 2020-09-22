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
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

//Menu principal
void menuPrincipal(){
bool finDePrograma=false;
char tecla;
const char *flecha="=>";
int pos=4;
    while(!finDePrograma){
        hidecursor();
        gotoxy(1,1);
        cout << "           MENU PRINCIPAL         "<< endl;
        cout << "-----------------------------------------------"<< endl;
        cout <<endl;
        gotoxy(1,4);
        cout <<"  1. Usuarios"<< endl;
        cout <<"  2. Entrenamientos"<< endl;
        cout <<"  3. Reportes"<< endl;
        cout <<"  4. Configuración"<< endl;
        cout <<"  5. Salir del programa" << endl;
        gotoxy(1,pos);
        cout <<flecha;
        cout <<endl;
        tecla=getch();
        validaTecla(tecla, &finDePrograma, &pos, 1);
    }
}

//Valida la tecla y evalua que movimiento tiene que realizar, si se selecciona ENTER entra en un switch.
void validaTecla(char t, bool *f, int *p, int m){
int aux=*p;
if (t==72){ //TECLA ARRIBA
    switch(aux){
        case 4:
            if(m==2 || m==3){ //Si le pasamos 2(Menu Usuarios) o 3(Menu Entrenamiento) le suma una posición.
            aux=9;
            }
            if (m==4 || m==5){ //Si le pasamos 4(Menu Reportes) o 5(Menu Configuracion) reduce las posiciones.
            aux=6;
            }else{
            aux=8;
            }
            break;
        case 5:
            aux=4;
            break;
        case 6:
            aux=5;
            break;
        case 7:
            aux=6;
            break;
        case 8:
            aux=7;
            break;
        case 9:
            aux=8;
            break;
    }
}
if(t==80){ //TECLA ABAJO
    switch(aux){
        case 4:aux=5;
            break;
        case 5:aux=6;
            break;
        case 6:
            if (m==4 || m==5){ //Si es 4(Menu Reportes) o 5(Menu configuracion), al tener 2 opciones vuelve al comienzo.
                aux=4;
            }else{
                aux=7;
            }
            break;
        case 7:aux=8;
            break;
        case 8:
            if(m==2 || m==3){ //Si le pasamos 2(Menu Usuarios) o 3(Menu Entrenamiento) le suma una posición.
            aux=9;
            }else{
            aux=4;
            }
            break;
        case 9:aux=4;
            break;
    }
}
if (t==13){ //ENTER. Accede a las opciones de los diferentes menus
     if(m==1){ //Accede a las opciones del MENU PRINCIPAL
     switch (aux){
        case 4:{
            menuUsuarios();//Accede al submenu de usuarios.
        }
            break;
        case 5:{
            menuEntrenamiento();//Accede al submenu entrenamiento
        }
            break;
        case 6:
            break;
        case 7:menuConfiguracion();
            break;
        case 8: system("cls");
                cout<<"               Gracias por acceder a LARA" << endl;
                 cout<<endl;
                 cout<<"                ¡Te esperamos pronto!"     << endl;
                 *f=true;
            break;
        }
     }
    if (m==2){ //Accede a las opciones del MENU USUARIO.
        switch (aux){
            case 4:{
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
                system("cls");
            }
                break;
            case 5:
                modificar_usuario();
                break;
            case 6:
                listar_usuarios_x_id();
                break;
            case 7:
                listar_usuarios();
                break;
            case 8:
                eliminar_usuario();
                break;
            case 9:system("cls");
                *f=true;
                break;
            }


    }
    if (m==3){ //Accede a las opciones del MENU ENTRENAMIENTO
         switch (aux){
            case 4:{
                Entrenamiento reg; ///Creo un registro
                reg=cargar_entrenamiento();

                if (guardar_entrenamiento(reg)){
                    cout<<"El entrenamiento se pudo guardar con exito"<<endl;
                }
                else{
                    cout<<"El entrenamiento no se pudo guardar."<<endl;
                }
                system("pause");
                system("cls");
            }
                break;
            case 5:{
                system("cls");
                cout<<"MODIFICAR ENTRENAMIENTO"<<endl;
                system("pause");
                system("cls");
            }
                break;
            case 6:{
                system("cls");
                cout<<"LISTAR ENTRENAMIENTO POR ID"<<endl<<endl;

                listar_entrenamiento_x_id();

                system("pause");
                system("cls");
            }
                break;
            case 7:{
                system("cls");
                cout<<"LISTAR ENTRENAMIENTO POR USUARIO"<<endl<<endl;

                listar_entranamiento_x_usuario();

                system("pause");
                system("cls");
            }
                break;
            case 8:{
                listar_entrenamientos();
                }
                break;
            case 9:*f=true;
                system("cls");
                break;
            }
    }
    if (m==5){ //Accede a MENU CONFIGURACION
        switch (aux){
            case 4:
                break;
            case 5:
                break;
            case 6:*f=true;
                    system("cls");
                break;
        }
    }
}
*p=aux; //Despues de todo el recorrido del switch, le asigna el valor nuevo de la tecla al puntero p.
}

//Submenu Usuarios
void menuUsuarios(){
    system("cls");
    bool volver=false;
    char tecla;
    const char *flecha="=>";
    int pos=4;
    while(!volver){
            gotoxy(1,1);
            cout << "           USUARIOS         "<< endl;
            cout << "-----------------------------------------------"<< endl;
            cout <<endl;
            gotoxy(1,4);
            cout <<"  1. Nuevo usuario"<< endl;
            cout <<"  2. Modificar Usuario"<< endl;
            cout <<"  3. Listar usuario por ID"<< endl;
            cout <<"  4. Listar todos los usuarios"<< endl;
            cout <<"  5. Eliminar usuario" << endl;
            cout <<"  6. Volver al menú principal" << endl;
            cout <<endl;
            gotoxy(1,pos);
            cout<< flecha;
            tecla=getch();
            validaTecla(tecla,&volver, &pos, 2);
    }
}

//Submenu Configuracion. Le agregué la funcion de setear la informacion.
void menuConfiguracion(){
system("cls");
bool volver=false;
char tecla;
const char *flecha="=>";
int pos=4;
    while(!volver){
        gotoxy(1,1);
        cout << "           CONFIGURACION         "<< endl;
        cout << "-----------------------------------------------"<< endl;
        cout <<endl;
        gotoxy(1,4);
        cout <<"  1. Realizar copia de seguridad"<< endl;
        cout <<"  2. Restaurar copia de seguridad" << endl;
        cout <<"  3. Volver al menú principal";
        gotoxy(1,pos);
        cout<< flecha;
        tecla=getch();
        validaTecla(tecla,&volver, &pos, 5);
    }
}

//Submenu Entrenamiento
void menuEntrenamiento(){
        system("cls");
        bool volver=false;
        char tecla;
        const char *flecha="=>";
        int pos=4;
        while(!volver){
            gotoxy(1,1);
            cout << "           ENTRENAMIENTO         "<< endl;
            cout << "-----------------------------------------------"<< endl;
            cout <<endl;
            gotoxy(1,4);
            cout <<"  1. Nuevo entrenamiento"<< endl;
            cout <<"  2. Modificar entrenamiento"<< endl;
            cout <<"  3. Listar entrenamiento por ID"<< endl;
            cout <<"  4. Listar entrenamiento por ID Usuario"<< endl;
            cout <<"  5. Listar todos los entrenamientos" << endl;
            cout <<"  6. Volver al menú principal" << endl;
            cout <<endl;
            gotoxy(1,pos);
            cout<<flecha;
            tecla=getch();
            validaTecla(tecla, &volver, &pos, 3);
        }
}
