#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void insert(Node** head, int data){
    Node *root = *head;
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(root == NULL){
        *head = newNode;
    } else{
        if (root->data > data){
            newNode->next = root;
            *head = newNode;
        } else {
            Node* curr = root;
            while(curr->next != NULL)
                if (curr->next->data < data)
                    curr = curr->next;
                else
                    break;
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
}

int main(){
    Node *S = NULL;
    insert(&S, 1);
    insert(&S, 3);
    insert(&S, 5);
    insert(&S, 7);

    insert(&S, 4);
    return 0;
}
