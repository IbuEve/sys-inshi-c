#include <stdio.h>
#define DATATYPE int

// プログラム2
struct CELL
{
    struct CELL *next;
    DATATYPE data   
};

// プログラム3
struct CELL *create(DATATYPE data){
    struct CELL *p = 【1】malloc(【2】);
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