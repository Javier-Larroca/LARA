#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

//Atributos Fecha
struct Fecha{
  int dia, mes, anio;
};

//Funciones Fecha
Fecha cargar_fecha();
Fecha validar_fecha(Fecha);
int edad(Fecha);
void mostrar_fecha(Fecha);

#endif // FECHA_H_INCLUDED

