#include <iostream>
#include "registro.h"
#include "estudiante.h"
#define CL system("cls")
#define PA system("pause")
using namespace std;

    //clase estudiante: codigo, nombre, apellido, direccion, telefono.

    int main(int argc, char const *argv[])
    {
        int opcion;
        registro registro;


        do
        {
            CL;
            cout << "1. Introduzca el estudiante" << endl;
            cout << "2. Que estudiante desea ver" << endl;
            cout << "3. Desea modificar" << endl;
            cout << "4. Desea eliminar Estudiante" << endl;
            cout << "5. Salir" << endl;
            cout << "Seleccionar una opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                CL;
                int a, c;
                string n, d, t;
                cout <<"Introduzca el codigo: ";
                cin >> n;
                cout <<"Digite el nombre del Estudiante: ";
                cin >> c;
                cout <<"Digite los Apellidos: ";
                cin >> a;
                cout <<"Ingrese direccion: ";
                cin >> d;
                cout <<"Digitar telefono: ";
                cin >> t;
                Estudiante nueva = Estudiante();
                nueva.actualizar(c, _strdup(n.c_str()), a )
                registro.guardar(nueva);
                PA;
                break;
            case 2:
                CL;
                cout << " |DATOS| " << endl;
                registro.mostrar();
                PA;
                break;
            case 3:
                CL;
                int id;
                cout << "Modificacion de codigo de Estudiante: ";
                cin >> id;
                registro.modificar(id);
                PA;
                break;
            case 4:
                CL;
                int id;
                cout << "Eliminacion de codigo del Estudiante: ";
                registro.eliminar(id);

                PA;
                break;

            }

        }while(opcion != 5);
    }
