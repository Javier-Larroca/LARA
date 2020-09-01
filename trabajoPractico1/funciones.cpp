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
using namespace std;
#include "funciones.h"
#include "usuario.h"

void validaOpcion(char o[], bool *f){
int opcion=atoi(o); //Aca paso la cadena a numeros
        switch (opcion){
        case 1:{
            mostrar_usuario(cargar_usuario());
            system("pause");
        }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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
