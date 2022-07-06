#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int t;
    int n;
    scanf("%d %d\n", &t, &n);
    int arr[n][n];
    for (int test = 0; test < t; test++) {
        scanf("%d\n", &n);
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                scanf("%d", &arr[x][y]);
            }
        }
        char first = 1;
        for (int i = 0; i < n + n - 1; i++) {
            int x = 0;
            int y = 0;
            if (i < n) {
                x = n - i - 1;
            } else {
                y = i - n + 1;
            }
            if (i % 2 == 0) {
                for (int i1 = 0; i1 < n - max(x, y); i1++) {
                    printf(first ? "%d" : " %d", arr[x + i1][y + i1]);
                }
            } else {
                for (int i1 = n - max(x, y) - 1; i1 >= 0; i1--) {
                    printf(first ? "%d" : " %d", arr[x + i1][y + i1]);
                }
            }
            first = 0;
        }
        printf("\n");
    }
    return 0;
}

