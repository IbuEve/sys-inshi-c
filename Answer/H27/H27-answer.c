#include <stdio.h>

// ピボットよりも小さい値は左側、大きい値は右側に置く

int *func(int *sp, int *ep){
    int *ip, *jp, pv, temp;

    ip = sp;
    jp = ep;
    pv = *jp; // pv = pivotの意

    while(1){
        while(*ip++ < pv) // ipの値*ipがpvより小さいならipを進める
            ;
        *ip--; // 【3】上の比較で行きすぎた分を戻る

        while(ip < --jp && pv < *jp) // 【4】 jpを先にデクリメントしないとjpが進めない
            ;
        if (ip >= jp) 
            break; // 【5】ループを脱出
        // 【6】 交換処理 
        temp = *ip;
        *ip = *jp;
        *jp = temp;

        ip++;
    }
    // 【7】
    temp = *ip;
    *ip = pv;
    *ep = temp;

    return ip;
}

void sort(int *sp, int *ep){
    int *vp;
    vp = func(sp, ep);
    if(sp < vp) // 【1】
        sort(sp, vp-1);
    if(ep > vp) // 【2】
        sort(vp+1, ep);
}


int main(void){
   int arr[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
   int n = sizeof(arr) / sizeof(arr[0]);  // 配列の要素数
   
   printf("Before sorting: ");
   for(int i = 0; i < n; i++){
       printf("%d ", arr[i]);
   }
   printf("\n");
   
   // クイックソート実行（最初の要素のアドレスと最後の要素のアドレスを渡す）
   sort(arr, arr + n - 1);
   
   printf("After sorting: ");
   for(int i = 0; i < n; i++){
       printf("%d ", arr[i]);
   }
   printf("\n");
   
   return 0;
}

