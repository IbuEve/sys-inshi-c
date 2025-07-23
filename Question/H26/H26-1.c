#include <stdio.h>

#define KEY int // KEY型をとりあえずintで定義しておきます

// プログラム3
int keyequal(KEY a, KEY b);
int keylt(KEY a, KEY b);

// プログラム2
typedef struct node{
    KEY data;
    struct node *left;
    struct node *right; 
} NODE;


// プログラム1
NODE *insert(NODE *root, KEY key)
{
    NODE **p;
    NODE *new;
    p = root; // 【ア】 // ルートから探索する
    while (*p != NULL){
        if (keyequal(key, 【イ】 -> data))
            return NULL;
        else if (keylt(key, 【イ】 -> data))
            p = 【ウ】;
        else 
            p = 【エ】;
    }
    if ((new = malloc(【オ】)) == NULL) {
        printf("ERROR: out of memory\n");
        exit(1);
    }
    new -> left = NULL;
    new -> right = NULL;
    new -> data = key;
    【カ】 = new;
    return new;

}
