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

void delete(Node **head, int data){
    Node *curr = *head;
    if (curr->data == data){
        *head = curr->next;
        free(curr);
        return;
    }
    while(curr->next != NULL)
        if(curr->next->data != data)
            curr = curr->next;
        else
            break;
    Node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

void printl(Node *head){
  Node* curr = head;
  while(curr!=NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main(){
    Node *head = NULL;
    char tmp;
    while(1){
        scanf("%c",&tmp);
        if(tmp == 'A'){
            int data;
            scanf("%d", &data);
            insert(&head, data);
            printl(head);
        }else if(tmp == 'D'){
            int data;
            scanf("%d", &data);
            delete(&head, data);
            printl(head);
        }else if(tmp == 'Q'){
            printl(head);
            return 0;
        }
    }
    return 0;
}
