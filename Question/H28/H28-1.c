#include <stdio.h>
#define MAX_ELEMENTS 1000

void merge_sort(int data[], int low, int high)
{
    int mid, i, j, k;
    int tempdata[MAX_ELEMENTS];

    if (low >= high)
        return;
    
    mid = (low + high)/2;
    merge_sort(data, 【1】);
    merge_sort(data, 【2】);

    for (i = low; i <= mid; i++)
        tempdata[i] = data[i];
    for (【3】; 【4】; i++, j--)
        tempdata[i] = data[j];

    i = low; j = high;
    for (k = low; k <= high; k++)
        if (【5】)
            data[k] = tempdata[i++];
        else
            data[k] = tempdata[j--];

}