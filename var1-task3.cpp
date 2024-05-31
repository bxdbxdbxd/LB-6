#include <iostream>

using namespace std;

void div_str_matr(double mas, int elem);
void line_subtrac(double* first_str, double* second_str, int elem);

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
    return 0;
}


void div_str_matr(double* mas, int elem) {
    for (int i = elem; i < 5; i++) {
        mas[i] /= mas[elem];
    }
}

