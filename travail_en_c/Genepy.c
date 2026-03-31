//Hello World
#include <stdio.h>

int main(void) {
    printf("Hello World\n");
}

//Print 42
#include <stdio.h>

int main(void) {
    printf("42\n");
}

//Seconde dans une année
#include <stdio.h>

int main(void) {
    printf("%d\n", 60 * 60 * 24 * 365);
}

//Using operators
#include <stdio.h>

int main(void) {
    double i = 8958937768937.0 / 2851718461558.0;
    printf("%.15f\n", i);
    return 0;
}

//Find the bug
#include <stdio.h>
int main(void) {
    printf("Gonna knock three times:\n");
    for (int i = 0; i < 3; i = i + 1){
        printf("*knock*\n");
    }
    printf("- Who's there?\n");
}

//Fix is_Anagram
#include <stddef.h>

int is_anagram(const char *left, const char *right)
{
    int count[256] = {0};
    size_t i;

    for (i = 0; left[i] && right[i]; i++) {
        count[(unsigned char)left[i]]++;
        count[(unsigned char)right[i]]--;
    }

    if (left[i] != right[i])
        return 1;

    for (i = 0; i < 256; i++) {
        if (count[i] != 0)
            return 1;
    }
    return 0;
}

//Copie de fichier
#include <stdio.h>

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}
