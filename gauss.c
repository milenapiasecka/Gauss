#include "gauss.h"

/*
 * Eliminacja Gaussa bez wyboru elementu głównego.
 * Funkcja przekształca macierz A do postaci górnotrójkątnej
 * oraz modyfikuje wektor b.
 */
void gauss(double A[][10], double b[], int n) {
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double factor = A[i][k] / A[k][k];

            for (int j = k; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }
}

