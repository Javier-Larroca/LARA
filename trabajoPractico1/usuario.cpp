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
#include "funciones.h"
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13


//Direccion donde vamos a guardar todos los usuarios.
const char *archivoUsuarios= "datos/usuarios.dat";


void mostrar_usuario(Usuario reg){
    char mayuscula = toupper(reg.perfilActividad); //Le agrego esta variable para que pueda mostrar el caracter en mayuscula
    cout << "ID         : " << reg.id << endl;
    cout << "Nombres    : " << reg.nombres<< endl;
    cout << "Apellidos  : " << reg.apellidos << endl;
    cout << "Nacimiento : ";
    mostrar_fecha(reg.nac);
    cout << "Altura     : " << reg.altura << " cms"<< endl;
    cout << "Peso       : " << reg.peso << " kgs"<< endl;
    cout << "Perfil     : " << mayuscula << endl;
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
    system("cls");
    showcursor();
    bool cancelarCarga=false;
    Usuario a, *aux;
    aux = &a;
    char auxiliares[50]; //Creo esta cadena de forma auxiliar para validar espacios
    int id,tipoDeCarga=1; //Tipo de carga es para saber si estamos cargando un usuario o un entrenamiento.
    cout << "ID   : ";
    cin >> id;
    aux->id = validar_id(id, tipoDeCarga); //Creo que funciona bien.
    cout << "Nombres  : ";
    cin.ignore();
    cin.getline(auxiliares, 50);
    valida_espacios(auxiliares);
    strcpy(aux->nombres,auxiliares); //Uso el copy para volcar el nombre en el atributo
    cout << "Apellidos: ";
    cin.ignore();
    cin.getline(auxiliares, 50);
    valida_espacios(auxiliares);
    strcpy(aux->apellidos, auxiliares); //Uso el copy para volcar el nombre en el atributo
    cout << "Ingrese fecha de nacimiento " << endl;
    aux->nac=cargar_fecha(tipoDeCarga); //Llamo a la función cargar fecha
    if (aux->nac.dia == 0){ //En fecha.cpp lo comento también, se me ocurrio usar el dia como bandera para cortar la carga si es menor.
        cout << "\nSe cancela carga de usuario por no cumplir con la edad minima...\n";
        return a;
    }
    cout << "Fecha ingresada: ";
    mostrar_fecha(aux->nac);
    cout<< "Altura   : ";
    cin>>aux->altura;
    while (aux->altura <= 0){
        cout << "Ingrese una altura válida\n";
        cout << "Altura: ";
        cin>>aux->altura;
        }
    cout << "Peso: ";
    cin>>aux->peso;
    while (aux->peso <= 0){
        cout << "Ingrese un peso válido\n";
        cout << "Peso: ";
        cin>>aux->peso;
        }
    cout << "\nIngrese un perfil de actividad 'A' 'B' o 'C'."<<endl;
    cout<<"Perfil actividad   : ";
    cin>>auxiliares;
    valida_cadena(auxiliares);
    aux->perfilActividad=auxiliares[0]; //Al ser validada previamente, toma el primer caracter de la cadena de validación
    cout << "Apto medico: ";
    cin >> auxiliares;
    aux->aptoMedico=valida_apto_medico(auxiliares);
    aux->estado = true;
    hidecursor();
    return a;
}



//Prototipo en forma de tabla

