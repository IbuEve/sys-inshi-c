#include <stdio.h>
#define DATATYPE int

// プログラム2
struct CELL
{
    struct CELL *next;
    DATATYPE data;
};

// プログラム3
struct CELL *create(DATATYPE data){
    struct CELL *p = (struct CELL *)malloc(sizeof(struct CELL)); // 【1】 【2】 
    // struct CELL *p = (CELL)malloc(sizeof(CELL)); これは間違い CELLという名前の型定義がされていないから
    p->next = NULL;
    p->data = data;
    return p;
}

// プログラム4
struct CELL *create(DATATYPE data){
    struct CELL p;
    p.next = NULL;
    p.data = data;
    return &p;
}