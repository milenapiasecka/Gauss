#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *readFromFile(char *fname) {
    int r, c;
    FILE *fin = fopen(fname, "r");
    Matrix *mat = NULL;

    if (fin != NULL) {
        fscanf(fin, "%d %d", &r, &c);
        mat = createMatrix(r, c);

        if (mat != NULL) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    fscanf(fin, "%lf", &mat->data[i][j]);
                }
            }
        } else {
            fprintf(stderr,
                "Blad tworzenia macierzy %dx%d z pliku %s\n",
                r, c, fname);
        }

        fclose(fin);
    } else {
        fprintf(stderr, "Nie moge otworzyc pliku: %s\n", fname);
    }

    return mat;
}

void printToScreen(Matrix *mat) {
    if (mat == NULL) return;

    printf("[\n");
    for (int i = 0; i < mat->r; i++) {
        printf(" ");
        for (int j = 0; j < mat->c; j++) {
            printf("%8.3f ", mat->data[i][j]);
        }
        printf("\n");
    }
    printf("]\n");
}

Matrix *createMatrix(int r, int c) {
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    if (mat == NULL) return NULL;

    mat->r = r;
    mat->c = c;
    mat->data = (double **)malloc(sizeof(double *) * r);

    if (mat->data == NULL) {
        free(mat);
        return NULL;
    }

    for (int i = 0; i < r; i++) {
        mat->data[i] = (double *)malloc(sizeof(double) * c);
        if (mat->data[i] == NULL) {
            for (int k = 0; k < i; k++)
                free(mat->data[k]);
            free(mat->data);
            free(mat);
            return NULL;
        }
    }

    return mat;
}

void freeMatrix(Matrix *mat) {
    if (mat == NULL) return;

    for (int i = 0; i < mat->r; i++)
        free(mat->data[i]);

    free(mat->data);
    free(mat);
}

