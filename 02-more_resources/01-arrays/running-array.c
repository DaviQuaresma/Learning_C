#include <stdio.h>  

int main()  
{  

  char palavra[] = "MELANCIA";
  char chute;

  do
  {
    printf("Adivinhe a letra que estou pensando: ");  
    scanf(" %c", &chute);

    for(int i = 0; i < strlen(palavra); i++)  
        {  
            if (chute == palavra[i])
            {
                printf("Parabéns! Você acertou a letra %c na posição %d da palavra.\n", chute, i);
            }
            
        }

    } while (chute != 'X'); // Condição para sair do loop

}