#include <stdio.h>
#include <locale.h> // Necessário para configurar o locale

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); // ou "" para usar o locale do sistema

    printf("Digite um numero inteiro: ");
    int num1;
    scanf("%d", &num1);

    printf("Digite outro numero inteiro: ");
    int num2;
    scanf("%d", &num2);

    int op = num1 * num2;
    printf("A op de %d e %d é %d\n", num1, num2, op);

    return 0;
}
