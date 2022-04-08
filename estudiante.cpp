#include "estudiante.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>



Estudiante::Estudiante()
{
    this -> cod = 0;
    this -> dir = 0;
    this -> tel = 0;
    strncpy_s(this -> nom, "\0");
    strncpy_s(this -> ape, "\0");
}

void Estudiante::actualizar(int cod, char nom[30], char ape[30], int dir, int tel)
{
    this -> cod = c;
    this -> dir = d;
    this -> tel = t;
    strncpy_s(this -> nom, n);
    strncpy_s(this -> ape, a);

}

void Estudiante::imprimir()
{
    cout << "El Codigo: " << this -> cod << endl;
    cout << "Los Nombres: " << this -> nom << endl;
    cout << "Los Apellido: " << this -> ape << endl;
    cout << "La Direccion: " << this -> dir << endl;
    cout << " El Telefono: " << this -> tel << endl;

}

int Estudiante::obtenerCodigo()
{
    return this -> cod;
}
