#include <iostream>

using namespace std;

void line_div(long double *mas, int start, int end, long double line);
void line_sub(long double *first, long double *second, int start, int end);

int main() {
    int len_str = 5, len_col = 4, ind = 0;
    double matrix_val[4][5] = {{-0.77, -0.04, 0.21, -18, -1.24},
                                {0.25, -1.23, 0.16, -0.09, 1.12},
                                {-0.21, 0.16, 0.8, -0.13, 2.56},
                                {0.15, -1.31, 0.06, 1.12, -0.77}};
    long double new_matrix[len_col][len_str];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            new_matrix[i][j] = matrix_val[i][j];
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;;

    while (ind < 4) {
        line_div(new_matrix[ind], ind, len_str, new_matrix[ind][ind]);
        for (int i = ind + 1; i < len_col; i++) {
            line_sub(new_matrix[ind], new_matrix[i], ind, len_str);
        }
        ind++;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void line_div(long double *mas, int start, int end, long double line) {
    for (int i = start; i < end; i++) {
        mas[i] /= line;
    }
}

void line_sub(long double *first, long double *second, int start, int end) {
    for (int i = start; i < end; i++) {
        second[i] -= (first[i] * second[start]);
    }
}