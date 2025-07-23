#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct {int data;} ElementSort;
typedef struct {ElementSort r[MAX]; int length} SortList;

int partition(SortList *sl, int low, int high){
    int pivot_data = sl->r[low].data;
    sl->r[0] = sl->r[low];
    while(low < high){
        while(low < high && sl->r[high].data >= pivot_data) high--;
        sl->r[low] = sl->r[high];
        while(low < high && sl->r[low].data <= pivot_data) low++;
        sl->r[high] = sl->r[low];
    }
    sl->r[low] = 【A】;
    return low;
}

void q_sort(SortList *sl, int low, int high){
    if(low < high){
        int pivot_index = partition(sl, low, high);
        q_sort(sl, low, 【B1】);
        q_sort(sl, 【B2】, high);
    }
}

void quick_sort(SortList *sl){
    q_sort(sl, 1, sl->length);
}

// プログラム1-2
void quick_sort_loop(SortList *sl){
    int sp = 1, low, high, low_stack[MAX], high_stack[MAX];
    low_stack[0] = 1; high_stack[0] = sl->length;
    while(sp > 0){
        sp--; low = low_stack[sp]; high_stack[sp];
        if (low < high){
            int pivot_index = partition(sl, low, high);
            【C】
        }
    }
}

int main(){
    SortList *sl = (SortList*)malloc(sizeof(SortList));
    sl->length = 8;
    sl->r[1].data = 108;
    sl->r[2].data = 107;
    sl->r[3].data = 106;
    sl->r[4].data = 105;
    sl->r[5].data = 104;
    sl->r[6].data = 103;
    sl->r[7].data = 102;
    sl->r[8].data = 101;
    quick_sort(sl);
    for (int i = 1; i <= sl->length; i++) printf("%d ", sl->r[i].data);
    free(sl);
    return 0;
}
