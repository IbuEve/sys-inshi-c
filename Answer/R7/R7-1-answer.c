#include <stdio.h>
#include <stdlib.h> 

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create_node(int val){
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // 【1】TreeNodeは型定義されていないから、構造体タグとして struct TreeNode と書く必要がある
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct TreeNode* insert_node(struct TreeNode* root, int val) {
    if (root == NULL) return create_node(val);
    if (val < root->val)
        root->left = insert_node(root->left, val);
    else if (val > root->val)
        root->right = insert_node(root->right, val);
    return root;
}

// プログラム1のdelete_nodeをdelete_node1にしてます

struct TreeNode* delete_node1(struct TreeNode* root, int val){
    if (root == NULL) return root;
    if (val < root->val)
        root->left = delete_node1(root->left, val);
    else if (val > root->val)
        root->right = delete_node1(root->right, val);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = root->right;
        while(temp->left != NULL) temp = temp->left;
        root->val = temp->val;
        root->right = delete_node1(root->right, root->val); // 【2】root->valにtemp->valを代入することで次の再帰の探索するvalをtemp->valにして、進んでいく.
    }
    return root;
}

struct TreeNode* search_node(struct TreeNode* root, int val){
    if (val == root->val) // 【3】
        return root;
    if (val < root->val)
        return search_node(root->left, val);
    return search_node(root->right, val);
}


struct TreeNode* delete_node2(struct TreeNode* root, int val){
    struct TreeNode *parent = NULL, *current = root;
    while(current != NULL && current->val != val) {
        parent = current;
        if (val < current->val)
            current = current->left;
        else
            current = current->right;
    }
    if (current == NULL) return root;

     //【4】子にNULLがあるとき
    if ( current->left == NULL || current->right == NULL ) {
        struct TreeNode *new_curr;
        if (current->left == NULL)
            new_curr = current->right;
        else
            new_curr = current->left;
        if (parent == NULL)
            return new_curr;
        if (current == parent->left)
            parent->left = new_curr;
        else
            parent->right = new_curr;
        free(current);
    } else {
        struct TreeNode *p = NULL;
        struct TreeNode *temp;
        temp = current->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
        current->val = temp->val;
        if (p != NULL) {
            //【5】whileでleftに進んで行ってるとき
            p->left = temp->right;
        } else {
            current->right = temp->right;
        }
        free(temp);
    }
    return root;
}