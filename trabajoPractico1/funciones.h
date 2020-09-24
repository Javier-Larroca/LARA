#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menuPrincipal();//Menu principal
void validaTecla(char t, bool *f, int *p, int m);//Valido la tecla que selecciono. Si es flecha arriba, flecha abajo o ENTER. Recibe el ultimo int para saber en que menú entrar
void menuUsuarios(); //SubMenu usuarios
void menuConfiguracion();// SubMenu configuracion
void menuEntrenamiento();//SubMenu entrenamiento
void modificarUsuario();//Pantalla para modificar el usuario
void menuReportes();//SubMenu reportes

#endif // FUNCIONES_H_INCLUDED
