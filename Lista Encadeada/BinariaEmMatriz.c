#include <stdio.h>

int BuscaBinariaMatriz(int L[][3], int x, int n) {
    int left = 0;
    int right = n * n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int midValue = L[mid / n][mid % n];

        if (midValue == x) {
            return 1; // Valor encontrado
        } else if (midValue < x) {
            left = mid + 1; // Descarta a metade inferior
        } else {
            right = mid - 1; // Descarta a metade superior
        }
    }

    return -1; // Valor não encontrado
}

int main() {
    int lista[3][3] = {{1, 2, 3}, {4, 5, 6}, {9, 11, 13}};

    int resultado = BuscaBinariaMatriz(lista, 6, 3);
    if (resultado == 1) {
        printf("Valor encontrado na matriz\n");
    } else {
        printf("Valor não encontrado\n");
    }

    return 0;
}

