#include <iostream>
#include <thread>
#include <windows.h>
#include <mutex>
using namespace std;
mutex m;

bool guanyador = false;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void moverCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

void funcio1() {
    for(int i = 0; i < 50 && !guanyador; i++) {
        
        m.lock();
        moverCursor(20 + i * 1, 2);
        cout << "*";
        m.unlock();
        

        if (rand() % 2 == 0) {
            Sleep(700);
        } else {
            Sleep(350);
        }
    }

    if (!guanyador) {
        guanyador = true;
        moverCursor(0, 8);
        cout << "El gorilla ha guanyat!";
    }
}

void funcio2() {
    for(int i = 0; i < 50 && !guanyador; i++) {
        
        m.lock();
        moverCursor(20 + i * 1, 4);
        cout << "*";
        m.unlock();

        if (rand() % 2 == 0) {
            Sleep(650);
        } else {
            Sleep(400);
        }
    }

    if (!guanyador) {
        guanyador = true;
        moverCursor(0, 8);
        cout << "El cangur ha guanyat!";
    }
}

void funcio3() {
    for(int i = 0; i < 50 && !guanyador; i++) {
        
        m.lock();
        moverCursor(20 + i * 1, 6);
        cout << "*";
        m.unlock();

        if (rand() % 2 == 0) {
            Sleep(750);
        } else {
            Sleep(325);
        }
    }

    if (!guanyador) {
        guanyador = true;
        moverCursor(0, 8);
        cout << "La jirafa ha guanyat!";
    }
}

int main() {
    system("cls");
    cout << "La carrera d'animals salvatges comensa!!\n";
    moverCursor(0, 2);
    cout << "Gorila: ";
    moverCursor(0, 4);
    cout << "Canguro: ";
    moverCursor(0, 6);
    cout << "Jirafa: ";

    thread fil1(funcio1);
    thread fil2(funcio2);
    thread fil3(funcio3);

    fil1.join();
    fil2.join();
    fil3.join();

    moverCursor(0, 10);
    cout << "Programa multithreading finalizado.";

    return 0;
}
