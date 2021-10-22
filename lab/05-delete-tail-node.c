/**
 * Napat Dollapavijit
 * 6310400967
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int item;
    struct node *next;
};

typedef struct node node_t;

struct head{
    int length;
    node_t *first, *last;
};

typedef struct head head_t;

node_t* inst_node(int val, node_t *ptr){
    node_t *new;
    if ((new = malloc(sizeof(node_t))) != NULL){
        new->item = val;
        new->next = ptr;
    }
    return new;
}

void insertFront(int data, head_t* head){
    node_t *new;
    new = inst_node(data, head->first);
    head->first = new;
    if(head -> length == 0)
        head->last = new;
    head->length++;
}

void deleteTail(head_t *head){
    if (head->length < 1)
        return;
    else if (head->length == 1){
        free(head->first);
        head->first = NULL;
        head->last = NULL;
        head->length--;
        return ;
    }

    size_t i;
    node_t *curr = head->first;
    for(int i = 0; i < head->length-2;i++)
        curr = curr->next;
    node_t *target = curr->next;
    curr->next = target->next;
    head->last = curr->next;
    head->length -= 1;
    free(target);
}

void deleteEndList(head_t *head) {
    if (head->length <= 0){
        return;
    }
    node_t *current = head->first;
    while(current->next->next != NULL){
        current = current->next;
    }
    head->length -= 1;
    if(head->length == 0){
        free(head->first);
        head->first = NULL;
        head->last = NULL;
        return;
    }
    free(current->next);
    current->next = NULL;
    head->last = current;
}

void printList(head_t * head){
    node_t * current;
    int i;
    current=head->first;
    if (head->length == 0)
        printf("Empty list\n");
    else{
        printf("link list\n");
        while(current->next != NULL){
            printf("%d\t",current->item);
            current = current->next;
        }
        printf("%d\t",current->item);
    printf("\n");
    }
}

int main(){
    head_t head;
    head.length = 0;
    head.first = NULL;
    head.last = NULL;
    for (size_t i = 0; i<5; i++)
        insertFront(35 - i, &head);
    for (size_t i = 0; i<6; i++){
        printList(&head);
        deleteTail(&head);
    }
    return 0;
}


