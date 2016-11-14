#include "ADT_tree.h"
#include <stdio.h>
#include <stdlib.h>

BST_tree* create_bst_tree(){
    BST_tree* tree = (BST_tree*)malloc(sizeof(BST_tree));
    tree->count = 0;
    tree->root = NULL;
    return tree;
}

T_node* find_smallest_node(T_node* root){
    if(root->left==NULL)//left node is small than root node
        return root;
    else
        return find_smallest_node(root->left);//recursive function
}

T_node* find_largest_node(T_node* root){
    if(root->right==NULL)//left node is larger than root node
        return root;
    else
        return find_largest_node(root->right);//recursive function
}

T_node* search_bst(T_node* root, int s_data){
    if(root == NULL)
        return NULL;//error case
    if(s_data<(root->data))//left is small
        return search_bst(root->left,s_data);
    else if(s_data>(root->data))//right is larger
        return search_bst(root->right,s_data);
    else//same
        return root;
}

T_node* add_bst(T_node* root, int data){
    if(root == NULL){
        T_node* new_node = (T_node*)malloc(sizeof(T_node));
        new_node->right = NULL;
        new_node->left = NULL;
        new_node->data = data;
        return new_node;
    }
    if(data<(root->data)){
        root->left = add_bst(root->left,data);
        return root;
    }
    else{
        root->right = add_bst(root->right,data);
        return root;
    }
}

T_node* delete_bst(T_node* root, int data, bool* success){
    if(root==NULL){
        *success = false;
        return NULL;
    }

    if(data<(root->data)){
        root->left = delete_bst(root->left,data,success);
    }
    else if(data>(root->data)){
        root->right = delete_bst(root->right,data,success);
    }
    else{
        T_node* deleted_node = root;
        if(root->left == NULL){
            T_node* new_node = root->right;
            free(deleted_node);
            *success = true;
            return new_node;
        }
        else{
            if(root->right == NULL){
                T_node* new_node = root->left;
                free(deleted_node);
                *success = true;
                return new_node;
            }
            else{
                T_node* search=find_largest_node(root->left);
                root->data = search->data;
                root->left = delete_bst(root->left,search->data,success);
            }
        }
    }
    return root;
}


void traverse_preorder(T_node* root){
    if(root != NULL){
        printf("%d,",root->data);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}

void traverse_inorder(T_node* root){
    if(root != NULL){
        traverse_inorder(root->left);
        printf("%d,",root->data);
        traverse_inorder(root->right);
    }
}

void traverse_postorder(T_node* root){
    if(root != NULL){
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%d,",root->data);
    }
}

bool BST_insert(BST_tree* tree, int data){
    T_node* newroot;
    newroot = add_bst(tree->root,data);
    if(newroot == NULL)
        return false;
    else{
        tree->root = newroot;
        (tree->count)++;
        return true;
    }
}

bool BST_delete(BST_tree* tree, int data){
    bool success;
    T_node* newroot;
    newroot = delete_bst(tree->root,data,&success);
    
    if(success){
        tree->root = newroot;
        (tree->count)--;
        if(tree->count == 0)
            tree->root = NULL;
    }

    return success;
}

void BST_print(BST_tree* tree, int method){
    printf("BST_TREE:\n");
    printf(" size : %d\n",tree->count);
    printf(" data : ");

    if(method ==0)
        traverse_preorder(tree->root);
    else if(method == 1)
        traverse_inorder(tree->root);
    else if(method == 2)
        traverse_postorder(tree->root);
    else
        printf("type error");

    printf("\n");
}


