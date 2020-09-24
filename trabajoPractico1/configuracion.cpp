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

const char *usuarioBackup="datos/usuario.BKP";
const char *entrenamientoBackup="datos/entrenamiento.BKP";

//Restauro Backup
void restaurarBackUp(){
    system("cls");
    bool volver=false;
    char tecla;
    const char *flecha="=>";
    int pos=4;
    int pin=0;
    while(!volver){
    gotoxy(20,1);
    cout<<"RESTAURACION DE ARCHIVO DE SEGURIDAD\n";
    gotoxy(20,2);
    cout<<"----------------------------------\n";
    gotoxy(1,4);
    cout<<"  1. Generar pin\n";
    cout<<"  2. Restaurar archivo de seguridad\n";
    cout<<"  3. Volver a menú Configuración\n";
    gotoxy(1,pos);
    cout<< flecha;
    tecla=getch();
    validaTeclaConf(tecla,&volver, &pos, &pin,2);
    }

}


//Restauro Archivos de seguridad
void restaurarArchivoSeg(int *pin){
system("cls");
char auxPin[20]; //Vector para validar el ingreso de numeros
int pinIngresado,intentoPermitido=3; //Pin ingresado e intentos para validar cuantas veces ingresa el pin
int pinOriginal=*pin; //Uso Pin original como auxiliar y le paso el valor del pin generado en el menu
    if(pinOriginal==0){
        gotoxy(20,3);
        cout<<"No se generó ningún PIN válido\n";
        cout<<"\nPara poder restaurar archivo de seguridad, genere un PIN válido";
        gotoxy(20,8);
        system("pause");
        system("cls");
        return;
    }
        gotoxy(20,3);
        cout<<"Restauración de archivo de seguridad para Usuarios y Entrenamientos.\n";
        gotoxy(1,5);
        cout<<"Ingrese PIN: ";
        showcursor();
        cin>>auxPin;
        pinIngresado=atoi(auxPin);

        while(pinIngresado!=pinOriginal){
            intentoPermitido--;
            cout<<"¡PIN incorrecto!\n";
            if (intentoPermitido==0){  //Si lo ingresa mal 3 veces seguidas, se bloquea el PIN
            cout<<"\nSe bloquea PIN, porfavor generar uno nuevo"<<endl;
            system("pause");
            system("cls");
            *pin=0; //Al bloquearse, se setea 0 automaticamente.
            return;
            }
            cout<<"Intentos restantes: "<<intentoPermitido<<"\n";
            cout<<"Ingrese PIN: ";
            cin>>auxPin;
            pinIngresado=atoi(auxPin);
        }
        system("cls");
        //Porcentaje
        int porcentaje=25;
            for(int x=0;x<4;x++){
            gotoxy(31,5);
            cout<<"Restaurando archivo de seguridad: ";
            cout<<porcentaje*(x+1);
            cout<<"%";
            Sleep(1000);
            if (x==3){
                gotoxy(20,7);
                restauroArchivoUsuario();
                gotoxy(20,9);
                restauroArchivoEntrenamiento();
                gotoxy(31,14);
                system("pause");
            }
                system("cls");
                hidecursor();
            }
}

//Genero Backup
void generarBackUp(){
    system("cls");
    bool volver=false;
    char tecla;
    const char *flecha="=>";
    int pos=4;
    int pin=0;
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
    validaTeclaConf(tecla,&volver, &pos, &pin,1);
    }
}

//Genero PIN
void generarPin(int *pin){
system("cls");
int aux=numeroAleatorio();
gotoxy(20,1);
cout<<"Aguarde unos segundos mientras se genera el pin solicitado"<<endl;
gotoxy(31,3);
cout<<"Generando pin";
Sleep(600);
cout<<".";
Sleep(600);
cout<<".";
Sleep(600);
cout<<".";
Sleep(600);
gotoxy(28,5);
cout<<"PIN GENERADO CON EXITO"<<endl;
gotoxy(35,7);
cout<<"PIN: "<<aux;
cout<<endl<<"\nEl PIN se bloqueará y se deberá generar uno nuevo si:\n";
cout<<"\n 1. Se ingresa erróneamente 3 veces al momento de generar archivo de seguridad";
cout<<"\n 2. Vuelve a menú CONFIGURACION\n";
*pin=aux;
gotoxy(25,14);
system("pause");
system("cls");
}

int numeroAleatorio(){
    int i;
    srand(time(NULL));
    i=rand();
    return i;

}

