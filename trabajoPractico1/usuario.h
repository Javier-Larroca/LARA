#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "fecha.h"

// Atributos de un usuario
struct Usuario{
    int id;
    char nombres[50];
    char apellidos[50];
    Fecha nac;
    float altura;
    float peso;
    char perfilActividad;
    bool aptoMedico;
    bool estado;
};

//Direccion donde vamos a guardar todos los usuarios.
const char archivoUsuarios[50]="datos/usuarios.dat";


//Funciones para Usuario

Usuario cargar_usuario(); //Carga un usuario
void mostrar_usuario(Usuario); //Muestra atributos de usuario cargado
int buscar_usuario(int); //
void listar_usuarios(); //Lista usuarios
bool guardar_usuario(Usuario); //Guarda usuarios, se llama a esta función al final de cargar_usuario
void encabezadoTablaUsuarios(); //Encabezado para mostrar usuarios en forma de tabla. No terminado
void mostrarDatosUsuarios(Usuario r); //Mostrar datos para los encabezados en forma de tabla. No terminado

///////////////////////////////////////////////////////////////////
bool guardar_usuario(Usuario, int);
int cantidadUsuarios();
int buscarUsuario(int);
Usuario leer_usuario(int);
void listar_usuarios_x_id();
bool modificar_usuario();

#endif // USUARIO_H_INCLUDED

