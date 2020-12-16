/**
 *  Bubble Sort
 *  Percorre várias vezes o vetor, jogando o maior valor para o final da lista
 *
 *  ex: [3,1,5,2]
 *      [1,3,5,2]
 *      [1,3,2,5]
 *      [1,2,4,5]
 *
 *  Pior caso   O(n^2)
 *  Melhor caso O(n)
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * Exibe os elementos do array
 * @param arr array para ser exibido
 * @param size tamanho do array
 */
void display(int* arr, int size){

    for(int i=0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


/**
 * Implementação do algoritmo bubble sort
 * @param arr array para ser ordenado
 * @param size tamanho do array
 */
void bubbleSort(int* arr, int size){

    for(int i=0; i<size-1; i++){
        bool swapped = false;

        for(int j=0; j<size-1-i; j++){

            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}


/**
 * Realiza a troca de elementos
 * @param primeiro ponteiro para o primeiro elemento
 * @param segundo ponteiro para o segundo elemento
 */
void swap(int* primeiro, int* segundo){
    int aux = *primeiro;
    *primeiro = *segundo;
    *segundo = aux;
}



int main(void){

    srand(time(NULL));
    int n = rand()%20;


    /* Criando um array dinâmico, com n elementos, todos zerados por causa do calloc */
    int *arr = (int*) calloc(n, sizeof(int));

    if(arr == NULL){
        printf("Memoria nao alocada!");
        exit(0);
    }
    /* Criando array aleatório de tamanho n */
    for(int i=0; i<n ; i++){
        arr[i] = rand()%100;
    }

    printf("Antes do sort: ");
    display(arr,n);

    bubbleSort(arr, n);

    printf("\nDepois do sort: ");
    display(arr,n);

    free(arr);
}
