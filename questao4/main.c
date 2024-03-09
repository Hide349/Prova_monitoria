#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "func.h"


float media(struct aluno aluno_a){
    float soma = 0;
    for(int i = 0;i < 3;i++){
        printf("");
        soma += aluno_a.notas[i];
    }
    return (soma / 3);
}


int qtd_aprovados(struct aluno *alunos, int n){
    int total = 0;
    for(int i = 0; i < n;i++){
        if(media(alunos[i]) > 7){
            total++;
        }
    }
    return total;
}


int imprimir(struct aluno aluno_a){
    printf("Matrícula: %d\n",aluno_a.matricula);
    printf("Nome: %s\n",aluno_a.nome);
    return 1;
}


int oredem_crescente(struct aluno *alunos, int n){ // Usando insertion Sort 
    for(int i = 1;i < n;i++){
        struct aluno aux = alunos[i];
        int j=i-1;
        for(j;j>=0 && media(aux) < media(alunos[j]);j--){
            alunos[j+1]=alunos[j];
        }
        alunos[j+1] = aux;
    }

    for(int i = 0;i < 3;i++){
        imprimir(alunos[i]);
    }
}


int* alocar_memoria(struct aluno *alunos,int n){
    int quantidade_aprovados = qtd_aprovados(alunos,n);
    quantidade_aprovados++;
    int *vetor;
    vetor =malloc(quantidade_aprovados * sizeof (int) );
    if(vetor == NULL){
        printf("Erro na alocação!");
        return 0;
    } 
    int j = 0;
    for(int i = 0;i < n;i++){
        if(media(alunos[i]) > 7){
            vetor[j]=alunos[i].matricula;
            j++;
        }
    }
    vetor[quantidade_aprovados -1] = -1;
    return vetor;

    }






int main(){
    // struct aluno a;
    // a.matricula = 5;
    // strcpy(a.nome,"Ruan");
    // for(int i = 0;i< 3;i++){
    //     printf("Digite as notas: ");
    //     scanf("%f",&a.notas[i]);
    // }
    // float media_nota = media(a);
    // for(int i = 0; i < 3;i++){
    //     printf("%g\n",a.notas[i]);
    // }
    // printf("A média do aluno é: %g\n",media_nota);



    // struct aluno alunos[10];
    // for(int i=0; i < 10;i++){
    //     for(int j = 0; j < 3;j++){
    //         alunos[i].notas[j] = 7;
    //     }
    // }

    // printf("%d",qtd_aprovados(alunos,10));


    struct aluno a;
    struct aluno b;
    struct aluno c;
    
    

    struct aluno alunos[3] = {a,b,c};

    for(int i=0; i < 3;i++){
        printf("Digite matrícula: ");
        scanf("%d",&alunos[i].matricula);
        printf("matrícula de a é  %d\n",alunos[i].matricula);
        for(int j = 0; j < 3;j++){
            scanf("%f",&alunos[i].notas[j]);
        }
    }

    //ordem_crescente(alunos,n); Colocar a quantidade de alunos que quiser 

    int *vetor = alocar_memoria(alunos,3);
    for(int i = 0;i < 3;i++){
        printf("Pessoa com matrícula %d entrou.\n",vetor[i]);
    }
}