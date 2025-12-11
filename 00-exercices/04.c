#include <stdio.h>

int sum(int *num1, int *num2) {
    return *num1 + *num2;
}

int sub(int *num1, int *num2) {
    return *num1 - *num2;
}

int mul(int *num1, int *num2) {
    return *num1 * *num2;
}

int divi(int *num1, int *num2) {
    if (*num2 == 0) {
        printf("Erro: Divisao por zero!\n");
        return 0;
    }
    return *num1 / *num2;
}

int main() {
    int condition;
    int a, b;

    do {
        printf("\n1-Soma\n2-Subtracao\n3-Divisao\n4-Multiplicacao\n5-Sair\n");
        scanf("%d", &condition);

        if (condition >= 1 && condition <= 4) {
            printf("Digite o primeiro numero: ");
            scanf("%d", &a);

            printf("Digite o segundo numero: ");
            scanf("%d", &b);
        }

        switch (condition) {
            case 1:
                printf("Resultado: %d\n", sum(&a, &b));
                break;
            case 2:
                printf("Resultado: %d\n", sub(&a, &b));
                break;
            case 3:
                printf("Resultado: %d\n", divi(&a, &b));
                break;
            case 4:
                printf("Resultado: %d\n", mul(&a, &b));
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Operacao invalida!\n");
        }

    } while (condition != 5);
    
    return 0;
}
