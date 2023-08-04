#include <stdio.h>
#include <stdlib.h>

int busca(int n, int x, int l[][2]);

int main() {
	int l[2][2] = {{2, 4}, {7, 8}};
	printf("%d",busca(2, 33, l));
	return 0;
}

int busca(int n, int x, int l[][2]) {
	int i, j;
	if (n > 0) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (l[i][j] == x) {
					return 2;
				}
			}
		}
	}
	return 1;
}