//Validación de teclas en SubMenu Realizar copia de seguridad
void validaTeclaConf(char t, bool *f, int *p, int *pin, int opcion){ //Valida tecla para las opciones de Configuracion y reportes ya que comparten 3 opciones.
int aux=*p;
int auxPin=*pin;
    if (t==72){ //TECLA ARRIBA
        switch(aux){
            case 4:aux=6;
                break;
            case 5:aux=4;
                break;
            case 6:aux=5;
                break;
        }
    }
    if (t==80){ //TECLA ABAJO
        switch(aux){
            case 4:aux=5;
                break;
            case 5:aux=6;
                break;
            case 6:aux=4;
                break;
        }
    }
    if (t==13){ //ENTER
        if (opcion==1){
            switch(aux){
            case 4:{
                    generarPin(&auxPin); //Genera pin aleatorio
                }
                break;
            case 5:
                generarArchivoSeg(&auxPin);             //Genera backup
                break;
            case 6:*f=true;
                break;
            }
        }else{
            switch(aux){
            case 4:{
                generarPin(&auxPin); //Genera pin aleatorio
                }
                break;
            case 5:restaurarArchivoSeg(&auxPin);//Restaura backup
                break;
            case 6:*f=true;
                break;
            }
        }
    }
*pin=auxPin;
*p=aux;
}

//Genero archivo de seguridad
void generarArchivoSeg(int *pin){
system("cls");
char auxPin[20]; //Vector para validar el ingreso de numeros
int pinIngresado,intentoPermitido=3; //Pin ingresado e intentos para validar cuantas veces ingresa el pin
int pinOriginal=*pin; //Uso Pin original como auxiliar y le paso el valor del pin generado en el menu
    if(pinOriginal==0){
        gotoxy(20,3);
        cout<<"No se generó ningún PIN válido\n";
        cout<<"\nPara poder generar archivo de seguridad, genere un PIN válido";
        gotoxy(20,8);
        system("pause");
        system("cls");
        return;
    }
        gotoxy(20,3);
        cout<<"Generación de archivo de seguridad para Usuarios y Entrenamientos.\n";
        gotoxy(1,5);
        showcursor();
        cout<<"Ingrese PIN: ";
        cin>>auxPin;
        pinIngresado=atoi(auxPin);

        while(pinIngresado!=pinOriginal){
            intentoPermitido--;
            cout<<"¡PIN incorrecto!\n";
            if (intentoPermitido==0){  //Si lo ingresa mal 3 veces seguidas, se bloquea el PIN
            cout<<"\nSe bloquea PIN, porfavor generar uno nuevo"<<endl;
            system("pause");
            system("cls");
            *pin=0; //Al bloquearse, se setea 0 automaticamente.
            return;
            }
            cout<<"Intentos restantes: "<<intentoPermitido<<"\n";
            cout<<"Ingrese PIN: ";
            cin>>auxPin;
            pinIngresado=atoi(auxPin);
        }
        system("cls");
        //Porcentaje
        int porcentaje=25;
            for(int x=0;x<4;x++){
            gotoxy(31,5);
            cout<<"Generando archivo de seguridad: ";
            cout<<porcentaje*(x+1);
            cout<<"%";
            Sleep(1000);
            if (x==3){
                buscoArchivos();
                gotoxy(31,14);
                system("pause");
            }
                system("cls");
                hidecursor();
            }
}

//Busco Archivos y los guardo en un vector
void buscoArchivos(){
Usuario *bkpUsuario; //Declaro vector de usuarios
Entrenamiento *bkpEntrenamiento;//Declaro vector de usuarios
int cantidadDeUsuariosRegistrados=cantidadUsuarios(); //Busco la cantidad de usuarios registrados
int cantidadDeEntrenamientoRegistrados=cantidad_entrenamientos(); //Busco la cantidad de entrenamientos registrados

bkpUsuario=(Usuario*)malloc(cantidadDeUsuariosRegistrados*sizeof(Usuario)); //Asignación dinamica de memoria para cargar usuarios
bkpEntrenamiento=(Entrenamiento*)malloc(cantidadDeEntrenamientoRegistrados*sizeof(Entrenamiento));//Asignacion dinamica de memoria para cargar entrenamientos
    gotoxy(20,7);
   if (guardoArchivoUsuario(bkpUsuario, cantidadDeUsuariosRegistrados)){
        cout<<"Se realizó con exito la generación de archivo de seguridad para Usuarios";
    } else{
        cout<<"Hubo un error al realizar la generación de archivo de seguridad para Usuarios";
        }
    gotoxy(20,9);
    if(guardoArchivoEntrenamiento(bkpEntrenamiento, cantidadDeEntrenamientoRegistrados)){
       cout<<"Se realizó con exito la generación de archivo de seguridad para Entrenamientos";
    } else{
        cout<<"Hubo un error al realizar la generación de archivo de seguridad para Entrenamientos";
        }
free(bkpUsuario); //Libero los vectores
free(bkpEntrenamiento); //Libero los vectores
}


