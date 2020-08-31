#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string.h>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "funciones.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "Spanish");
    char opc[1]; //Se puede cambiar, queda medio feo un vector de 1. Para evitar bugs fue lo poco que se me ocurrio
    bool finDePrograma=false;
    while(!finDePrograma){
        system("cls");
        cout <<endl;
        cout << "           MENU PRINCIPAL         "<< endl;
        cout << "-----------------------------------------------"<< endl;
        cout <<endl;
        cout <<"  1. Usuarios"<< endl;
        cout <<"  2. Entrenamientos"<< endl;
        cout <<"  3. Reportes"<< endl;
        cout <<"  4. Configuración"<< endl;
        cout <<"  5. Salir del programa" << endl;
        cout <<endl;
        cout <<"Seleccione una opción: ";
        cin >> opc;
        system("cls");
        validaOpcion(opc, &finDePrograma);
    }
    return 0;
}
