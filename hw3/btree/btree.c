/* Name:
 * ID:
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void insert(Node **tree, int val) {
    
    if (!(*tree)){
        *tree = (Node *)malloc(sizeof(Node));
        (*tree)->data = val;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    if((*tree)->data > val){
        insert(&(*tree)->left, val);
    }else if((*tree)->data < val){
        insert(&(*tree)->right, val);
    }
      
}

void print_space(int layer){
    for (int i =1; i < layer; i++){
        printf("  ");
    }
    if (layer != 0) printf("|-");
 }


void print_helper(Node *tree,int layer){
    print_space(layer);
    printf("%d\n", tree->data);
    
    if (tree->left){
        print_helper(tree->left, ++layer);
    }
    
    if (tree->right && tree->left){
        print_helper(tree->right,layer);
    }else if (tree->right && !tree->left){
        print_helper(tree->right,++layer);
    }
 }

void print(Node *tree) {
    print_helper(tree, 0);
}

  


void delete(Node *tree) {
     if (tree){
        delete(tree->left);
        delete(tree->right);
        free(tree);
     }
}

Node *lookup(Node ** tree, int val) {
    if (!(*tree)) return NULL;
    else if(val == (*tree)->data) return *tree;
    else if(val < (*tree)->data)  return lookup(&(*tree)->left, val);
    else return lookup(&(*tree)->right, val);
}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);
    // Lets see how the tree looks
    print(root);
    // Check if 4 in the tree
    target = lookup(&root, 4);
    
    //printf("%d\n", target->data);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    // Check if 44 in the tree
    target = lookup(&root, 44);
    //printf("%d\n", target->data);

    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    
    // Now let's free up the space
    delete(root);
}
