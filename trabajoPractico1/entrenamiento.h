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
void mostrar_datos_entrenamientos(Entrenamiento r);
bool guardar_entrenamiento(Entrenamiento);
int cantidad_entrenamientos();
#endif // ENTRENAMIENTO_H_INCLUDED
