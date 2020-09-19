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


//Funciones para Usuario

Usuario cargar_usuario(); //Carga un usuario
void mostrar_usuario(Usuario); //Muestra atributos de usuario cargado
void listar_usuarios(); //Lista usuarios
bool guardar_usuario(Usuario); //Guarda usuarios, se llama a esta función al final de cargar_usuario
void encabezadoTablaUsuarios(); //Encabezado para mostrar usuarios en forma de tabla.
void mostrarDatosUsuarios(Usuario r); //Mostrar datos para los encabezados en forma de tabla.
bool modificar_atributo(int o, Usuario *r, bool *m); //Modifica atributo. Le paso la opcion elegida, la direccion del usuario y un booleano para validar si modifico algun atributo
void eliminar_usuario();
void valida_espacios(char *n);
int validar_id(int p, int t); //Recibe el id del usuario a cargar y también un int con el tipo de carga para saber si estamos validando en carga de Usuario o Entrenamiento.
///////////////////////////////////////////////////////////////////
bool guardar_usuario(Usuario, int);
int cantidadUsuarios();
int buscarUsuario(int);
Usuario leer_usuario(int);
void listar_usuarios_x_id();
bool modificar_usuario();

#endif // USUARIO_H_INCLUDED

