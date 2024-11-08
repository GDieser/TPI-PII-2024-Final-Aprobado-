#include <iostream>
#include <cstring>

#include "ServicioEjercicio.h"
#include "Ejercicio.h"

using namespace std;

ServicioEjercicio::ServicioEjercicio()
{
    _archivoEjercicio = GestionArchivoEjercicios("archivoEjercicios.dat");
}

void ServicioEjercicio::verEjercicios()
{
    system("cls");
    Ejercicio ejercicio;
    int contador = 0;

    int cantidad = _archivoEjercicio.cantidadRegistrosEjercicios();

    cout << "+------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                        EJERCICIOS                                        |" << endl;
    cout << "+------------------------------------------------------------------------------------------+" << endl;

    for(int i=0; i<cantidad; i++)
    {
        ejercicio = _archivoEjercicio.leerRegistroEjercicio(i);

        cout << " " << i+1 << ". Nombre     : " << ejercicio.getNombreEjercicio() << endl;
        cout << "   ID          : #" << ejercicio.getIdEjercicio() << endl;
        cout << "   Descripcion : " << ejercicio.getDescripcion() << endl;
        cout << "+------------------------------------------------------------------------------------------+" << endl;
        contador++;
        if(contador%5 == 0)
        {
            cout << endl;
            cout << "Siguiente pagina..." << endl;
            system("pause");
            system("cls");
        }
    }

    cout << endl;
    system("pause");
}

void ServicioEjercicio::verEjercicio(int IdEjercicio)
{
    Ejercicio ejercicio;

    int pos = _archivoEjercicio.buscarEjercicio(IdEjercicio);

    ejercicio = _archivoEjercicio.leerRegistroEjercicio(pos);

    cout << " ID           : #" << ejercicio.getIdEjercicio() << endl;
    cout << " Nombre       : " << ejercicio.getNombreEjercicio() << endl;
}

void ServicioEjercicio::agregarEjercicio()
{
    system("cls");
    string nombre, descripcion;

    system("cls");
    cout << "+------------------------------------------+" << endl;
    cout << "|            AGREGAR EJERCICIO             |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << endl;
    cout << " Nombre del Ejercicio : ";
    cin.ignore();
    getline(cin, nombre);

    while(verificarEjercicioDuplicado(nombre))
    {
        cout << endl;
        cout << " Ejercicio ya existe en los registros " << endl;
        cout << " Nombre del Ejercicio : ";
        cin.ignore();
        getline(cin, nombre);

    }


    cout << endl;
    cout << " Descripcion          : ";
    getline(cin, descripcion);

    int idEjercicio = obtenerUltimoIdEjercicio();

    Ejercicio ejercicio(idEjercicio, nombre, descripcion);

    if(_archivoEjercicio.guardarEjercicio(ejercicio))
    {
        cout << endl;
        cout << " Ejercicio ID #" << idEjercicio << " guardado con exito." << endl;
    }
    else
    {
        cout << endl;
        cout << " Error de guardado, consulte con soporte." << endl;
    }
    cout << endl;

    system("pause");
}
void ServicioEjercicio::modificarEjercicio()
{
    system("cls");
    Ejercicio ejercicio;
    int idEjercicio;

    string nombre, descripcion;

    cout << "+--------------------------------------------+" << endl;
    cout << "|             MODIFICAR EJERCICIO            |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << endl;

    cout << " Ingrese ID del ejercicio a modificar: ";
    cin >> idEjercicio;

    int pos = _archivoEjercicio.buscarEjercicio(idEjercicio);

    if(pos != -1)
    {
        ejercicio = _archivoEjercicio.leerRegistroEjercicio(pos);

        cout << endl;
        cout << " Nombre: " << ejercicio.getNombreEjercicio() << endl;
        cout << " Descripcion: " << ejercicio.getDescripcion() << endl;
        system("pause");

        system("cls");
        cout << "+--------------------------------------------+" << endl;
        cout << "|             MODIFICAR EJERCICIO            |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << endl;
        cout << " Nombre del Ejercicio: ";
        cin.ignore();
        getline(cin, nombre);
        cout << endl;
        cout << " Descripcion: ";
        getline(cin, descripcion);

        ejercicio.setNombreEjercicio(nombre);
        ejercicio.setDescripcion(descripcion);

        if(_archivoEjercicio.guardarEjercicio(ejercicio, pos))
        {
            cout << endl;
            cout << " Modificacion realizada con exito" << endl;
        }
        else
        {
            cout << endl;
            cout << "Error inesperado, comuniquese con soporte." << endl;
        }
    }
    else
    {
        cout << endl;
        cout << " ID de ejercicio no encontrado" << endl;
    }

    system("pause");
}

int ServicioEjercicio::obtenerUltimoIdEjercicio()
{
    int cantidad = _archivoEjercicio.cantidadRegistrosEjercicios();

    if(cantidad != -1)
    {
        return cantidad+1;
    }
    else
    {
        return 1;
    }
}

///Que no acepte duplicados
bool ServicioEjercicio::verificarEjercicioDuplicado(string nombre)
{
    Ejercicio ejercicio;
    int cantidad = _archivoEjercicio.cantidadRegistrosEjercicios();

    if(cantidad < 0)
    {
        return false;
    }

    for(int i=0; i<cantidad; i++)
    {
        ejercicio = _archivoEjercicio.leerRegistroEjercicio(i);

        if(strcmp(nombre.c_str(), ejercicio.getNombreEjercicio().c_str()) == 0)
        {
            return true;
        }
    }

    return false;
}