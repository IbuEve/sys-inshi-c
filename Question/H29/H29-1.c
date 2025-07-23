#include <stdio.h>
#include <string.h>

int brute_force_search(char text[], int text_len, char pattern[], int pat_len)
{
    int i, j;
    i = 0; j = 0;

    while (i < text_len && j < pat_len){
        if (text[i] == pattern[j]) {
            i++; j++;
        } else {
            【1】
        }
    }
    return (j == pat_len) ? 【2】;
}

