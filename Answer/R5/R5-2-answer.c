#include <stdio.h>

#define MAX 20
#define BASE 10

void print(int *a, int n){
    int i;
    for (i = 0; i<n; i++) printf("%d\t", a[i]);
    printf("\n");
}

void radix_sort(int *a, int n){
    int i, b[MAX], m = a[0], exp = 1;
    for (i = 0; i<n; i++) { if (a[i] > m) m = a[i]; }
    while( exp < m ){ //【D1】最大値mよりexpが大きくなったら終了
        int count[BASE] = {0};
        for (i = 0; i<n; i++) count[(a[i]/exp)%BASE]++; 
        for (i = 1; i<BASE; i++) count[i] += count[i - 1]; // 累積度数を計算
        for (i = n-1; i>=0; i--) b[count[(a[i]/exp)%BASE]-- - 1] = a[i];// 【D2】
        for (i = 0; i<n; i++) a[i] = b[i];
        exp *= BASE;
        printf("\n processing...: "); print(a, n);
    }
}

int main(){
    int i, n, arr[MAX];
    printf("enter total elements (n <= %d) : ", MAX);
    scanf("%d", &n); n = n < MAX ? n : MAX;
    printf("Enter %d elements : ", n);
    for (i = 0; i<n; i++) scanf("%d", &arr[i]);
    printf("\nARRAY : "); print(arr, n);
    radix_sort(arr, n);
    printf("\nSORTED : "); print(arr, n);
    return 0;
}