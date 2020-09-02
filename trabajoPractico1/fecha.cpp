#include <iostream>
using namespace std;
#include "fecha.h"
#include "usuario.h"

Fecha cargar_fecha(){ //Carga una fecha.
    Fecha reg;
    cout << "Día: ";
    cin >> reg.dia;
    cout << "Mes: ";
    cin >> reg.mes;
    cout << "Año: ";
    cin >> reg.anio;
    return reg;
}


void mostrar_fecha(Fecha reg){ //Muestra fecha de nacimiento
    cout << reg.dia << "/" << reg.mes << "/" << reg.anio << endl;
}

