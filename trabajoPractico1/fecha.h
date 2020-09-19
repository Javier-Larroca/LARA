#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

//Atributos Fecha
struct Fecha{
  int dia, mes, anio;
};

//Funciones Fecha
Fecha cargar_fecha(int r);// Le paso un parametro para que haga validaciones acorde al tipo de registro que vamos a cargar (Usuario o Entrenamiento)
Fecha validar_fecha(Fecha, int r); //Al llamar a cargar_fecha en su función, le paso el mismo parametro de tipo de registro.
int edad(Fecha);
void mostrar_fecha(Fecha);

#endif // FECHA_H_INCLUDED

