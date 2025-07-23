#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HT_SIZE 20

typedef struct data{
    int age;
    char name[100];
} data;

typedef struct node {
    char *key;
    data details;
    struct node* next;
} node;

node *htable[HT_SIZE]; // htableっていう配列の各要素がnodeへのポインタ htable[x] <-こいつはnodeをさすポインタ型

int hash(char key[]) {
    int i = 0;
    while(*key) {
        i += *key++;
    }
    return i % HT_SIZE;
}

int keyequal(char key1[], char key2[]){
    int lk1 = strlen(key1);
    int lk2 = strlen(key2);
    if (lk1 != lk2) return 0;
    int i = 0;
    for (i = 0; i < lk1; i++) {
        if (key1[i] != key2[i]) return 0;
    }
    return 1;
}

void init_htable(){
    int i; for (i = 0; i < HT_SIZE; i++) htable[i] = NULL;
}

data *find(char key[]){
    node *p;
    for (p = htable[hash(key)]; p != NULL; p = p->next)
        if (keyequal(key, p->key)) return &p->details;
    return NULL;
}

int insert(char key[], data *details){
    node *p;
    int h;
    if (find(key) != NULL) return 0;
    if ((p = malloc(sizeof(node))) == NULL){
        fprintf(stderr, "OUT OF MEMORY\n");
        exit(2);
    }
    p->key = key;
    p->details = *details;
    // 【2】 同じハッシュ値を持つデータを連結リストに挿入する
    h = hash(key);
    p->next = htable[h];
    htable[h] = p;
    // 元々入ってた方を押し出す感じね

    return 1;
}

int delete(char key[]){
    int h = hash(key);
    if (htable[h] == NULL) return 0;
    node *p, *q;
    if (keyequal(key, htable[h]->key)) {
        p = htable[h];
        htable[h] = p->next;
        free(p);
        return 1;
    }
    for (q = htable[h], p = q->next; p != NULL; q = p, p = p->next){
        if (keyequal(key, p->key)){
            q->next = p->next;
            free(p);
            return 1;
        }
    }
    return 0;
}

int main(){
    init_htable();
    data a = {20, "Handai"};
    insert("s12", &a);
    data b = {21, "Kyodai"};
    insert("s13", &b);    
    data c = {22, "Todai"};
    insert("s22", &c);
    data *d = find("s12");
    if (d != NULL){
        printf("%d", d->age);
    }
    delete("s13");
    return 0;
}