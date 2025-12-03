#include <stdio.h>

// Ao declarar int* você está dizendo que não ta declarando um inteiro, ta vindo um endereço de memoria de 
// um inteiro ( um valor que já existe na memória )

void calcula(int* c2){

    printf("calcula %d %d\n", (*c2), c2);
    (*c2)++;
    printf("calcula %d %d\n", (*c2), c2);
}


// Para pegar o endereço de memória de uma variável, usamos o operador &
int main() {

    int c = 10;
    printf("main %d %d\n", c, &c);
    calcula(&c);
    printf("main %d %d\n", c, &c);
}


// Exemplo sem ponteiros

void calcula(int c){

    printf("calcula %d %d\n", c, &c);
    c++;
    printf("calcula %d %d\n", c, &c);
}


// Para pegar o endereço de memória de uma variável, usamos o operador &
int main() {

    int c = 10;
    printf("main %d %d\n", c, &c);
    calcula(c);
    printf("main %d %d\n", c, &c);
}

