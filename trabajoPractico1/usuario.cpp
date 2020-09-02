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
#include "usuario.h"

void mostrar_usuario(Usuario reg){
    cout << "ID         : " << reg.id << endl;
    cout << "Nombres    : " << reg.nombres<< endl;
    cout << "Apellidos  : " << reg.apellidos << endl;
    cout << "Nacimiento : ";
    mostrar_fecha(reg.nac);
    cout << "Altura     : " << reg.altura << " cms"<< endl;
    cout << "Peso       : " << reg.peso << " kgs"<< endl;
    cout << "Perfil     : " << reg.perfilActividad << endl;
    cout << "Apto medico: " << reg.aptoMedico << endl;
}
/*
int buscar_usuario(int id_buscado){
    Usuario reg;
    FILE *f;
    int pos=0;
    f = fopen("datos/usuarios.dat", "rb");
    if (f == NULL){
        return -1;
    }
    while(fread(&reg, sizeof(Usuario), 1, f)){
        if (id_buscado == reg.id){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}

*/
Usuario cargar_usuario(){ //Cargamos usuario
    Usuario a, *aux;
    aux = &a;

    int id, pos, apto;
    cout << "ID   : ";
    cin >> id;
    /*
    while(!(id >= 1000 && codigo <= 9999)){
        cout << "> Código   : ";
        cin >> codigo;
    }
    **/
    /*
    // Validamos el ID que no se repita en la lista
    while (buscar_usuario(id) >= 0){
        cout << "> ID   : ";
        cin >> id;
    }
    // Fin de la validación de id
    */
    aux->id = id;
    cout << "Nombres  : ";
    cin.ignore();
    cin.getline(aux->nombres, 50);
    cout << "Apellidos: ";
    cin.getline(aux->apellidos, 50);
    cout << "Ingrese fecha de nacimiento " << endl;
    aux->nac=cargar_fecha(); //Llamo a la función cargar fecha
    cout << "Fecha ingresada: ";
    mostrar_fecha(aux->nac);
    /*cout << "Fecha de nacimiento: "; //Lo dejo por las dudas, despues decidimos que funciones usar sino
    cin >> aux->nac.dia;
    cin >> aux->nac.mes;
    cin >> aux->nac.anio;**/

    cout<< "Altura   : ";
    cin >> aux->altura;
    cout << "Peso: ";
    cin >> aux->peso;

    cout << "Perfil actividad   : ";
    cin >> aux->perfilActividad;
    /// "toupper" convierte un caracter de minuscula a mayuscula.
    while (toupper(aux->perfilActividad) != 'A' && toupper(aux->perfilActividad) != 'B' && toupper(aux->perfilActividad) != 'C'){
        cout << endl <<  "> Perfil Actividad   : " ;
        cin >> aux->perfilActividad;
    }
    cout << "Apto medico: ";
    cin >> apto;
    while (apto != 0 && apto != 1 ){
        cout << endl <<  "> Apto medico  : " ;
        cin >> apto;
    }
    aux->aptoMedico = apto;
    //No se si esta bien esta asignacion
    /// Para mi si

    aux->estado = true;
    guardar_usuario(a); // Termina de cargar el usuario y valida que se guarde.Creo que es un buen lugar para poner el mensaje, decime que te parece despues.

    return a;
}
//Listar usuarios

//Original
/* void listar_usuarios(){
    Usuario reg;
    FILE *f;
    int aux;
    f = fopen(archivoUsuarios, "rb");
    if (f == NULL){
        cout << "No se puede leer el archivo.";
        return;
    }
    if (!fread(&reg, sizeof(Usuario), 1, f)){  //Valida que existan usuarios cargados
        cout << "No existen usuarios cargados" << endl;
        }
    while(fread(&reg, sizeof(Usuario), 1, f)){
        mostrar_usuario(reg);
        cout << endl;
    }
    system("pause");
    fclose(f);
} **/

//Prototipo en forma de tabla

void listar_usuarios(){
Usuario reg;
FILE *f;

f=fopen(archivoUsuarios, "rb");

 if (f == NULL){
        cout << "No se puede leer el archivo.";
        return;
    }
 if (!fread(&reg, sizeof(Usuario), 1, f)){  //Valida que existan usuarios cargados
        cout << "No existen usuarios cargados" << endl;
    }
    encabezadoTablaUsuarios();
    while (fread(&reg, sizeof (Usuario), 1, f)){
    mostrarDatosUsuarios(reg);
    }
    system("pause");
}

//Guardar usuarios
bool guardar_usuario(Usuario reg){
    bool grabo;
    FILE *f;
    f = fopen(archivoUsuarios, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
    if (f == NULL){
        cout << endl <<"No se pudo guardar el usuario";
        return false;
    }
    grabo = fwrite(&reg, sizeof(Usuario), 1, f);
    fclose(f);
    cout << endl <<"¡Se cargo correctamente el usuario!" << endl;
    return grabo;
}

//Encabezado para reporte de usuarios en forma de tabla
void encabezadoTablaUsuarios(){
cout << left;
cout << setw(4) << "ID";
cout << setw(20) << "Nombres";
cout << setw(15)  << "Apellidos";
cout << setw(12) << "Altura";
cout << setw(12) << "Peso";
cout << setw(10)  << "Estado" << endl;
cout << "--------------------------------------------------------------------------------" << endl;

}

//Datos en forma de tabla para usuarios.

void mostrarDatosUsuarios(Usuario r){
cout << left;
cout << setw(4) << r.id;
cout << setw(20) << r.nombres;
cout << setw(20) << r.apellidos;
cout << fixed;
cout << setw(8) << setprecision(2) << r.altura;
cout << fixed;
cout << setw(8) << setprecision(2) << r.peso;
cout << right;
cout << setw(2) << r.estado;
cout << endl;
}
