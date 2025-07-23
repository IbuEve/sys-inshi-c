#include <stdio.h>
#include <string.h>

#define AtoZ ('Z'-'A'+1)
#define HT_SIZE 10
#define NOISE_PARAM 100

struct {
    char name[4];
    int price;
} hash_table[HT_SIZE];

int hash(char *key){
    unsigned long h = 0;
    h = (key[0] - 'A') + (key[1] - 'A') + (key[2] - 'A');
    return h % HT_SIZE;
}

int rehash(char *key){
    unsigned long h = 0;
    h = (key[0] - 'A') * AtoZ * AtoZ + (key[1] - 'A') * AtoZ + (key[2] - 'A');
    return h * h / NOISE_PARAM % HT_SIZE;
}

int insert(char *key, int data){
    int hash_value;
    hash_value = hash(key);
    if ( strcmp(hash_table[hash_value].name, "") == 0 ){ // 【A】 c言語では文字列比較に"=="は使えないよ!!
        strcpy(hash_table[hash_value].name, key);
        hash_table[hash_value].price = data;
        return 1;
    }
    hash_value = rehash(key);
    if ( strcmp(hash_table[hash_value].name, "") == 0 ){ // 【A】
        strcpy(hash_table[hash_value].name, key);
        hash_table[hash_value].price = data;
        return 1;
    }
    while (hash_value < HT_SIZE){
        hash_value++;
        if ( strcmp(hash_table[hash_value].name, "") == 0 ){ // 【A】
            strcpy(hash_table[hash_value].name, key);
            hash_table[hash_value].price = data;
            return 1;
        }
    }
    printf("Rehash error\n");
    return 0;
}

int main(void){
    for (int i = 0; i < HT_SIZE; i++){
        strcpy(hash_table[i].name, "");
        hash_table[i].price = 0;
    }
    
    insert("ACE", 100);
    insert("ACT", 200);
    insert("CAT", 300);

    for (int i = 0; i < HT_SIZE; i++){
        printf("%d: %s %d\n", i, hash_table[i].name, hash_table[i].price);
    }
    return 0;
}

/* 
c言語では文字列比較に"=="は使えないよ!!
【A】
hash_table[hash_value].name == ""
これは間違い!!
strcmp(str1, str2)を使おう
等しかったら0を返してくれる(他の機能は省略) 

理由: 
hash_table[hash_value].nameはchar[4]型の配列
""が指してるのは文字列リテラルのメモリ(ポインタ)
つまり、比較できない式になっている!!
*/