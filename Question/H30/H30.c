#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
} NODE;

NODE *root = NULL;
NODE *erase2(NODE **p){
    NODE *x;
    while((*p)->right != NULL){ p = &(*p)->right;}
    x = *p;
    *p = (*p)->left;
    return x;
}

void erase(int key){
    NODE **p, *x;
    p = &root;

    while(*p != NULL){
        if (key == (*p)->data){
            x = *p;
            if (x->left == NULL && x->right == NULL) {【1】}
            else if (x->right == NULL) {【2】}
            else if (x->left == NULL) {【3】}
            else{
                【4】
                (*p)->right = x->right;
                (*p)->left = x->left;
            }
            free(x);
        }else if (key < (*p)->data){
            p = &(*p)->left;
        }else{
            p = &(*p)->right;
        }
    }
}

void insert(int key){
    NODE **p, *n;
    p = &root;
    while(*p != NULL){
        if (key == (*p)->data) return;
        else if (key < (*p)->data)
            p = &(*p)->left;
        else
            p = &(*p)->right;
    }
    n = (NODE*)malloc(sizeof(NODE));
    n->left = NULL;
    n->right = NULL;
    n->data = key;
    【5】
}


void order(NODE *p){
    if (p == NULL) { return; }
    【A】
    printf("%d, ", p->data);
    【B】
}

int main(int argc, char** argv){
    int data[11] = {10, 5, 15, 3, 7, 13, 17, 6, 14, 16, 19};
    for (int i = 0; i < 11; i++){
        insert(data[i]);
    }
    order(root);
    printf("\n");
    erase(10);
    order(root);
    printf("\n");
    return 1
}
