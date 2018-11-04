#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

string contrasena2 = "";
string contrasena = "";
string contrasena1 = "";
int retorno;

void crear();
void menu();
int leer();

int main()
{
    retorno = leer();
    if(retorno == 1)
    {
        crear();
    }

    cout <<" Cual es la contrasena? " <<endl;
    cout <<" ===> ";
    cin >> contrasena1;
    if(contrasena == contrasena1)
    {
        cout <<" La contrasena funciona" <<endl;
        menu();
    }
    else{
        cout <<" Contrasena incorrecta. Vuelva a intentarlo" <<endl;
        system("PAUSE");
    }

    return 0;
}

int leer()
{
    cout <<" Buscando fichero de contrasena" <<endl;
    ifstream lectura;
    lectura.open("contrasena.txt", ios::in);
    if(lectura.fail())
    {
        cout <<" Debe crear un archivo de contrasena. A continuacion se le ejecutara el asistente" <<endl;
        system("PAUSE");
        return 1;
    }
    while(!lectura.eof())
    {
        getline(lectura, contrasena);
    }
    lectura.close();
    return 0;
}

void crear()
{
    cout <<" Cual sera la contrasena? " <<endl;
    cout <<" ===> ";
    cin >> contrasena2;

    ofstream creacion;
    creacion.open("contrasena.txt", ios::out);
    if(creacion.fail())
    {
        cout <<" No se ha podido inicializar los datos" <<endl;
        system("PAUSE");
        exit(1);
    }
    creacion <<contrasena2;
    creacion.close();
    cout <<" Archivo creado correctamente. Reinicie la app para probar el sistema" <<endl;
    system("PAUSE");
    exit(0);
}

void menu()
{
    int op = 0;
    cout <<endl;
    cout <<" Que desea hacer?" <<endl;
    cout <<" 1.Cambiar contrasena" <<endl;
    cout <<" 2.Salir" <<endl;
    cout <<" ===> ";
    cin >> op;
    switch(op)
    {
        case 1:{
            crear();
        }
        break;
        case 2:{
            system("PAUSE");
            exit(0);
        }
        break;
        default:{
            cout <<" Opcion incorrecta" <<endl;
            system("PAUSE");
        }
    }
}