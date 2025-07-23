#include <stdio.h>
#include <string.h>

int boyer_moore_search(char text[], int text_len, char pattern[], int pat_len)
{
    int skip[128];
    int i, j;
    for (i = 0; i < 128; i++)
        skip[i] = 【1】;
    for (i = 0; i < pat_len - 1; i++)
        skip[pattern[i]] = 【2】;

    i = 【3】;
    while (i < text_len){
        j = pat_len - 1;
        while (text[i] == pattern[j]) {
            if (j == 0)
                return i;
            i--; j--;
        }
        i = i + max(skip[text[i]], 【4】);
    }
    return -1;
}

