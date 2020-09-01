#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "fecha.h"

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

Usuario cargar_usuario();
void mostrar_usuario(Usuario);

int buscar_usuario(int);
void listar_usuarios();
bool guardar_usuario(Usuario);


#endif // USUARIO_H_INCLUDED

