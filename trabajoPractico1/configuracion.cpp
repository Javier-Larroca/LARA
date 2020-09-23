#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
using namespace std;
#include "funciones.h"
#include "usuario.h"
#include "entrenamiento.h"
#include "ui.h"
#include "rlutil.h"
#include "configuracion.h"
using namespace rlutil;


void generarBackUp(){
    system("cls");
    bool volver=false;
    char tecla;
    const char *flecha="=>";
    int pos=4;
    while(!volver){
    gotoxy(20,1);
    cout<<"GENERACIÓN DE ARCHIVO DE SEGURIDAD\n";
    gotoxy(20,2);
    cout<<"----------------------------------\n";
    gotoxy(1,4);
    cout<<"  1. Generar pin\n";
    cout<<"  2. Generar archivo de seguridad\n";
    cout<<"  3. Volver a menú Configuración\n";
    gotoxy(1,pos);
    cout<< flecha;
    tecla=getch();
    validaTeclaSubMenu(tecla,&volver, &pos, 5);
    }
}

void generarPin(){
system("cls");
int pin;
pin=numeroAleatorio();
gotoxy(20,1);
cout<<"Aguarde unos segundos mientras se genera el pin solicitado"<<endl;
gotoxy(30,3);
cout<<"Generando pin";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(1000);
cout<<".";
Sleep(1000);
gotoxy(30,5);
cout<<"PIN GENERADO CON EXITO"<<endl;
cout<<"PIN: "<<pin;
cout<<"\nSi se ingresa erróneamente el pin 3 veces, se bloqueará el mismo y se deberá generar de nuevo\n";
system("pause");
system("cls");
}

int numeroAleatorio(){
    int i;
    srand(time(NULL));
    i=rand();
    return i;

}
