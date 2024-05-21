#include <iostream>

using namespace std;

int main() {
    int str_len, num_row, sum_str = 0, max_sum = 0, max_str = -1;
    cin >> str_len >> num_row;

    int **matrix = new int *[num_row];
    for (int i = 0; i < num_row; i++) {
        matrix[i] = new int [str_len];
    }

    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < str_len; j++) {
            matrix[i][j] = rand() % (200 - 100 + 1) + 100;
            sum_str += matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << endl;
        if (sum_str > max_sum) {
            max_sum = sum_str;
            max_str = i;
        }
        sum_str = 0;
    }

    cout << "Maximum amount " << max_sum << "\nLine " << max_str;

    for(int i = 0; i < num_row; i++)
        delete[] matrix[i];

    delete[] matrix;
    return 0;
}