//Recibe vector y lo guarda en archivo de usuarios Backup
bool guardoArchivoUsuario(Usuario *u, int c){
    Usuario reg; //Usuario donde guardamos los usuarios que leemos
    FILE *f;
    f=fopen("datos/usuarios.dat", "rb");
    int registrosGuardados=0; //Creo esta variable a modo de bandera
    if (f == NULL){
        system("cls");
        cout<<"\nNo se puedo abrir archivo original de Usuarios\n";
        system("pause");
        return false;
    }
        while (fread(&reg, sizeof (Usuario), 1, f)){
            FILE *bkp; //Archivo de backup
            bkp = fopen(usuarioBackup, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
            if (bkp == NULL){
            system("cls");
            cout<<"\nNo se pudo abrir archivo de backup de Usuarios\n";
            return false;
            }
            fwrite(&reg, sizeof(Usuario), 1, bkp);
            registrosGuardados++;
            fclose(bkp);
        }
    fclose(f);//Cierro archivo de usuarios original
    if (registrosGuardados==c){
    return true;
    }
}

//Recibe vector y lo guarda en archivo entrenamiento
bool guardoArchivoEntrenamiento(Entrenamiento *e, int c){
Entrenamiento reg; //Usuario donde guardamos los entrenamientos que leemos
FILE *f;
f=fopen("datos/entrenamiento.dat", "rb");
int registrosGuardados=0; //Creo esta variable a modo de bandera
    if (f == NULL){
        system("cls");
        cout<<"\nNo se puedo abrir archivo original de Usuarios\n";
        system("pause");
        return false;
    }
        while (fread(&reg, sizeof (Entrenamiento), 1, f)){
            FILE *bkp; //Archivo de backup
            bkp = fopen(entrenamientoBackup, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
            if (bkp == NULL){
            system("cls");
            cout<<"\nNo se pudo abrir archivo de backup de Entrenamiento\n";
            return false;
            }
            fwrite(&reg, sizeof(Usuario), 1, bkp);
            registrosGuardados++;
            fclose(bkp);
        }
    fclose(f);//Cierro archivo de usuarios original
    if (registrosGuardados==c){
    return true;
    }
}

bool restauroArchivoUsuario(){
Usuario reg; //Usuario donde guardamos los usuarios que leemos
FILE *f; //Archivo backup
FILE *original; //Archivo original
bool restaura=false;
f=fopen(usuarioBackup, "rb"); //Abro archivo de backup
    if (f == NULL){
        cout<<"Hubo un error al leer archivo de backup. No existe o esta dañado\n";
        return false;
    }
    original=fopen("datos/usuarios.dat", "wb"); //Seteo a 0 la información en usuarios.dat
        while (fread(&reg, sizeof (Usuario), 1, f)){
            original = fopen("datos/usuarios.dat", "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
            if (original == NULL){
            return false;
            }
            fwrite(&reg, sizeof(Usuario), 1, original); //Escribo los registros de backup en el archivo original
            fclose(original);
        }
    restaura=true;
    fclose(f);//Cierro archivo de usuarios backup
    gotoxy(20,7);
        if (restaura){
        cout<<"Se realizó con exito la generación de archivo de seguridad para Usuarios";
        } else{
        cout<<"Hubo un error al realizar la restauración de archivo de seguridad para Usuario";
            }
return restaura;
}

bool restauroArchivoEntrenamiento(){
Entrenamiento reg; //Usuario donde guardamos los usuarios que leemos
FILE *f; //Archivo backup
FILE *original; //Archivo original
bool restaura=false;
f=fopen(entrenamientoBackup, "rb"); //Abro archivo de backup
    if (f == NULL){
        cout<<"Hubo un error al leer archivo de backup de Entrenamiento. No existe o esta dañado\n";
        return false;
    }
    original=fopen("datos/entrenamiento.dat", "wb"); //Seteo a 0 la información en usuarios.dat
        while (fread(&reg, sizeof (Entrenamiento), 1, f)){
            original = fopen("datos/entrenamiento.dat", "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
            if (original == NULL){
            return false;
            }
            fwrite(&reg, sizeof(Entrenamiento), 1, original); //Escribo los registros de backup en el archivo original
            fclose(original);
        }
    restaura=true;
    fclose(f);//Cierro archivo de usuarios backup
    gotoxy(20,9);
        if (restaura){
        cout<<"Se realizó con exito la generación de archivo de seguridad para Entrenamiento";
        } else{
        cout<<"Hubo un error al realizar la restauración de archivo de seguridad para Entrenamiento";
            }
return restaura;

}

