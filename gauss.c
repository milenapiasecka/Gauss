
#include "gauss.h"

/**
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa (dzielenie przez 0)
 */
int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r;

    /* Sprawdzenie poprawnych rozmiarów */
    if (mat->r != mat->c) return 1;
    if (b->r != n || b->c != 1) return 1;

    for (int k = 0; k < n - 1; k++) {

        /* Sprawdzenie elementu diagonalnego */
        if (mat->data[k][k] == 0.0) {
            return 1; // dzielenie przez zero
        }

        for (int i = k + 1; i < n; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];

            /* Zerowanie elementów pod diagonalą */
            for (int j = k; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }

            /* Modyfikacja wektora b */
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0;
}