void listar_usuarios(){
    system("cls");
    Usuario reg;
    FILE *f;
    f=fopen(archivoUsuarios, "rb");

    if (f == NULL){
        cout << "No se puede leer el archivo.";
        return;
    }
    encabezadoTablaUsuarios();
    while (fread(&reg, sizeof (Usuario), 1, f)){
         mostrarDatosUsuarios(reg);
    }
    fclose(f);
    system("pause");
    system("cls");
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
    if (r.estado){
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
    system("cls");
    int id, pos;
    cout << "ID: ";
    cin >> id;
    system("cls");
    pos = buscarUsuario(id);
    if (pos >= 0){
        mostrar_usuario(leer_usuario(pos));
    }
    else{
        cout<<"No existe el usuario"<<endl;;
    }
    system("pause");
    system("cls");
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
    system("cls");
    showcursor();
    int id, pos, opcion;
    char opc[10];
    bool modifico=false, volver=false;
    cout << "Ingrese ID de usuario a modificar\n";
    cout << "ID: ";
    cin >> id;
    cin.ignore();
    pos = buscarUsuario(id);
    Usuario reg = leer_usuario(pos);
    if (pos >= 0){
        while (!volver){
        system("cls");
        cout << endl << "Usuario a modificar: " << endl;
        cout << "---------------------------" << endl;
        mostrar_usuario(reg);
        cout << endl;
        ///Habria que poner un switch y permitir modificar el peso, el perfil de actividad y el apto médico.
        //Armo una funcion.
        cout << "Ingrese el campo que desea modificar: \n";
        cout << "1. Peso\n";
        cout << "2. Perfil de actividad\n";
        cout << "3. Apto medico \n";
        cout << "4. Volver a menú anterior\n";
        cout << "Opcion seleccionada: ";
        cin.getline(opc, 10);
        opcion = atoi(opc);
        volver = modificar_atributo(opcion, &reg, &modifico); //Llamo a la función modificar_atributo esperando un bool.
        }
        if (modifico==true){
            if (guardar_usuario(reg, pos) == true){
            //msj("Participante guardado correctamente.", APP_FORECOLOR, APP_OKCOLOR);
            cout<<"¡Se guardaron todas las modificaciones correctamente!"<<endl;
            system("pause");
            return true;
            }
            else{
            //msj("El participante no se guardó correctamente.", APP_FORECOLOR, APP_ERRORCOLOR);
            cout<<"¡No se pudo guardar las modificaciones!"<<endl<<endl;
            return true;
            }
        }else{
        cout << "No se realizaron modificaciones\n";
        system("pause");
        }
    }
    else{
        //msj("No existe el participante", 15, 3);
        cout<<"Usuario inexistente"<<endl<<endl;
        system("pause");
        return false;
    }
    hidecursor();
    system("cls");
}

//Modifico atributo
bool modificar_atributo(int o, Usuario *r, bool *m){
    char aux[15]; //Cadena char para validar la opcion que ingresa. Uso puntero para capturar si tiene espacios
    long int valor=0;// Le asigno 0 ya que despues le paso el valor de aux
    switch (o){
    case 1: //Modificacion de peso. Sin validacion de entrada.
        cout << "\nIngrese nuevo peso para " << r->nombres << " " << r->apellidos << endl;
        cout << "Peso: ";
        cin >> r->peso;
        while (r->peso <= 0){
        cout << "Ingrese un peso válido\n";
        cout << "Peso: ";
        cin >> r->peso;
        }
        cout << "\nPeso modificado\n";
        *m=true;
        system("pause");
        cin.ignore();
        return false;//Limpio buffer
        break;
    case 2: //Modificacion perfil de actividad. Valida que no se ingresen otras letras
        cout << "\nIngrese nuevo perfil de actividad para " << r->nombres << " " << r->apellidos << endl;
        cout << "Perfil actividad: ";
        cin>>aux;
        valida_cadena(aux);
        r->perfilActividad = aux[0];
        cout << "\nPerfil modificado\n";
        *m=true;
        system("pause");
         cin.ignore();
        return false;
        break;
    case 3: //Validacion apto medico. Valida que no se ingrese otros caracteres
        cout << "\nIngrese nuevo apto medico para " << r->nombres << " " << r->apellidos << endl;
        cout << "Apto medico: ";
        cin>>aux;
        r->aptoMedico = valida_apto_medico(aux);
        cout << "\nApto medico modificado\n";
        *m=true;
        system("pause");
        cin.ignore();
        return false;
        break;
    case 4: //Opción para cancelar modificacion
        return true;
        break;
    default:
        cout << "Opción ingresada no es válida\n";
                system("pause");
                system ("cls");
        break;
    }

}

//Baja lógica de usuario
void eliminar_usuario(){
int id;
Usuario reg;
char opc[10];
long int longitud;
system("cls");
cout << "Eliminar usuario\n";
cout << "--------------------------------------\n";
cout << "Ingrese ID de usuario a eliminar\n";
cout << "ID: ";
cin >> id;
cin.ignore();
system("cls");
cout << "USUARIO A ELIMINAR: \n";
cout <<endl;
mostrar_usuario(reg=leer_usuario(buscarUsuario(id)));
cout << "\nAl eliminar el usuario no se podrá crear uno nuevo con el mismo ID\n";
cout << "\n¿Esta seguro que desea eliminar el usuario: " << reg.nombres << " " <<reg.apellidos << "? S/N : ";
cin.getline(opc,10);
longitud = strlen(opc);
    while ((toupper(opc[0]) != 'S' && toupper(opc[0]) != 'N') || longitud >1){
      cout << "Opción ingresada no es válida\n";
      cout << "\n¿Esta seguro que desea eliminar el usuario? S/N: ";
      cin.getline(opc,10);
      longitud=strlen(opc);
    }
        if(toupper(opc[0])=='S'){
        system("cls");
        reg.estado=false;
            if (guardar_usuario(reg, buscarUsuario(id))== true){
            //gotoxy(10,5);
            cout << "Se da de baja al usuario: " << reg.nombres << " " << reg.apellidos << endl;
            cout << "\n";
            system("pause");
            }else{
            //gotoxy(10,5);
            cout << "No se puedo dar de baja al usuario: " << reg.nombres << " " << reg.apellidos << endl;
            cout << "\n";
            }
        }if(toupper(opc[0])=='N'){
        system("cls");
        //gotoxy(10,5);
        cout << "Se cancela baja de usuario\n";
        system("pause");
        }
        system("cls");
}
//Valida espacios en cadena
void valida_espacios(char *n){
long int longitud;
longitud=strlen(n);
while (n[0] == ' ' || n[longitud-1] == ' ' || longitud==0){
    cout << "Ingrese valores válidos, no estan permitidos campos vacíos, espacios al inicio o al final\n";
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(n, 50);
    longitud=strlen(n);
}

}

int validar_id(int p, int t){
    if (t==1){ //Si es 1, es carga de usuario.
        while (leer_usuario(buscarUsuario(p)).id==p){ //Si el usuario se repite, entra en el while hasta ingresar un id nuevo.
            cout<< "\nEl ID ingresado ya fue asignado a otro usuario. Ingrese un nuevo ID: \n";
            cout << "ID: ";
            cin >> p;
        }
    }else{ //Si no es uno, mandamos el numero 2 por lo que entre en este ciclo.
        if (t==2){
            while (leer_usuario(buscarUsuario(p)).id!=p){ //Si el usuario no existe, entra en el while hasta ingresar un id válido.
                cout << "\nEl ID ingresado no existe. Porfavor ingrese un usuario válido";
                cout <<"\nID: ";
                cin >>p;
            }
            cout << "Se cargará los datos de entrenamiento al usuario: " << leer_usuario(buscarUsuario(p)).nombres <<" "<< leer_usuario(buscarUsuario(p)).apellidos;
        }
        else{
            while (leer_usuario(buscarUsuario(p)).id!=p){ //Si el usuario no existe, entra en el while hasta ingresar un id válido.
                cout << "\nEl ID ingresado no existe. Porfavor ingrese un usuario válido";
                cout <<"\nID: ";
                cin >>p;
            }
            cout << "Se listaran los entrenamientos del siguiente usuario: " << leer_usuario(buscarUsuario(p)).nombres <<" "<< leer_usuario(buscarUsuario(p)).apellidos<<endl<<endl;
        }
    }
    return p;
}

void valida_cadena(char *n){
long int longitud;
longitud=strlen(n);
while (longitud>1 || (toupper(n[0]) != 'A' && toupper(n[0]) != 'B' && toupper(n[0]) != 'c')){
    cout << "\nPerfil de actividad erróneo";
    cout << "\nPerfil de Actividad: ";
    cin>>n;
    longitud=strlen(n);
}

}

int valida_apto_medico(char *n){
int valor = strtol(n, NULL, 36); //Esta funcion me permite obtener un numero especifico de codigo ASCII para validar letras ya que ATOI me devuelve 0 si son letras
        while (valor != 1 && valor != 0){
        cout << "Solo se permiten los siguientes valores: 1 | 0\n";
        cout << "Apto medico: ";
        cin>>n;
        valor = strtol (n, NULL, 36);
        }
    return valor;
}
