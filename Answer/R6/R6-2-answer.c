#include <stdio.h>

void swap(int* a, int* b) {int temp = *a; *a = *b; *b = temp; }
void heapdown(int a[], int i, int n){
    int child, tmpele;
    for (tmpele = a[i]; 2 * i + 1 < n; i = child){
        child = 2 * i + 1;
        if (child != n-1 && a[child + 1] > a[child]) ++child;
        if (tmpele < a[child]) a[i] = a[child]; else break;
    }
    a[i] = tmpele;
}

void print(int a[], int n){
    int i;
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void heapsort(int a[], int n){
    int i;
    for (i = n/2; i >= 0; --i) heapdown(a, i, n);  // n/2以降の要素は子を持っていないから0~n/2でループ
    print(a, n); // 問題は標準出力はここのみ。for文にかかってないことに注意

    for (i = n-1; i > 0; --i) {swap(&(a[0]), &(a[i])); heapdown(a, 0, i);} 
    print(a, n);
}

int main(){
    int arr[10] = {81, 2, 39, 49, 34, 62, 53, 6, 43, 98};
    heapsort(arr, 10);
    return 0;
}