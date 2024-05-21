#include <iostream>
#include <conio.h>
#include <random>

using namespace std;

int main() {
    int str_len, num_row, min_num = 51, max_num = -1, index_min, index_max;
    cin >> str_len >> num_row;
    int **matrix = new int *[num_row];
    for (int i = 0; i < num_row; i++) {
        matrix[i] = new int [str_len];
    }
    int newMatrix[2][num_row];

    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < str_len; j++) {
            matrix[i][j] = rand() % (50 - 10 + 1) + 10;
            if (matrix[i][j] < min_num) {
                newMatrix[0][i] = matrix[i][j];
                index_min = j;
                min_num = matrix[i][j];
            }
            if (matrix[i][j] > max_num) {
                newMatrix[1][i] = matrix[i][j];
                index_max = j;
                max_num = matrix[i][j];
            }
            cout << matrix[i][j] << " ";
        }
        swap(matrix[i][index_max], matrix[i][index_min]);
        min_num = 51;
        max_num = -1;
        cout << '\n';
    }

    cout << "--------\n";

    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < str_len; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }

    cout << "--------\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < str_len + 1; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << '\n';
    }

    for(int i = 0; i < num_row; i++)
        delete[] matrix[i];

    delete[] matrix;
    return 0;
}