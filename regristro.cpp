#include "registro.h"
#include <iostream>


void registro::guardar(Estudiante estudiante)
{
    this -> archivo.open("estudiantes.dat", ios::out | ios::app);
    if (this -> archivo.fail())
    {
        cout << "No es posible abrir el archivo" << endl;
    }
    else
    {
        this -> archivo.write((char*)&estudiante, sizeof(Estudiante));
        this -> archivo.close();
        cout << "Se guardo el estudiante exitosamente..." << endl;
    }
}

void registro::mostrar()
{
    Estudiante mostrar = Estudiante();
    this -> archivo.open("estudiantes.dat", ios::in);
    if (this -> archivo.fail())
    {
        cout << "Imposible abrir el archivo..." << endl;
    }
    else
    {
        while (!this -> archivo.eof())
        {
            this -> archivo.read((char*)&mostrar, sizeof(Estudiante));
            if (!this -> archivo.eof())
            {
                mostrar.imprimir();
            }
        }
        this -> archivo.close();
    }
}

void registro::modificar(int codigo)
{
    bool encontrado = false;
    Estudiante aux;
    ifstream lectura; ofstream escritura;
    lectura.open("estudiantes.dat", ios::in);
    escritura.open("aux.dat", ios::app);
    if (lectura.fail() || escritura.fail())
    {
        cout << "Imposible abrir el archivo..." << endl;
    }
    else
    {
        while(lectura.read((char*)&aux, sizeof(aux)))
        {
            if (aux.obtenerCodigo() == codigo)
            {
                encontrado = true;
                int a, c;
                string n;
                cout <<"Digite de nuevo el Codigo: ";
                cin >> n;
                cout <<"Digite de nuevo los Nombre: ";
                cin >> c;
                cout <<"Digite de nuevo los Apellidos: ";
                cin >> a;
                aux.actualizar(c, _strdup(n.c_str(), a);
                escritura.write((char*)&aux, sizeof(aux));
            }
            else
            {
                escritura.write((char*)&aux, sizeof(aux));
            }
        }
        lectura.close();
        escritura.close();
        remove("estudiantes.dat");
        if (rename("aux.dat", "estudiantes.dat"))
        {
            cout << "Renombrar el archivo es imposible..." << endl;
        }
        if (!encontrado) {
            cout << "No se encontro el estudiante" << endl;
        }else {
            cout << "Se modifico el estudiante" << endl;
        }
    }
}



void registro::eliminar(int codigo)
{
      bool encontrado = false;
    Estudiante aux;
    ifstream lectura; ofstream escritura;
    lectura.open("estudiantes.dat", ios::in);
    escritura.open("aux.dat", ios::app);
    if (lectura.fail() || escritura.fail())
    {
        cout << "Imposible abrir el archivo..." << endl;
    }
    else
    {
        while(lectura.read((char*)&aux, sizeof(aux)))
        {
            if (aux.obtenerCodigo() != codigo)
            {
                escritura.write((char*)&aux, sizeof(aux));
            }
            else
            {
               encontrado = true;
            }
        }
        lectura.close();
        escritura.close();
        remove("estudiantes.dat");
        if (rename("aux.dat", "estudiantes.dat"))
        {
            cout << "No se renombro el Estudiante" << endl;
        }
        if (!encontrado) {
            cout << "El Estudiante no fue encontrado" << endl;
        }else {
            cout << "Se modifico el Estudiante" << endl;
        }
    }

}
