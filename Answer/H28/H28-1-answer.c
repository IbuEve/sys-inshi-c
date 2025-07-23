#include <stdio.h>
#define MAX_ELEMENTS 1000

void merge_sort(int data[], int low, int high)
{
    int mid, i, j, k;
    int tempdata[MAX_ELEMENTS];

    if (low >= high)
        return;
    
    mid = (low + high)/2;
    merge_sort(data, low, mid); // 【1】
    merge_sort(data, mid+1, high); // 【2】

    for (i = low; i <= mid; i++)
        tempdata[i] = data[i];
    for (j = high; j > mid; i++, j--) // 【3】  // 【4】
        tempdata[i] = data[j];

    i = low; j = high;
    for (k = low; k <= high; k++)
        if (tempdata[i] < tempdata[j]) // 【5】
            data[k] = tempdata[i++];
        else
            data[k] = tempdata[j--];

}

int main(void){
   int arr[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
   int n = sizeof(arr) / sizeof(arr[0]);  // 配列の要素数
   
   printf("Before sorting: ");
   for(int i = 0; i < n; i++){
       printf("%d ", arr[i]);
   }
   printf("\n");
   
   // マージソート実行
   merge_sort(arr, 0, n - 1);
   
   printf("After sorting: ");
   for(int i = 0; i < n; i++){
       printf("%d ", arr[i]);
   }
   printf("\n");
   
   return 0;
}