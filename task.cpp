#include <iostream>

using namespace std;

void f(double* arr, int start, int end);

int main() {
    int len_str = 5, len_col = 4;
    const double matrix_val[4][5] = {{-0.77, -0.04, 0.21, -18, -1.24},
                                {0.25, -1.23, 0.16, -0.09, 1.12},
                                {-0.21, 0.16, 0.8, -0.13, 2.56},
                                {0.15, -1.31, 0.06, 1.12, -0.77}};
    for (int i = 0; i < len_col; i++) {
        
    }
    return 0;
}

void f(double* arr, int start, int end) {
    for (int i = start; i < end; i++) {
        if (arr[start] < 0) {
            arr[i] = arr[i] / arr[start] * (-1);
        }
        else {
            arr[i] = arr[i] / arr[start];
        }
    }
}

void s(double* first, double* second, int start, int end) {
    for (int i = start; i < end; i++) {
        second[i] -= first[i];
    }
}