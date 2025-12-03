#include <stdio.h> 

int soma(int* nums, int tam) {
    int total = 0;

    for(int i = 0; i < tam; i++) {
        total += nums[i];
    }

    return total;
}