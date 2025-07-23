#include <stdio.h>
#include <stdlib.h>

struct binarytree {
    char data;
    struct binarytree *lchild;
    struct binarytree *rchild;
};

typedef struct binarytree btree;
typedef struct binarytree *pbtree;


void create_binary_tree(pbtree *t){
    char chin;
    while(1){
        scanf("%c", &chin);
        if (chin >= 'A' && chin <= 'Z') break;
        if (chin == '#') { *t = NULL; return; }
    }

    *t = (pbtree)malloc(sizeof(btree));
    if (!*t) {
        printf("ERROE: fail\n");
        exit(1);
    }
    (*t)->data = chin;
    create_binary_tree(&((*t)->lchild));
    create_binary_tree(&((*t)->rchild));
}

void preorder_traverse(pbtree t){
    if (t != NULL) {
        printf("%c", t->data);
        preorder_traverse(t->lchild);
        preorder_traverse(t->rchild);
    } else return;
}

void inorder_traverse(pbtree t){
    if (t != NULL) {
        // 【1】
    } else return;
}


#define STACKSIZE 100
struct stack
{
    pbtree *base;
    pbtree *top;
    int stacksize;
};

typedef struct stack btreestack;
typedef struct stack *pbtreestack;

void init_stack(pbtreestack s) {
    s->base = (pbtree*)malloc(STACKSIZE*sizeof(pbtree));
    if(!s->base) {
        pringf("ERROR fail\n");
        exit(1);
    }
    s->top = s->base;
    s->stacksize = STACKSIZE;
}

void push_stack(pbtreestack s, pbtree e) {
    if (s->top - s->base >= s->stacksize) {
        printf("ERROR: stack overfloe\n");
    }
    // 【2】
}

pbtree pop_stack(pbtreestack s) {
    if (s->top == s->base) {
        printf("ERROR: stack is empty\n");
    }
    // 【3】
}

int isempty_stack(pbtreestack s) {
    if (s->top == s->base) return 1;
    else return 0;
}

void preorder_loop_traverse(pbtree t) {
    pbtree p = t;
    pbtreestack s;
    init_stack(&s);
    while(p || !isempty_stack(&s)) {
        if (p) {
            printf("%c", p->data);
            // 【4】
        } else {
            p = pop_stack(&s);
            // 【5】
        }
    }
}

int main() {
    pbtree t = NULL;
    create_binary_tree(&t);
    preorder_traverse(t);
    inorder_traverse(t);
    preorder_loop_traverse(t);
    return 0;
}