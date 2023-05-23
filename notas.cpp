#include <iostream>

int main()
{
    int nota;

    // Solicitar al usuario que ingrese la nota
    std::cout << "Ingrese la nota del alumno: ";
    std::cin >> nota;

    // Evaluar la nota y mostrar el resultado correspondiente
    if (nota < 5)
    {
        std::cout << "El alumno está suspendido." << std::endl;
    }
    else if (nota == 5)
    {
        std::cout << "El alumno tiene un suficiente." << std::endl;
    }
    else if (nota == 6 || nota == 7)
    {
        std::cout << "El alumno tiene un bien." << std::endl;
    }
    else if (nota == 8)
    {
        std::cout << "El alumno tiene un notable." << std::endl;
    }
    else if (nota == 10)
    {
        std::cout << "El alumno tiene un sobresaliente." << std::endl;
    }
    else
    {
        std::cout << "La nota ingresada no es válida." << std::endl;
    }

    return 0;
}
