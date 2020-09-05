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
            ///Falta validacion de que el id no este repetido.
    aux->id = id;
    cout << "Nombres  : ";
    cin.ignore();
    cin.getline(aux->nombres, 50); ///Falta quitar espacios en nombre
    cout << "Apellidos: ";
    cin.getline(aux->apellidos, 50);   ///Falta quitar espacios en apellido
    cout << "Ingrese fecha de nacimiento " << endl;
    aux->nac=cargar_fecha(); //Llamo a la función cargar fecha
    cout << "Fecha ingresada: "; ///Habria que ver la forma de cortar aca la carga del usuario si es menor de 13 años
    mostrar_fecha(aux->nac);
    /*cout << "Fecha de nacimiento: "; //Lo dejo por las dudas, despues decidimos que funciones usar sino
    cin >> aux->nac.dia;
    cin >> aux->nac.mes;
    cin >> aux->nac.anio;**/ ///Para mi esto esta okey.

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
    //guardar_usuario(a); // Termina de cargar el usuario y valida que se guarde.Creo que es un buen lugar para poner el mensaje, decime que te parece despues.
    ///Esto lo saque de aca, y lo mande directo para el menu, en funciones.cpp
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
        return false;
    }
    grabo = fwrite(&reg, sizeof(Usuario), 1, f);
    fclose(f);
    return grabo;
}


//Encabezado para reporte de usuarios en forma de tabla
    void encabezadoTablaUsuarios(){
    cout << left;
    cout << setw(14) << "ID" << "|";
    cout << setw(20) << "Nombres" << "|";
    cout << setw(20)  << "Apellidos" << "|";
    cout << setw(16) << "Fecha nacimiento" << "|";
    cout << setw(7) << "Altura" << "|";
    cout << setw(7) << "Peso" << "|";
    cout << setw(10) << "Actividad" << "|";
    cout << setw(10) << "Apto medico" << "|";
    cout << setw(6)  << "Estado" << "|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

//Datos en forma de tabla para usuarios.

void mostrarDatosUsuarios(Usuario r){
    char aux = toupper(r.perfilActividad); //Uso un char auxiliar para mostrar todas las letras en mayusculas
    cout << left;
    cout << setw(14) << r.id << "|";
    cout << setw(20) << r.nombres << "|";
    cout << setw(20) << r.apellidos << "|";
    cout << right;
    cout << setfill('0');               //Esto es para que muestre un 0 en los dias del 1 al 9
    cout << setw(2) <<r.nac.dia <<"/";
    cout <<  setw(2) <<r.nac.mes << "/";
    cout << left;
    cout << setfill(' ');              //El setfill sigue de largo hasta encontrar un endl, por lo que lo lleno con espacios. Si genera problemas ponemos un if y listo.
    cout << setw(10) <<r.nac.anio << "|";
    cout << fixed;
    cout << setw(7) << setprecision(2) << r.altura << "|";
    cout << fixed;
    cout << setw(7) << setprecision(2) << r.peso << "|";
    cout << setw(10) << aux << "|";
    cout << setw(11) << r.aptoMedico << "|";
    cout << right;
    cout << setw(6) << r.estado << "|";
    cout << endl;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////

Usuario leer_usuario(int pos){
    Usuario reg;
    FILE *p = fopen(archivoUsuarios, "rb");
    if (p == NULL){
        reg.id = 0;
        return reg;
    }
    fseek(p, pos * sizeof(Usuario), SEEK_SET);
    fread(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return reg;
}

bool guardar_usuario(Usuario reg, int pos){
    bool grabo;
    FILE *f;
    f = fopen(archivoUsuarios, "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f, pos * sizeof(Usuario), SEEK_SET);
    grabo = fwrite(&reg, sizeof(Usuario), 1, f);
    fclose(f);
    return grabo;
}

void listar_usuarios_x_id(){
    //cls();
    //title("LISTADO DE PARTICIPANTE x ID");
    //gotoxy(1, 5);
    int id, pos;
    cout << "ID: ";
    cin >> id;
    pos = buscarUsuario(id);
    if (pos >= 0){
        mostrar_usuario(leer_usuario(pos));
    }
    else{
        cout<<"No existe el usuario"<<endl;;
    }
}

int buscarUsuario(int idBuscado){
    Usuario reg;
    FILE *f;
    int pos=0;
    f = fopen(archivoUsuarios, "rb");
    if (f == NULL){
        return -2;
    }
    while(fread(&reg, sizeof(Usuario), 1, f)){
        if (idBuscado == reg.id){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}


int cantidadUsuarios(){
    FILE *p = fopen(archivoUsuarios, "rb");
    if (p == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(p, 0, SEEK_END); // SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Usuario);
    return cant;
}

bool modificar_usuario(){
    //cls();
    //title("MODIFICAR PARTICIPANTE");
    //gotoxy(1, 5);
    int id, pos;
    cout << "ID: ";
    cin >> id;
    pos = buscarUsuario(id);
    if (pos >= 0){
        cout << endl << "Usuario a modificar: " << endl;
        cout << "---------------------------" << endl;
        Usuario reg = leer_usuario(pos);
        mostrar_usuario(reg);
        cout << endl;
        ///Habria que poner un switch y permitir modificar el peso, el perfil de actividad y el apto médico.
        cout << "Nuevo nombre: ";
        cin.ignore();
        cin.getline(reg.nombres, 50);
        if (guardar_usuario(reg, pos) == true){
            //msj("Participante guardado correctamente.", APP_FORECOLOR, APP_OKCOLOR);
            cout<<"Participante guardado correctamente"<<endl<<endl;
            return true;
        }
        else{
            //msj("El participante no se guardó correctamente.", APP_FORECOLOR, APP_ERRORCOLOR);
            cout<<"Participante guardado correctamente"<<endl<<endl;
            return true;

        }
    }
    else{
        //msj("No existe el participante", 15, 3);
        cout<<"No existe el participante"<<endl<<endl;
        return false;
    }
}
