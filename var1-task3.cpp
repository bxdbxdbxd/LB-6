#include <iostream>

using namespace std;

void div_str_matr(double (&mas)[4][5], int elem, int col, int len);
void line_subtrac(double (&mas)[4][5], int first, int second, int len);

int main() {
    int len_str = 5, len_col = 4;
    const double matrix_val[4][5] = {{-0.77, -0.04, 0.21, -18, -1.24},
                                {0.25, -1.23, 0.16, -0.09, 1.12},
                                {-0.21, 0.16, 0.8, -0.13, 2.56},
                                {0.15, -1.31, 0.06, 1.12, -0.77}};
    double new_matrix[4][5];
    for (int  i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            new_matrix[i][j] = matrix_val[i][j] / matrix_val[i][0];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < len_col -1; i++) {
        for (int j = i + 1; j < len_col; j++) {
            line_subtrac(new_matrix, i, j, len_str);
        }
        div_str_matr(new_matrix, i+1, i+1, len_str);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


void div_str_matr(double (&mas)[4][5], int elem, int col, int len) {
    for (int i = elem; i < len; i++) {
        if (mas[col][elem] < 0) {
            mas[col][i] /= mas[col][elem] * (-1);
            }
        else {
            mas[col][i] /= mas[col][elem];
        }
    }
}

void line_subtrac(double (&mas)[4][5], int first, int second, int len) {
    for (int i = 0; i < len; i++) {
        mas[second][i] = mas[second][i] - mas[first][i]*mas[second][0];
    }
}