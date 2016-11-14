#ifndef ADT_LLIST_2015114834
#define ADT_LLIST_2015114834
#include <stdio.h>
#include <stdlib.h>

//Tree Node struct
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}T_node;

//BST
typedef struct {
    int count;
    T_node* root;
}BST_tree;

BST_tree* create_bst_tree();
T_node* find_smallest_node(T_node* root);
T_node* find_largest_node(T_node* root);
T_node* search_bst(T_node* root, int key);
T_node* add_bst(T_node* root, int data);
T_node* delete_bst(T_node* root, int data, bool* success);

void traverse_preorder(T_node* root);
void traverse_inorder(T_node* root);
void traverse_postorder(T_node* root);

bool BST_insert(BST_tree* tree, int data);
bool BST_delete(BST_tree* tree, int data);
void BST_print(BST_tree* tree, int method);
#endif
