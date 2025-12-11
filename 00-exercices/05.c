#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necessário para usar time() como semente

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para embaralhar o array usando o algoritmo de Fisher-Yates
void shuffle(int arr[], int n) {
    // Inicializa o gerador de números aleatórios com a hora atual
    // para garantir uma sequência diferente a cada execução
    srand(time(NULL));

    // Percorre o array do último elemento ao segundo
    for (int i = n - 1; i > 0; i--) {
        // Escolhe um índice aleatório 'j' de 0 a 'i'
        // A expressão (rand() % (i + 1)) garante que o índice esteja dentro do intervalo [0, i]
        int j = rand() % (i + 1);

        // Troca o elemento atual (arr[i]) pelo elemento aleatório (arr[j])
        swap(&arr[i], &arr[j]);
    }
}

void guessingGame(int indice1, int indice2, int *arr, int len){

    if (indice1 > len || indice2 > len)
    {
        printf("Indices ultrapassam tamanho do array!\n");
        return;
    }

    printf("\n");
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    if (arr[indice1] == arr[indice2])
    {
        printf("\nParabens! Voce encontrou um par: %d e %d\n", arr[indice1], arr[indice2]);
    }
    else
    {
        printf("\nTente novamente! %d e %d nao formam um par.\n", arr[indice1], arr[indice2]);
    }
}


// Função principal para demonstrar o uso
int main() {
    int arr[6] = {1, 8, 3, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newArr[6];

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
    }

    shuffle(arr, n);

    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }

    int indice1;
    int indice2;
    printf("Escolha um valor entre 0 e %d para o indice 1: ", n - 1);
    scanf("%d", &indice1);

    printf("Escolha um valor entre 0 e %d para o indice 2: ", n - 1);
    scanf("%d", &indice2);

    guessingGame(indice1, indice2, newArr, n);

    printf("\n");

    return 0;
}