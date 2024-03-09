#include <stdio.h>


int ja_foi_impresso(int x,int *v,int n){
    for(int i = 0; i < n;i++){
        if(x == v[i]){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n,qtd;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);
    int vetor[n];
    int impressos[n];
    for(int i=0; i < n;i++){
        printf("Digite o %dª elemento do vetor:",i+1);
        scanf("%d",&vetor[i]);
    }
    for(int i=0;i<n;i++){
        qtd=1;
        for(int j=i+1;j<n;j++){
            if(vetor[i]==vetor[j]){
                qtd++;
            }
        }
        if(!ja_foi_impresso(vetor[i],impressos,n)){
            printf("Número %d, quantidade %d\n",vetor[i],qtd);
            impressos[i] = vetor[i];
        }
    }
}