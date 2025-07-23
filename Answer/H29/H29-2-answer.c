#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int boyer_moore_search(char text[], int text_len, char pattern[], int pat_len)
{
    int skip[128];
    int i, j;

    // スキップテーブルの作成
    for (i = 0; i < 128; i++)
        skip[i] = pat_len; // 【1】
    for (i = 0; i < pat_len - 1; i++)
        skip[pattern[i]] = pat_len - i - 1; // 【2】

    i = pat_len - 1; // 【3】
    while (i < text_len){
        j = pat_len - 1;
        while (text[i] == pattern[j]) {
            if (j == 0)
                return i;
            i--; j--;
        }
        i = i + max(skip[text[i]], pat_len - j); //【4】
    }
    return -1;
}

int main(void){
    char str[] = "Good morning";
    char pattern[] = "ing";

    int match = boyer_moore_search(str, strlen(str), pattern, strlen(pattern));
    if (match != -1) {
        printf("pattern found at position: %d\n", match);
    } else {
        printf("pattern not found\n");
    }


}