#include <iostream>
using namespace std;
#include "fecha.h"

Fecha cargar_fecha(){
    Fecha reg;
    cout << "D�a: ";
    cin >> reg.dia;
    cout << "Mes: ";
    cin >> reg.mes;
    cout << "A�o: ";
    cin >> reg.anio;
    return reg;
}
void mostrar_fecha(Fecha reg){
    cout << reg.dia << "/" << reg.mes << "/" << reg.anio << endl;
}

