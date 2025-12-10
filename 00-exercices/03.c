#include <stdio.h>
#include <stdlib.h>

// Retorna o ÍNDICE do menor elemento
int searchMinIndex(int *arr, int len)
{
    int min = arr[0];
    int min_index = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

// "POP" - remove elemento do índice e desloca os demais
int popAt(int *arr, int *len, int index, int *totalChanges)
{
    int value = arr[index];  // Guarda o valor
    
    // Desloca elementos para esquerda
    for (int i = index; i < *len - 1; i++)
    {
        arr[i] = arr[i + 1];
        (*totalChanges)++;  // Incrementa contador de trocas
    }

    (*len)--;  // Diminui o tamanho
    return value;
}

void increase(int *arr, int len)
{
    int *newArr = malloc(len * sizeof(int));  // Aloca array ordenado
    int newSize = 0;  // Tamanho do newArr
    int tempLen = len;  // Tamanho atual do arr (vai diminuindo)
    int totalChanges = 0;  // Contador de trocas
    
    // Cria cópia temporária do array original
    int *tempArr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        tempArr[i] = arr[i];
    }
    
    // Equivalente a: while tempArr não estiver vazio
    while (tempLen > 0)
    {
        // Acha o índice do menor
        int minIndex = searchMinIndex(tempArr, tempLen);
        
        // "POP" do menor e "APPEND" no newArr
        int menor = popAt(tempArr, &tempLen, minIndex, &totalChanges);
        newArr[newSize] = menor;  // APPEND
        newSize++;
    }
    
    // Copia resultado de volta para arr original
    for (int i = 0; i < len; i++)
    {
        arr[i] = newArr[i];
    }
    
    printf("Total de trocas (movimentacoes): %d\n", totalChanges);
    
    free(tempArr);
    free(newArr);
}

void decrease(int *arr, int len)
{
    // Ordena crescente primeiro
    increase(arr, len);
    
    // Inverte o array
    for (int i = 0; i < len / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}


void chooseOperation(int *arr, int operation, int length)
{
    if (operation == 1)
    {
        printf("Ordenando crescente...\n");
        increase(arr, length);
    }
    else if (operation == 2)
    {
        printf("Ordenando decrescente...\n");   
        decrease(arr, length);
    }
    else
    {
        printf("Operacao invalida!\n");
    }
}

int main()
{
    int arr[10] = {3, 5, 7, 2, 8, 1, 4, 9, 6, 0};  // Array normal, não ponteiros
    int length = sizeof(arr) / sizeof(arr[0]);
    int operation = 0;

    printf("Array original: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Escolha a operacao que deseja realizar:\n");
    printf("1 - Ordenar crescente\n");
    printf("2 - Ordenar decrescente\n");
    scanf("%d", &operation);

    chooseOperation(arr, operation, length);

    printf("\nArray ordenado: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}