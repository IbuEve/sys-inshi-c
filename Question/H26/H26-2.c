#include <stdio.h>
int convert(char *s);

int main(void){
    char *s = "Osaka Univ.";
    int i;
    i = convert(s);
    printf("After: %s NumChar: %d\n", s, i);
    return 0;
}

int convert(char *s){
    int i, size;
    size = sizeof(s); // アーキテクチャの違いで結果変わります
    for (i = 0; i < size; i++){
        if (('A' <= *s && *s < 'M') || (('a' <= *s && *s < 'm')) ){
            // 【キ】
        }
        else if (('N' <= *s && *s < 'Z') || (('n' <= *s && *s < 'z')) ){
            // 【ク】
        }
        s++;
    }
    return size;
}