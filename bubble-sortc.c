#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void display(int* arr, int size){

    for(int i=0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


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


void swap(int* primeiro, int* segundo){
    int aux = *primeiro;
    *primeiro = *segundo;
    *segundo = aux;
}



int main(void){

    srand(time(NULL));
    int n = rand()%20;

    int *arr = (int*) calloc(n, sizeof(int));

    if(arr == NULL){
        printf("Memoria nao alocada!");
        exit(0);
    }

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
