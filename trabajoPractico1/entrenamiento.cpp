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
    cout << "\n\nIngrese fecha de entrenamiento: \n";
    aux->fechaDeEntrenamiento=cargar_fecha(tipoDeCarga);

    cout << "\nActividades: \n";
    cout << "1. Caminata\n" << "2. Correr\n" << "3. Bicicleta\n" << "4. Natacion\n" << "5. Pesas\n";

    aux->actividad=validar_actividad(opcion, leer_usuario(buscarUsuario(aux->idUsuario)).aptoMedico);
    cout << "\nIngrese calorias: ";
    cin >> aux->calorias;
    while (a.calorias<1){
        cout<<"Ingreso un numero de calorias no valido."<<endl;
        cout << " >Ingrese calorias: ";
        cin >> aux->calorias;
    }
    cout << "\nIngrese tiempo en minutos: ";
    cin >> aux->tiempo;
    while (a.tiempo<1){
        cout<<"Ingreso un numero de minutos no valido."<<endl;
        cout << " >Ingrese tiempo en minutos: ";
        cin >> aux->tiempo;
    }

    return a;
}

//Valida actividad a registrar
int validar_actividad(char *o, int a){
    int opc;
    cout << "Ingrese actividad a registrar: ";
    cin >> o;
    opc=atoi(o);
    if (opc<1 || opc >5){
        cout << "Actividad no reconocida."<<endl<<" >";
        validar_actividad(o,a);
    }
    //cout<<endl<<"APTO FISICO: "<<a<<endl;
    if (a==0 && (opc==4 || opc == 5)){
        cout << "Usuario sin apto medico vigente. Natacion y pesas no son permitias"<<endl<<" >";
        validar_actividad(o,a);
    }
    opc=atoi(o);
}

void mostrar_datos_entrenamiento(Entrenamiento r){
    cout<<endl;
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
        mostrar_datos_entrenamiento(reg);
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
	FILE *f;
	f = fopen(archivoEntrenamiento, "rb");
	if (f == NULL) {
		return 0;
	}
	fseek(f, 0, SEEK_END);
	cantidad = ftell(f) / sizeof(Entrenamiento);
	fclose(f);
	return cantidad;
}

int buscar_entrenamiento(int id) {
	FILE* f;
	f = fopen(archivoEntrenamiento, "rb");

	if (f== NULL) {
		return -1;
	}

	Entrenamiento reg;
	int index = 0;
	while (fread(&reg, sizeof(Entrenamiento), 1, f) == 1) {
		if (reg.id == id) {
			fclose(f);
			return index;
		}
		index++;
	}
	fclose(f);
	return -1;
}

Entrenamiento leer_entrenamiento(int pos) {
	FILE* f;
	Entrenamiento reg = {};
	f = fopen(archivoEntrenamiento, "rb");
	if (f == NULL) {
		return reg;
	}
	fseek(f, pos*sizeof(Entrenamiento), SEEK_SET);
	fread(&reg, sizeof(Entrenamiento), 1, f);
	fclose(f);
	return reg;
}

void listar_entrenamiento_x_id(){
    int codigo, pos;
    cout << "ID de entrenamiento: ";
    cin >> codigo;

    pos = buscar_entrenamiento(codigo);

    if (pos >= 0){
        mostrar_datos_entrenamiento(leer_entrenamiento(pos));
    }
    else{
        //msj("No existe el participante", 15, 3);
        cout<<"El entrenamiento ingresado no pudo ser leido."<<endl;
    }
}

void listar_entranamiento_x_usuario(){
    int idUsuario, pos,ce;
    cout<<"ID de usuario a consultar: ";
    cin>> idUsuario;
    cout<<endl;
    idUsuario = validar_id(idUsuario, 3);
    ce=buscar_entrenamiento_x_usuario(idUsuario);
    if (ce==-1){
        cout<<"Error al abrir el archivo."<<endl;
    }
    else{
        if (ce==0){
            cout<<"No hay entrenamientos registrados por el usuario."<<endl;
        }
        else{
            cout<<"Listado de los "<<ce<<" encontrados del usuario."<<endl;
        }
    }

}

int buscar_entrenamiento_x_usuario(int idUsuario) {
	FILE* f;
	f = fopen(archivoEntrenamiento, "rb");
    int cont=0;
	if (f== NULL) {
		return -1;
	}

	Entrenamiento reg;
	int index = 0;
	while (fread(&reg, sizeof(Entrenamiento), 1, f) == 1) {
		if (reg.idUsuario == idUsuario) {
			//Vamos a probar
			mostrar_datos_entrenamiento(leer_entrenamiento(index));
			cont++;
		}
		index++;
	}
	fclose(f);
	return cont;
}

void modificar_entrenamiento_x_id(){
    int codigo, pos,op;
    Entrenamiento reg;
    cout << "ID de entrenamiento a modificar: ";
    cin >> codigo;

    pos = buscar_entrenamiento(codigo);

    if (pos >= 0){
        reg = leer_entrenamiento(pos);
        mostrar_datos_entrenamiento(reg);
    }
    else{
        cout<<"El entrenamiento ingresado no pudo ser leido."<<endl;
    }

    cout<<"¿Que datos desea cambiar del entrenamiento?"<<endl<<endl;
    cout<<" 1. Tiempo"<<endl;
    cout<<" 2. Calorias"<<endl;
    cout<<"Elija la opcion: ";
    cin>>op;
    switch(op){
        case(1):{
            cout<<"Ingrese tiempo: ";
            cin>>reg.tiempo;
        }
        break;
        case(2):{
            cout<<"Ingrese calorias: ";
            cin>>reg.calorias;
        }
        break;
        default:{
        cout<<"Opcion ingresada incorrecta"<<endl;
        }
    }

    if(guardar_entrenamiento(reg,pos)){
        cout<<"La modificacion se realizo con exito"<<endl;
    }
    else{
        cout<<"La modificacion no pudo realizarce."<<endl;
    }
}

bool guardar_entrenamiento(Entrenamiento reg, int pos) {
	FILE* f;
	bool bGrabo = true;
	f = fopen(archivoEntrenamiento, "rb+");
	if (f == NULL) {
		return false;
	}
	fseek(f, pos * sizeof(Entrenamiento), SEEK_SET);
	bGrabo = fwrite(&reg, sizeof(Entrenamiento), 1, f);
	fclose(f);
	return bGrabo;
}




