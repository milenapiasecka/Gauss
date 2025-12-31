#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	if ( b->c != 1 || b->r != mat->r || x->r != mat->r || x->c != 1) { 
		return 2; 
	 }

    int n = mat->r;

    if (mat->r != mat->c || b->r != n || b->c != 1 || x->r != n || x->c != 1)
        return 2;

    for (int i = n - 1; i >= 0; i--) {

        if (mat->data[i][i] == 0.0)
            return 1;

        double sum = b->data[i][0];

        for (int j = i + 1; j < n; j++) {
            sum -= mat->data[i][j] * x->data[j][0];
        }

        x->data[i][0] = sum / mat->data[i][i];
    }

    return 0;
}






	



