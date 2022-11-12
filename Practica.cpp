// Crear un archivo que almacene datos de estudiantes: Nombre, Carne, Carrera por medio de un struct
// Que estos datos sean almacenados en un fichero externo
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

// Variable struct para el manejo de varios datos
struct Nodo
{
    string Nombre;
    string Carnet;
    struct Nodo *siguiente;
} personas;

// Iniciando valor de la lista
struct Nodo *lista = NULL;

// Funciones que solicitan los datos
void insertar_Datos();                          // Pide los datos y almaneca en fichero (archivo.txt)
void Struct_Asignacion(string Name, string ID); // Toma los datos y los guarda a un struct
// Lectura de ficheros
void Lectura_Datos(); // lee los datos de los ficheros

int main()
{
    // Menu
    int opc;
    bool continuar = true;

    do
    {
        // opciones
        cout << "1. Insertar elementos " << endl;
        cout << "2. Mostrar elementos " << endl;
        cout << "3. Salir " << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            insertar_Datos();
            Struct_Asignacion(personas.Nombre, personas.Carnet);
            system("pause");
            break;
        case 2:
            Lectura_Datos();
            system("pause");
            break;

        case 3:
            cout << "Adios" << endl;
            system("pause");
            continuar = false;
            break;

        default:
            break;
        }
        system("cls");
    } while (continuar);
    return 0;
}
void insertar_Datos()
{
    ofstream Nombres_Archivo, Carnet_Archivo; // Variable para poner las direcciones de los .txt
    string Estudiante;                        // Variable que almacena Nombres de los ficheros
    string ID;                                // Variable que almacena los carnet de los estudiantes del fichero

    // Varible asignada a el archivo ("Nombre del archivo en cuestion", Funcion del fichero en este caso Escritura)
    Nombres_Archivo.open("Estudiantes.txt", ios::app);
    Carnet_Archivo.open("Carnet.txt", ios::app);

    // Condicional por si los archivos no se encuentran o estan dañados
    if (Nombres_Archivo.fail() && Carnet_Archivo.fail())
    {
        cout << "error" << endl;
        exit(1);
    }

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, Estudiante);
    cout << "Carnet: ";
    getline(cin, ID);

    // guarda los datos en el fichero
    Nombres_Archivo << Estudiante << endl;
    Carnet_Archivo << ID << endl;

    // se cierran los archivos
    Nombres_Archivo.close();
    Carnet_Archivo.close();
}
void Lectura_Datos()
{
    ifstream Nombres_Archivo, Carnet_Archivo;
    string D_Nombre, D_Carnet;

    // Apertura de archivos para lectura
    Nombres_Archivo.open("Estudiantes.txt", ios::in);
    Carnet_Archivo.open("Carnet.txt", ios::in);

    // Comprobando existencia de archivos
    if (Nombres_Archivo.fail() && Carnet_Archivo.fail())
    {
        cout << "Error en la apertura de archivos" << endl;
        exit(1);
    }

    // Recorriendo contenidos de los txt
    while (!Nombres_Archivo.eof() && !Carnet_Archivo.eof())
    {
        // Recibiendo datos de los ficheros
        getline(Nombres_Archivo, D_Nombre);
        getline(Carnet_Archivo, D_Carnet);

        // Imprimiendo datos de los ficheros
        cout << "Estudiante: " << D_Nombre << "Carnet: " << D_Carnet << endl;
    }

    Nombres_Archivo.close();
}
void Struct_Asignacion(string Name, string ID)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;

    if (nuevoNodo != NULL)
    {
        nuevoNodo->Nombre = Name;
        nuevoNodo->Carnet = ID;
        nuevoNodo->siguiente = NULL;

        if (lista == NULL)
        {
            lista = nuevoNodo;
            cout << "Elemento agregado " << endl;
        }
        else
        {
            while (temporal->siguiente != NULL)
            {
                temporal = temporal->siguiente;
            }
            temporal->siguiente = nuevoNodo;
            cout << "Elemento agregado" << endl;
        }
    }
}
