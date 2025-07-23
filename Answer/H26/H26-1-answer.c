#include <stdio.h>
#include <stdlib.h> // 実行用に追加

#define KEY int // KEY型をとりあえずintで定義しておきます

// プログラム3
int keyequal(KEY a, KEY b){
    if (a == b) return 1;
    else return 0;
};
int keylt(KEY a, KEY b){
    if (a < b) return 1;
    else return 0;
};

// プログラム2
typedef struct node{
    KEY data;
    struct node *left;
    struct node *right; 
} NODE;


// プログラム1
NODE *insert(NODE *root, KEY key)
{
    NODE **p; // ダブルポインタ型 p = NODE型のポインタのアドレス
    NODE *new;
    p = &root; // 【ア】rootのメモリアドレス
    while (*p != NULL){
        if (keyequal(key, (*p) -> data)) //【イ】(*p)でroot(NODEのポインタ型)にいける -> でdataに辿り着く. *p -> dataだと間接演算子の効果が、*(p -> data)で扱われてしまう
            return NULL;
        else if (keylt(key, (*p) -> data)) //【イ】
            p = &((*p) -> left); // 【ウ】 x = (*p)->leftの値はNODE型の値が入っている場所を指すポインタ, つまりxはあるノードを指すポインタで    変数pはダブルポインタ型だから、
        else 
            p = &((*p) -> right); // 【エ】
    }
    if ((new = malloc(sizeof(NODE))) == NULL) { // 【オ】 NODE型のメモリ領域を確保したい-> sizeof(NODE)でとる
        printf("ERROR: out of memory\n");
        exit(1);
    }
    new -> left = NULL;
    new -> right = NULL;
    new -> data = key;
    *p = new; // 【カ】newにはポインタが入ってる
    return new;

}


// 実行用
void preorder(NODE *root) {
    if (root != NULL) {
        printf("%d ", root->data);  // ノードを訪問
        preorder(root->left);       // 左の子を再帰的に処理
        preorder(root->right);      // 右の子を再帰的に処理
    }
}


int main (void){
    NODE *root = NULL;  // 空の二分探索木として初期化
    KEY key1 = 6;
    KEY key2 = 3;
    KEY key3 = 1;
    KEY key4 = 2;
    KEY key5 = 5;
    KEY key6 = 4;
    KEY key7 = 8;   
    KEY key8 = 9;

    // ノードを挿入
    root = insert(root, key1);
    insert(root, key2);
    insert(root, key3);
    insert(root, key4);
    insert(root, key5);
    insert(root, key6);
    insert(root, key7);
    insert(root, key8);
   
    // 行きがけ順で表示
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    return 0;
}
