#include <iostream>
using namespace std;
#include "usuario.h"

void mostrar_usuario(Usuario reg){
    cout << "ID         : " << reg.id << endl;
    cout << "Nombres    : " << reg.nombres<< endl;
    cout << "Apellidos  : " << reg.apellidos << endl;
    cout << "Nacimiento : ";
    mostrar_fecha(reg.nac);
    cout << "Altura     : " << reg.altura << " cms"<< endl;
    cout << "Peso       : " << reg.peso << " kgs"<< endl;
    cout << "Perfil     : " << reg.perfilActividad << endl;
    cout << "Apto medico: " << reg.aptoMedico << endl;
}
/*
int buscar_usuario(int id_buscado){
    Usuario reg;
    FILE *f;
    int pos=0;
    f = fopen("datos/usuarios.dat", "rb");
    if (f == NULL){
        return -1;
    }
    while(fread(&reg, sizeof(Usuario), 1, f)){
        if (id_buscado == reg.id){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}

*/
Usuario cargar_usuario(){
    Usuario a, *aux;
    aux = &a;

    int id, pos, apto;
    cout << "ID   : ";
    cin >> id;
    /*
    while(!(id >= 1000 && codigo <= 9999)){
        cout << "> Código   : ";
        cin >> codigo;
    }
    **/
    /*
    // Validamos el ID que no se repita en la lista
    while (buscar_usuario(id) >= 0){
        cout << "> ID   : ";
        cin >> id;
    }
    // Fin de la validación de id
    */
    aux->id = id;
    cout << "Nombres  : ";
    cin.ignore();
    cin.getline(aux->nombres, 50);
    cout << "Apellidos: ";
    cin.getline(aux->apellidos, 50);
    cout << "Fecha de nacimiento: ";
    cin >> aux->nac.dia;
    cin >> aux->nac.mes;
    cin >> aux->nac.anio;

    cout<< "Altura   : ";
    cin >> aux->altura;
    cout << "Peso: ";
    cin >> aux->peso;

    cout << "Perfil actividad   : ";
    cin >> aux->perfilActividad;
    /// "toupper" convierte un caracter de minuscula a mayuscula.
    while (toupper(aux->perfilActividad) != 'A' && toupper(aux->perfilActividad) != 'B' && toupper(aux->perfilActividad) != 'C'){
        cout << endl <<  "> Perfil Actividad   : " ;
        cin >> aux->perfilActividad;
    }
    cout << "Apto medico: ";
    cin >> apto;
    while (apto != 0 && apto != 1 ){
        cout << endl <<  "> Apto medico  : " ;
        cin >> apto;
    }
    aux->aptoMedico = apto;
    //No se si esta bien esta asignacion

    aux->estado = true;

    return a;
}

/*
void listar_usuarios(){
    Usuario reg;
    FILE *f;
    int aux;
    f = fopen("datos/usuarios.dat", "rb");
    if (f == NULL){
        cout << "No se puede leer el archivo.";
        return;
    }
    while(fread(&reg, sizeof(Usuario), 1, f)){
        mostrar_usuario(reg);
        cout << endl;
    }
    fclose(f);
}
*/

/*
bool guardar_usuario(Usuario reg){
    bool grabo;
    FILE *f;
    f = fopen("datos/usuarios.dat", "ab");
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&reg, sizeof(Usuario), 1, f);
    fclose(f);
    return grabo;
}
*/

