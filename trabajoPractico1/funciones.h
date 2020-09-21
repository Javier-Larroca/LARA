#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void validaOpcion(char o[], bool *f); //Valida y evalua la opción ingresada
void menuUsuarios(); //SubMenu usuarios
void menuConfiguracion();// SubMenu configuracion
void menuEntrenamiento();//SubMenu entrenamiento
void opcionSetearTodo(char *o);//Setea archivo de usuarios.dat (Jugue un poco con puntero y borrar el archivo, nada importante)
void modificarUsuario();//Pantalla para modificar el usuario
//void gotoxy(int x, int y);// Armo función Gotoxy
#endif // FUNCIONES_H_INCLUDED
