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
#include "entrenamiento.h"

//Direccion donde vamos a guardar todos los entrenamientos
const char *archivoEntrenamiento= "datos/entrenamiento.dat";

//Cargamos entrenamiento
Entrenamiento cargar_entrenamiento(){
bool cancelarCarga=false;
Usuario reg; //Creo un usuario de soporte para acceder a sus atributos
char opcion[50]; //Tengo que usar asignación dinamica aca para validar entrada
Entrenamiento a, *aux;
aux=&a;
int id, tipoDeCarga=2;
cout << "Ingrese ID de usuario correspondiente: ";
cin >> id;
aux->idUsuario = validar_id(id, tipoDeCarga);
cout << "\nIngrese fecha de entrenamiento: \n";
aux->fechaDeEntrenamiento=cargar_fecha(tipoDeCarga);
aux->actividad=validar_actividad(opcion, leer_usuario(buscarUsuario(aux->idUsuario)).aptoMedico);
cout << "Ingrese calorias: ";
cin >> aux->calorias;
cout << "\nIngrese tiempo en minutos: ";
cin >> aux->tiempo;
}

//Valida actividad a registrar
int validar_actividad(char *o, int a){
int opc;
cout << "\nActividades: \n";
cout << "1. Caminata\n" << "2. Correr\n" << "3.Bicicleta\n " << "4. Natacion\n" << "5.Pesas\n";
cout << "Ingrese actividad a registrar: ";
cin >> o;
opc=atoi(o);

while (opc<1 || opc >5){
cout << "Actividad no reconocida. Ingrese actividad válida a registrar: ";
cin >> o;
opc=atoi(o);
    if (a==0 && (opc==4 || opc == 5)){
    cout << "Usuario sin apto medico vigente. Natacion y pesas no son permitias\n";
    cout << "Ingrese actividad a registrar: ";
    opc=0;
    }
}

}
