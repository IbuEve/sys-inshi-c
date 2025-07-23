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
            i++; j = 0;  // 【1】
        }
    }
    return (j == pat_len) ?  i-j : -1; // 【2】 コロンを使う
}

int main(void){
    char str[] = "Good morning";
    char pattern[] = "ing";

    int match = brute_force_search(str, strlen(str), pattern, strlen(pattern));
    if (match != -1) {
        printf("pattern found at position: %d\n", match);
    } else {
        printf("pattern not found\n");
    }


}