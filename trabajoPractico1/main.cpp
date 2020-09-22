#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string.h>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "funciones.h"
using namespace std;
//#include "ui.h"
//#include "rlutil.h"
//using namespace rlutil;

int main(){
    setlocale(LC_ALL, "Spanish");
    system("color 1A");
    SetConsoleTitle("   -    LARA   -   ");
    //initUI();
    //title("", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    menuPrincipal();
    return 0;
}
