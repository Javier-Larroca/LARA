#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///Funciones Elmer
void validaOpcion(char o[], bool *f); //Valida y evalua la opci�n ingresada
void menuUsuarios(); //SubMenu usuarios
void menuConfiguracion();// SubMenu configuracion
void opcionSetearTodo(char *o);//Setea archivo de usuarios.dat (Jugue un poco con puntero y borrar el archivo, nada importante)
void modificarUsuario();//Pantalla para modificar el usuario
#endif // FUNCIONES_H_INCLUDED