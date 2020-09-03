#include <iostream>
using namespace std;
#include "fecha.h"
#include "usuario.h"
#include <ctime>

Fecha validar_fecha(Fecha reg)
{
    bool band=true;
    Fecha actual;

    //Obtencion de fecha actual y guardado en un Struct de Fecha.
    time_t t = time( NULL );
    struct tm today = *localtime( &t );
    actual.mes =today.tm_mon + 1;
    actual.dia =today.tm_mday;
    actual.anio =(today.tm_year+1900);


    //Validacion de que el tipo de fecha ingresado sea correcto.
    if ( reg.mes >= 1 && reg.mes <= 12 )
    {
        switch ( reg.mes )
        {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 : if ( reg.dia < 1 || reg.dia > 31 ){
                          band=false;
                        }
            break;

            case  4 :
            case  6 :
            case  9 :
            case 11 : if ( reg.dia < 1 || reg.dia > 30 ){
                          band=false;
                        }
            break;

            case  2 : if( reg.anio%4==0 && (reg.anio%100!= 0 || reg.anio%400==0) ){
                        if ( reg.dia < 1 || reg.dia > 29 ){
                              band=false;
                            }
                     }
                     else{
                          if ( reg.dia < 1 || reg.dia > 28 ){
                              band=false;
                          }
                      }
            break;
        }
    }
    else{
        band=false;
    }
    //Finalizacion de validacion de fecha correcta.
    cout << actual.dia << "/" << actual.mes << "/" << actual.anio << endl;

    //Validacion de que la fecha no sea del futuro.
    if (reg.anio>actual.anio){
        band=false;
    }
    else{
        if (reg.anio==actual.anio){
            if (reg.mes>actual.mes){
                band=false;
            }
            else{
                if (reg.mes==actual.mes){
                    if (reg.dia>actual.dia){
                        band=false;
                    }
                }
            }
        }
    }
    //Fin de validacion de fecha del futuro

    //Validacion de que la bandera nunca haya cambiado, en caso de que haya cambiado vuelve a llamar a cargar_fecha
    if (band){
        return reg;
    }
    else{
        cout<<">Fecha incorrecta"<<endl;
        return cargar_fecha();
    }
}

Fecha cargar_fecha(){ //Carga una fecha.
    Fecha reg;
    cout << "D�a: ";
    cin >> reg.dia;
    cout << "Mes: ";
    cin >> reg.mes;
    cout << "A�o: ";
    cin >> reg.anio;
    return validar_fecha(reg);

    //return reg;
}

void mostrar_fecha(Fecha reg){ //Muestra fecha de nacimiento
    cout << reg.dia << "/" << reg.mes << "/" << reg.anio << endl;
}

