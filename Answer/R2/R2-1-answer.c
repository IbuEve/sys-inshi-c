#define max(a, b) ((a>b) ? a:b ) // 【1】 マクロはカッコで囲わないといけない
#include <stdio.h>
#include <string.h>

int bm_search(char text[], char pattern[]){
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int skip[256], i, j;

    for (i = 0; i < 256; i++){
        skip[i] = pattern_len;
    }

    for (i = 0; i < pattern_len; i++){
        int k = (unsigned int)pattern[i];
        skip[k] = pattern_len - i - 1;
    }

    i = pattern_len - 1;
    while(i < text_len){
        j = pattern_len - 1;
        while(text[i] == pattern[j]){
            if (j == 0) return i;
            i--; j--;
        }
        int k = (unsigned char)text[i];
        i = i + max(skip[k], pattern_len - j);
        printf("%d, %c\n", i, text[i]);
    }
    return i;
}

int main(void){
    char text[] = "abcecabeabc";
    int i = bm_search(text, "abcab");
    if (i >= strlen(text)) printf("pattern not found");
    else printf("%d, %c\n", i, text[i]);
    return 0;
}
