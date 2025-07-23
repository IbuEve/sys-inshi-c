#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int *b){ // 【6】
    //【7】
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print(int a[], int n){
    int i;
    for (i = 0; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1); // 【8】違う
    print(arr, sizeof(arr)/sizeof(arr[0]) - 1);
    return 0;
}