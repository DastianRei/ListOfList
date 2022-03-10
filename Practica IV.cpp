// Practica IV.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <fstream>
/*int main()
{
    string materia;
    string estudiante;
    ListaDeListas<string> list;
    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1--Insertar---" << endl;
        cout << "2--Mostrar--" << endl;
        cout << "3--Eliminar--" << endl;
        cout << "4--Buscar--" << endl;
        cout << "5--InsertarArchivos--" << endl;
        cout << "6--BuscarArchivo--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            cout << "Materia: "; cin >> materia;
            cout << "Estudiante: "; cin >> estudiante;
            list.insertarPrimero(materia, estudiante);
        }
        if (opcion == 2)
        {
            list.mostrar();
        }
        if (opcion == 3)
        {
            cout << "Materia: "; cin >> materia;
            cout << "Estudiante a Eliminar: "; cin >> estudiante;
            list.eliminar(materia, estudiante);
        }
        if (opcion == 4)
        {
            cout << "Materia: "; cin >> materia;
            cout << "Estudiante a Buscar: "; cin >> estudiante;
            string msg = list.buscar(materia, estudiante);
            cout << "el estudiante buscado es: " << msg << endl;
        }
        if (opcion == 5)
        {
            ifstream arch;
            string MBuscar = "BaseDatos";
            int cont = 0;
            arch.open("1.txt");
            while (!arch.eof())
            {
                arch >> materia;
                do
                {
                    arch >> estudiante;
                    if (estudiante != "#")
                    {
                        list.insertarPrimero(materia, estudiante);
                        if (MBuscar == materia)
                        {
                            cont += 1;
                        }
                    }

                } while (estudiante != "#");
            }
            arch.close();
           // cout << "La materia buscada tiene: " << cont << "estudiante";
        }
        if (opcion == 6)
        {
            ifstream arch;
            string MBuscar;
            cout << "Ingrese la materia a buscar estudiantes:";
            cin >> MBuscar;
            int cont = 0;
            arch.open("1.txt");
            while (!arch.eof())
            {
                arch >> materia;
                do
                {
                    arch >> estudiante;
                    if (estudiante != "#")
                    {
                        //list.insertarPrimero(materia, estudiante);
                        if (MBuscar == materia)
                        {
                            cont += 1;
                        }
                    }

                } while (estudiante != "#");
            }
            arch.close();

            cout << "La materia buscada tiene: " << cont << " estudiante" << endl;
        }

        } while (opcion != 7);
    }
    */
//EXAMPLE ListOfList
#include "ListOfList.h"
int main()
{
    ListOfList<int> list;//The list has to be the same type of Variable
    list.pushFront(1, 120);
    list.pushFront(1, 121);
    list.pushFront(1, 122);
    list.pushFront(2, 121);
    list.pushFront(2, 123);
    list.pushFront(2, 124);
    list.pushFront(2, 125);
    list.pushFront(2, 126);
    list.pushFront(3, 122);
    list.show();
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
