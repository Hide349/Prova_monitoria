#include <stdio.h>

int main(){
    int n,soma;
    float media;
    printf("Digite um inteiro n: ");
    scanf("%d",&n);
    int matriz[n][n];
    float vetor[n];

    for(int i = 0; i < n; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            printf("Digite o elemento da coluna [%d][%d:]",i,j);
            scanf("%d",&matriz[i][j]);
            soma += matriz[i][j];
        }
        media = (float) soma / n;
        vetor[i] = media;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d \t",matriz[i][j]);
        }
        printf("\n");
    }
    for(int i = 0;i < n;i++){
        printf("A média da linha %d é %g\n",i,vetor[i]);
    }
}