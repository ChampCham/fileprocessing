/* Name:
 * ID:
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
    if(!*q){
         *q = (Queue *)malloc(sizeof(Queue));
         (*q)->head = NULL;
    }

    Node *new_node = (Node*)malloc(sizeof(Node));
    char* new_word = (char *)malloc(sizeof(char)*strlen(word)+1);
    strcpy(new_word, word); 
    new_node->data = new_word;

    if(!(*q)->head){
        (*q)->head = new_node;
        new_node->next = NULL;
    }else{
        (*q)->tail->next = new_node;
        new_node->next = NULL;
    }
    (*q)->tail = new_node;
    new_node->next = NULL;
}

char *pop(Queue *q) {
     if (!q || !(q->head)) return NULL;
     char *new_word = (char *)malloc(sizeof(char)*strlen(q->head->data)+1); 
     strcpy(new_word, q->head->data);  
     
     Node *node = q->head;
     q->head = q->head->next;
     free(node->data);
     free(node);
     return new_word;    
}

void print(Queue *q) {
    if (!q || !q->head) {
        printf("No items\n");
    }else{
        Node *node = q->head;
        while(node){
            printf("%s\n", node->data);
            node = node->next;
         }
    }
}

int isEmpty(Queue *q) {
    if  (!q || !q->head){
        return 1;
    }
    return 0;
}

void delete(Queue *q) {
    if (!isEmpty(q)){
        while(q->head){
            Node *temp = q->head->next;
            free(q->head->data);
            free(q->head);
            q->head  = temp;
        }
    }
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Queue *q = NULL;

    // print the queue
    print(q);

    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    
    print(q);
    
    // pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        printf("%s\n", item);
        free(item);
    }


    char *item = pop(q);
    assert(item == NULL);

    // push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);


    // destroy the queue
    delete(q);

    // print again
    print(q);
    
    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    
    //return 0;

    char *t = pop(q);
    

    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);
}
