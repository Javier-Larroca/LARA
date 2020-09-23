#ifndef ENTRENAMIENTO_H_INCLUDED
#define ENTRENAMIENTO_H_INCLUDED
#include "usuario.h"
#include "fecha.h"


//Atributos de un entrenamiento
struct Entrenamiento {
    int id; //Autonumerico
    int idUsuario;
    Fecha fechaDeEntrenamiento;
    int actividad;
    float calorias;
    int tiempo;
};

//Funciones para entrenamiento
Entrenamiento cargar_entrenamiento();//Carga un nuevo Entrenamiento
int validar_actividad(char *o, int a);//Valida actividad
void listar_entrenamientos(); //No se, empece a probar
void mostrar_datos_entrenamiento(Entrenamiento r);
bool guardar_entrenamiento(Entrenamiento);
int cantidad_entrenamientos();
int buscar_entrenamiento(int);
Entrenamiento leer_entrenamiento(int);
void listar_entrenamiento_x_id();
void listar_entranamiento_x_usuario();
int buscar_entrenamiento_x_usuario(int);
bool guardar_entrenamiento(Entrenamiento, int);
void modificar_entrenamiento_x_id();
#endif // ENTRENAMIENTO_H_INCLUDED
