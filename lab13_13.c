#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct my_set {
    unsigned int dt1[8];
} my_set;

my_set fill_my_set(char a)
{
    my_set emp1;
    memset(emp1.dt1, a && 1, 32);
    return emp1;
}

my_set char_to_my_set(char a)
{
    my_set ret1;
    memset(ret1.dt1, 0, 32);
    int code1 = (int)a;
    ret1.dt1[code1 / 32] |= (1 << (code1 % 32));
    return ret1;
}

my_set set_or1(my_set a, my_set b)
{
    my_set ret1;
    memset(ret1.dt1, 0, 32);
    for (int i = 0; i < 8; i++) {
        ret1.dt1[i] = a.dt1[i] | b.dt1[i];
    }
    return ret1;
}

my_set set_and1(my_set a, my_set b)
{
    my_set ret1;
    memset(ret1.dt1, 0, 32);
    for (int i = 0; i < 8; i++) {
        ret1.dt1[i] = a.dt1[i] & b.dt1[i];
    }
    return ret1;
}

my_set set_del1(my_set a, my_set b)
{
    my_set ret1;
    memset(ret1.dt1, 0, 32);
    for (int i = 0; i < 8; i++) {
        ret1.dt1[i] = a.dt1[i] & ~b.dt1[i];
    }
    return ret1;
}

char set_equal1(my_set a, my_set b)
{
    for (int i = 0; i < 8; i++) {
        if (a.dt1[i] != b.dt1[i]) {
            return 0;
        }
    }
    return 1;
}

my_set str_to_my_set(char *a)
{
    my_set ret1;
    memset(ret1.dt1, 0, 32);
    for (int i = 0; a[i]; i++) {
        ret1 = set_or1(ret1, char_to_my_set(a[i]));
    }
    return ret1;
}

void string_tolower(char *a)
{
    for (int i = 0; a[i]; i++) {
        a[i] = tolower(a[i]);
    }
}

int main(void)
{
    my_set bukvi1 = str_to_my_set("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm");
    my_set glasnie = str_to_my_set("euioa");
    my_set empty1 = fill_my_set(0);
    char *pass1 = 0;
    while (1) {
        char in1 = getchar();
        if (in1 == EOF) {
            break;
        }
        char isletter1 = !set_equal1(set_and1(char_to_my_set(in1), bukvi1), empty1);
        if (!isletter1 && pass1) {
            string_tolower(pass1);
            my_set curr1 = str_to_my_set(pass1);
            glasnie = set_del1(glasnie, curr1);
            free(pass1);
            pass1 = 0;
            continue;
        }
        if (isletter1) {
            int sl1 = pass1 ? strlen(pass1) : 0;
            pass1 = realloc(pass1, sl1 + 2);
            pass1[sl1] = in1;
            pass1[sl1 + 1] = 0;
        }
    }
    printf(set_equal1(glasnie, empty1) ? "No\n" : "Yes\n");
    return 0;
}

