#include <iostream>        // Biblioteca para entrada/salida estándar.
#include <thread>          // Biblioteca para manejar hilos (threads).
#include <windows.h>       // Biblioteca para funciones específicas de Windows.
#include <mutex>           // Biblioteca para manejar exclusión mutua (mutex).
using namespace std;       // Utiliza el espacio de nombres estándar.

mutex m;                  // Crea un mutex para proteger el acceso a la consola.
bool guanyador = false;   // Variable que indica si ya hay un ganador.
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtiene el manejador de la consola.

void moverCursor(int x, int y) {
    COORD coord;         // Estructura para coordenadas del cursor.
    coord.X = x;        // Asigna la posición X.
    coord.Y = y;        // Asigna la posición Y.
    SetConsoleCursorPosition(hConsole, coord); // Mueve el cursor a la posición especificada.
}

void funcio1() {        // Función para el gorila.
    for(int i = 0; i < 50 && !guanyador; i++) { // Bucle para avanzar en la carrera.
        m.lock();                // Bloquea el mutex para acceso exclusivo.
        moverCursor(20 + i * 1, 2); // Mueve el cursor para el gorila.
        cout << "*";            // Imprime un asterisco para el avance.
        m.unlock();             // Desbloquea el mutex.

        // Espera un tiempo aleatorio para simular el movimiento.
        if (rand() % 2 == 0) {
            Sleep(700);         // Espera 700 ms si el número es par.
        } else {
            Sleep(350);         // Espera 350 ms si el número es impar.
        }
    }

    if (!guanyador) {          // Si no hay ganador, declara al gorila ganador.
        guanyador = true;
        moverCursor(0, 8);     // Mueve el cursor para imprimir el mensaje.
        cout << "El gorilla ha guanyat!"; // Mensaje de victoria del gorila.
    }
}

void funcio2() {        // Función para el canguro.
    for(int i = 0; i < 50 && !guanyador; i++) { // Bucle para avanzar en la carrera.
        m.lock();                // Bloquea el mutex para acceso exclusivo.
        moverCursor(20 + i * 1, 4); // Mueve el cursor para el canguro.
        cout << "*";            // Imprime un asterisco para el avance.
        m.unlock();             // Desbloquea el mutex.

        // Espera un tiempo aleatorio para simular el movimiento.
        if (rand() % 2 == 0) {
            Sleep(650);         // Espera 650 ms si el número es par.
        } else {
            Sleep(400);         // Espera 400 ms si el número es impar.
        }
    }

    if (!guanyador) {          // Si no hay ganador, declara al canguro ganador.
        guanyador = true;
        moverCursor(0, 8);     // Mueve el cursor para imprimir el mensaje.
        cout << "El cangur ha guanyat!"; // Mensaje de victoria del canguro.
    }
}

void funcio3() {        // Función para la jirafa.
    for(int i = 0; i < 50 && !guanyador; i++) { // Bucle para avanzar en la carrera.
        m.lock();                // Bloquea el mutex para acceso exclusivo.
        moverCursor(20 + i * 1, 6); // Mueve el cursor para la jirafa.
        cout << "*";            // Imprime un asterisco para el avance.
        m.unlock();             // Desbloquea el mutex.

        // Espera un tiempo aleatorio para simular el movimiento.
        if (rand() % 2 == 0) {
            Sleep(750);         // Espera 750 ms si el número es par.
        } else {
            Sleep(325);         // Espera 325 ms si el número es impar.
        }
    }

    if (!guanyador) {          // Si no hay ganador, declara a la jirafa ganadora.
        guanyador = true;
        moverCursor(0, 8);     // Mueve el cursor para imprimir el mensaje.
        cout << "La jirafa ha guanyat!"; // Mensaje de victoria de la jirafa.
    }
}

int main() {
    system("cls");           // Limpia la consola.
    cout << "La carrera d'animals salvatges comensa!!\n"; // Mensaje de inicio.

    // Inicializa la posición de cada animal.
    moverCursor(0, 2);       // Posición del gorila.
    cout << "Gorila: ";       // Texto para el gorila.
    moverCursor(0, 4);       // Posición del canguro.
    cout << "Canguro: ";      // Texto para el canguro.
    moverCursor(0, 6);       // Posición de la jirafa.
    cout << "Jirafa: ";       // Texto para la jirafa.

    // Crea hilos para cada función (cada animal).
    thread fil1(funcio1);    // Hilo para el gorila.
    thread fil2(funcio2);    // Hilo para el canguro.
    thread fil3(funcio3);    // Hilo para la jirafa.

    // Espera a que los hilos terminen su ejecución.
    fil1.join();
    fil2.join();
    fil3.join();

    moverCursor(0, 10);      // Mueve el cursor para el mensaje final.
    cout << "Programa multithreading finalizado."; // Mensaje de finalización.

    return 0;                // Fin del programa.
}
