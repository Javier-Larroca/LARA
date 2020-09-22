#include <iostream>
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
#include <iomanip>
using namespace std;
#include "entrenamiento.h"

//Direccion donde vamos a guardar todos los entrenamientos
const char *archivoEntrenamiento= "datos/entrenamiento.dat";

//Cargamos entrenamiento
Entrenamiento cargar_entrenamiento(){
    system("cls");
    bool cancelarCarga=false;
    Usuario reg; //Creo un usuario de soporte para acceder a sus atributos
    char opcion[50]; //Tengo que usar asignación dinamica aca para validar entrada
    Entrenamiento a, *aux;
    aux=&a;
    int id, tipoDeCarga=2;
    aux->id=cantidad_entrenamientos()+1;
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

    return a;

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

void mostrar_datos_entrenamientos(Entrenamiento r){
    cout<<"ID: "<<r.id<<endl;
    cout<<"ID Usuario: "<<r.idUsuario<<endl;
    cout<<"Actividad: "<<r.actividad<<endl;
    cout<<"Calorias: "<<r.calorias<<endl;
    cout<<"Fecha de entrenamiento: ";
    mostrar_fecha(r.fechaDeEntrenamiento);
    cout<<"Tiempo: "<<r.tiempo<<endl;
    cout<<endl;
}

void listar_entrenamientos(){
    system("cls");
    Entrenamiento reg;
    FILE *f;
    f= fopen(archivoEntrenamiento, "rb");

    if (f == NULL){
        cout<<"No se puede leer el archivo de entrenamientos"<<endl;
        return;
    }
    //encabezadoTablaUsuarios();
    while (fread(&reg, sizeof (Entrenamiento), 1, f)){
        mostrar_datos_entrenamientos(reg);
    }
    fclose(f);
    system("pause");
    system("cls");
    return;
}

bool guardar_entrenamiento(Entrenamiento reg){
    bool grabo;
    FILE *f;
    f = fopen(archivoEntrenamiento, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&reg, sizeof(Entrenamiento), 1, f);
    fclose(f);
    return grabo;
}

int cantidad_entrenamientos() {
	int cantidad;
	FILE* pFile;
	pFile = fopen(archivoEntrenamiento, "rb");
	if (pFile == NULL) {
		return 0;
	}
	fseek(pFile, 0, SEEK_END);
	cantidad = ftell(pFile) / sizeof(Entrenamiento);
	fclose(pFile);
	return cantidad;
}



