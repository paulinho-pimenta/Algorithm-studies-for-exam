#include <stdio.h>

void ordenar(int *vetor,int tamanho){
    int i,j;
    int pos_i;
    for(i = 1; i < tamanho; i++){
        pos_i = vetor[i];
        for(j = i - 1; j >= 0 && pos_i < vetor[j]; j--){
            vetor[j + 1] = vetor[j];
        }
        vetor[j + 1] = pos_i;
    }
}

void mostrar_vetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vetor[i]);
    }
    printf("\n");
}

int encontrar_posicao(int *vetor,int tamanho,int entrada){
    int comeco = 0,meio,fim = tamanho - 1;

    while(comeco <= fim){
        meio = comeco + (fim - comeco) / 2;

        if(entrada == vetor[meio]){
            printf("O numero %d esta na posicao %d",entrada,meio);
            return 0;
        }else{
            if(entrada < vetor[meio]){
                fim = meio - 1;
            }else{
                comeco = meio + 1;
            }
        }
    }
    printf("O numero inserdio nao pode ser econtrado");
    return 1; 
}

int main(){
    int vetor[10] = {33,22,44,11,77,99,67,55,100,88};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int entrada;

    ordenar(vetor,tamanho);
    mostrar_vetor(vetor,tamanho);

    printf("Insira um numero dentre esses para encontrarmos sua posicao no vetor:\n");
    scanf("%d",&entrada);

    encontrar_posicao(vetor,tamanho,entrada);

    return 0;
}
