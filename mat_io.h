#ifndef _MAT_IO_H
#define _MAT_IO_H

typedef struct _Matrix {
    int r, c;
    double **data;
} Matrix;

/* Wczytanie macierzy z pliku */
Matrix *readFromFile(char *fname);

/* Wypisanie macierzy na ekran */
void printToScreen(Matrix *mat);

/* Utworzenie macierzy */
Matrix *createMatrix(int r, int c);

/* Zwolnienie pamięci */
void freeMatrix(Matrix *mat);

#endif

