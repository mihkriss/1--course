#include <stdio.h>

int main(void) {
    int c, first, second;
    int i = 0;
    int m = 0;
    while((c = getchar()) != EOF) {
        if (i == 0) {
            second = c;
            first = c;
            c = getchar();
            i += 1;
        }
        if (c == first) {
            while (((c != ' ') || (c != '\n')) && (m == 0)) {
                c = getchar();
                if (c == ' ') {
                    printf("False\n");
                    i = 0;
                    m += 1;
                    continue;
                } else if (c == '\n') {
                    printf("False\n");
                    m += 1;
                    continue;
                }
            }
            m = 0;
        } else {
            if ((c == ' ') || (c == '\n')) {
                if (c == ' ') {
                    printf("True\n");
                    i = 0;
                } else {
                    printf("True\n");
                }
            }
            second = first;
            first = c;
            continue;
        }
    }
}