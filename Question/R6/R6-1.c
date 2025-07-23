#include <stdio.h>
#include <stdlib.h> 
#define M 3

typedef struct BTNode{
    int key_num;
    int key[M];
    struct BTNode *parent;
    struct BTNode *child[M+1];
} Node, *PTree;

void search_btree(PTree t, int val, Node *r_node, int *r_i){
    int i; Node *p = t;
    while(p != NULL) {
        i = 0;
        while(i < p->key_num && val > p->key[i])i++;
        if (【1】) {r_node = p; *r_i = i; return; }
        else { p = p->child[i]; }
    }
    【2】
}

int main(){
    PTree t = (PTree)malloc(sizeof(Node));
    t->key_num = 2; t->parent = NULL;
    t->key[0] = 4; t->key[1] = 7;
    
    t->child[0] = (PTree)malloc(sizeof(Node));
    t->child[0]->key_num = 1; t->child[0]->parent = t;
    t->child[0]->key[0] = 3;
    t->child[0]->child[0] = NULL;
    t->child[0]->child[1] = NULL;
    
    t->child[1] = (PTree)malloc(sizeof(Node));
    t->child[1]->key_num = 1; t->child[1]->parent = t;
    t->child[1]->key[0] = 6;
    t->child[1]->child[0] = NULL;
    t->child[1]->child[1] = NULL;
    
    t->child[2] = (PTree)malloc(sizeof(Node));
    t->child[2]->key_num = 1; t->child[2]->parent = t;
    t->child[2]->key[0] = 9;
    t->child[2]->child[0] = NULL;
    t->child[2]->child[1] = NULL;

    Node *r_nd = NULL; int r_id = -1;
    search_btree(t, 6, r_nd, &r_id); printf("%d", r_id);
    return 0;
}