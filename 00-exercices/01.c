#include <stdio.h>
#include <stdlib.h>
#include "01.h"

int arrayDefinedSize(int *size)
{
    printf("Defina o tamanho do array: ");
    scanf("%d", size);

    if (*size >= 100)
    {
        printf("Tamanho invalido! O tamanho deve ser menor que 100.\n");
        exit(1);
    }

    return *size;
}

int* buildingArray(int *sizeOut)
{
    int size;
    size = arrayDefinedSize(&size);
    // Aloca memória dinamicamente para o array
    int *array = (int*)malloc(size * sizeof(int));
    
    if (array == NULL) {
        printf("Erro ao alocar memória!\n");
        *sizeOut = 0;
        return NULL;
    }
    
    *sizeOut = size;

    int command;

    printf("Digite 0 para sair ou qualquer outro numero para continuar: ");
    scanf("%d", &command);
    
    if (command == 0){
        free(array);
        *sizeOut = 0;
        return NULL;

    } else {

        for (int i = 0; i < size; i++)
        {
            printf("Defina o valor para a posicao %d: ", i);
            int value;
            scanf("%d", &value);
            array[i] = value;
        }
    }

    printf("Array construido com sucesso!\n");
    printf("O tamanho do array e: %d\n", size);

    return array;
}

int higherValue(int *array, int size)
{
    int higher = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > higher)
        {
            higher = array[i];
        }
    }
    return higher;
}

int lowerValue(int *array, int size)
{
    int lower = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < lower)
        {
            lower = array[i];
        }
    }
    return lower;
}

int media(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum / size;
}

int main()
{
    int length = 0;
    int *arr = buildingArray(&length);

    if (arr == NULL || length == 0) {
        printf("Programa encerrado.\n");
        return 0;
    }

    printf("Valores no array:\n");
    printf("O tamanho do array e: %d\n", length);

    // for (int i = 0; i < length; i++)
    // {
    //     printf("Valor na posicao %d: %d\n", i, arr[i]);
    // }

    printf("O maior valor no array e: %d\n", higherValue(arr, length));
    printf("O menor valor no array e: %d\n", lowerValue(arr, length));
    printf("A media dos valores no array e: %d\n", media(arr, length));

    // Libera a memória alocada
    free(arr);

    return 0;
}
