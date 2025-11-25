#include <stdio.h>

int main() {

    int total;

    for (int i = 0; i <= 100; i++)
    {
        total = total + i;
    }

    printf("Total de 0 a 100 é %d\n", total);
    
    return 0;
}