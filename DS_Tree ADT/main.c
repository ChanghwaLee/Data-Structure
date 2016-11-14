#include <stdio.h>
#include "ADT_tree.h"

#define PRE_ORDER 0
#define IN_ORDER 1
#define POST_ORDER 2

int main(){
    int i;
    T_node* search;

    BST_tree* tree = create_bst_tree();

    if(!BST_insert(tree,10))
        printf("tree insertion error\n");
    if(!BST_insert(tree,5))
        printf("tree insertion error\n");
    if(!BST_insert(tree,14))
        printf("tree insertion error\n");
    if(!BST_insert(tree,7))
        printf("tree insertion error\n");
    if(!BST_insert(tree,22))
        printf("tree insertion error\n");

    BST_print(tree,IN_ORDER);
    printf("\n");

    if(!BST_insert(tree,8))
        printf("tree insertion error\n");
    if(!BST_insert(tree,30))
        printf("tree insertion error\n");
    if(!BST_insert(tree,3))
        printf("tree insertion error\n");
    if(!BST_insert(tree,17))
        printf("tree insertion error\n");
    if(!BST_insert(tree,9))
        printf("tree insertion error\n");

    BST_print(tree,IN_ORDER);
    BST_print(tree,POST_ORDER);
    BST_print(tree,PRE_ORDER);
    printf("\n");

    search = search_bst(tree->root, 17);
    if(search != NULL)
        printf("searched node: %d\n",search->data);
    else
        printf("not found: %d\n",17);

    printf("\n");
    search = find_smallest_node(tree->root);
    if(search != NULL)
        printf("smallest node: %d\n",search->data);
    else
        printf("error on finding smalles one\n");

    printf("\n");
    search = find_largest_node(tree->root);
    if(search != NULL)
        printf("largest node: %d\n",search->data);
    else
        printf("error on finding largest one\n");

    printf("\n");
    if(!BST_delete(tree,17))
        printf("failed on deleting 17\n");
    else{
        printf("after deleting 17\n");
        BST_print(tree,IN_ORDER);
    }

    if(!BST_delete(tree,5))
        printf("failed on deleting 5\n");
    else{
        printf("after deleting 5\n");
        BST_print(tree,IN_ORDER);
    }
    if(!BST_delete(tree,3))
        printf("failed on deleting 3\n");
    else{
        printf("after deleting 3\n");
        BST_print(tree,IN_ORDER);
    }
    if(!BST_delete(tree,22))
        printf("failed on deleting 22\n");
    else{
        printf("after deleting 22\n");
        BST_print(tree,IN_ORDER);
    }
    return 0;
}
