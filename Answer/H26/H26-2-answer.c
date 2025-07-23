#include <stdio.h>
#include <string.h> // strlenを使うために追加
int convert(char *s);

int main(void){
    // char *s = "Osaka Univ."; で定義すると文字列リテラルをポインタが指してしまい、実行不可になる (参考:http://daeudaeu.com/c-literal/)
    char s[] = "Osaka Univ.";
    int i;
    i = convert(s);
    printf("After: %s NumChar: %d\n", s, i);
    return 0;
}

int convert(char *s){
    int i, size;
    //size = sizeof(*s); // アーキテクチャの違いで結果変わります
    size = strlen(s); // (c) sizeofだとポインタのメモリサイズをとって来てしまうので、配列のサイズを取るように変更する。
    
    for (i = 0; i < size; i++){
        if (('A' <= *s && *s < 'M') || (('a' <= *s && *s < 'm')) ){
            // 【キ】
            *s += 'N'-'A';
            // *s += 13
        }
        else if (('N' <= *s && *s < 'Z') || (('n' <= *s && *s < 'z')) ){
            // 【ク】
            *s += 'A'-'N';
            // *s -= 13
        }
        s++;
    }
    return size;
}