#include <iostream>
#include <vector>
#include <conio.h> // Для функции _kbhit()
#include <windows.h> // Для функции Sleep()

using namespace std;

// Размеры поля
const int WIDTH = 10;
const int HEIGHT = 10;

// Состояния клеток
const int DEAD = 0;
const int ALIVE = 1;

// Правила игры жизни Конвея
int rules[10] = {
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0  // 0-8 соседей - правила игры жизни Конвея
};


// Инициализация поля
vector<vector<int>> field(HEIGHT, vector<int>(WIDTH, DEAD));

// Подсчет живых соседей клетки
int countNeighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Пропускаем саму клетку
            int neighborX = (x + i + WIDTH) % WIDTH; // Периодические граничные условия
            int neighborY = (y + j + HEIGHT) % HEIGHT;
            count += field[neighborY][neighborX];
        }
    }
    return count;
}

void updateField() {
    vector<vector<int>> newField(HEIGHT, vector<int>(WIDTH, DEAD));

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(i, j);
            newField[i][j] = rules[neighbors + 3 * field[i][j]]; // Индекс правила: 3 * текущее состояние + количество соседей
        }
    }

    field = newField;
}

// Отображение поля
void printField() {
    system("cls"); // Очистка консоли

    cout << "+";
    for (int i = 0; i < WIDTH; i++) {
        cout << "-";
    }
    cout << "+" << endl;

    for (int i = 0; i < HEIGHT; i++) {
        cout << "|";
        for (int j = 0; j < WIDTH; j++) {
            cout << (field[i][j] ? 'O' : ' ');
        }
        cout << "|" << endl;
    }
    cout << "+";
    for (int i = 0; i < WIDTH; i++) {
        cout << "-";
    }
    cout << "+" << endl;
}


// Основной цикл игры
int main() {
    // Инициализация поля случайными значениями
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            field[i][j] = rand() % 2;
        }
    }

    while (!_kbhit()) { // Продолжаем цикл, пока не нажата клавиша
        printField();
        updateField();
        Sleep(700); // Задержка в 0,1 секунды
    }

    return 0;
}
