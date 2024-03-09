#include <stdio.h>
#include <stdlib.h>


int main(){
    int n,maior_altura,altura = 0;
    printf("Digite um inteiro com n>= 2: ");
    scanf("%d",&n);
    int vetor[n];
    for(int i=0;i < n;i++){
        printf("Digite um número: ");
        scanf("%d",&vetor[i]);
    }
    
    for(int i=0;i < n - 1;i++){
        if(i == 0){
            maior_altura = abs(vetor[i] - vetor[i+1]);
            continue;
        }
        altura = abs(vetor[i] - vetor[i+1]);
        if(altura > maior_altura){
            maior_altura = altura;
        }
    }
    printf("A maior altura é %d",maior_altura);

}