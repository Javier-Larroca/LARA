#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void generarBackUp(); //Genera archivo de backup, recibe un pin global = 0.
void generarPin(int *pin); //Genera y asigna pin para realizar copia de seguridad
int numeroAleatorio(); //Genera numero aleatorio
void validaTeclaConf(char t, bool *f, int *p, int *pin, int opcion); //Valida tecla para Configuración ya que solo tienen 3 opciones. Si recibe opcion =1 genera backup, si es 2 lo restaura
void generarArchivoSeg(int *pin); //Genera archivos de seguridad. Pin generado
void restaurarBackUp(); //Restaura backup, recibe un pin global = 0
void restaurarArchivoSeg(int *pin); //Restaura archivos de seguridad
void buscoArchivos(); //Busca los archivos y despues llama a guardoArchivos para guardar todos los registros en BKP.
bool guardoArchivoUsuario(Usuario *u, int c);//Recibe 1 vector de Usuario para guardarlo en el archivo
bool guardoArchivoEntrenamiento(Entrenamiento *e, int c);//Recibe 1 vector de Entrenamiento para guardarlo en el archivo
bool restauroArchivoUsuario(); //Restaura los archivos de usuarios de backup. Si no fueron generados emite mensaje de advertencia
bool restauroArchivoEntrenamiento(); //Restaura los archivos de entrenamiento de backup. Si no fueron generados emite mensaje de advertencia
#endif // CONFIGURACION_H_INCLUDED
