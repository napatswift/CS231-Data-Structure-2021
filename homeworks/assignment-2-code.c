/* 6310400967
 * Napat Dollapavaijit
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int size;
    char* name;
    struct Node* parent;
    struct Node* leftChild;
    struct Node* rightSibling;
} Node;

Node* createRoot(int size, char* name){
    Node* root = (Node*) malloc(sizeof(Node));

    root->size = size;
    root->name = name;
    root->parent = NULL;
    root->leftChild = NULL;
    root->rightSibling = NULL;

    return root;
}

Node* createNode(int size, char* name, Node* parent){
    Node* node = (Node*) malloc(sizeof(Node));

    node->size = size;
    node->name = name;
    node->parent = parent;
    node->leftChild = NULL;
    node->rightSibling = NULL;

    if (node->parent != NULL){
        if (parent->leftChild != NULL){
            Node* childNode = parent->leftChild;
            while(childNode->rightSibling != NULL)
                childNode = childNode->rightSibling;
            childNode->rightSibling = node;
        } else {
            parent->leftChild = node;
        }
    }

    return node;
}

int isExternal(Node* node){
    if (node->leftChild == NULL)
        return 1;
    return 0;
}

void printPreorder(Node* node){
    if (node == NULL)
        return;
    printf("%s ", node->name);
    printPreorder(node->leftChild);
    printPreorder(node->rightSibling);
}

int calcSize(Node* n, Node* r){
    if (n == NULL || r == n)
        return 0;
    else if (isExternal(n))
        return n->size + calcSize(n->rightSibling, r);
    return n->size 
            + calcSize(n->leftChild, r) 
            + calcSize(n->rightSibling, r);
}

void printSize(Node* n){
    if (n == NULL)
        return;
    printSize(n->leftChild);
    printSize(n->rightSibling);
    if (!isExternal(n)){
        printf("%s %dk\n", n->name, n->size + calcSize(n->leftChild, n));
    }
}


int main(){
    Node* root = createRoot(1, "/user/courses");
    Node* cs016 = createNode(2, "cs016", root);
    Node* cs252 = createNode(1, "cs252", root);
    createNode(8, "grades", cs016);

    Node* homeworks = createNode(1, "homeworks", cs016);
    createNode(3, "hw1", homeworks);
    createNode(2, "hw2", homeworks);
    createNode(4, "hw3", homeworks);

    Node* programs = createNode(1, "programs", cs016);
    createNode(57, "pr1", programs);
    createNode(97, "pr2", programs);
    createNode(74, "pr3", programs);

    Node* projects = createNode(1, "projects", cs252);
    Node* papers = createNode(1, "papers", projects);
    Node* demos = createNode(1, "demos", projects);

    createNode(3, "grades", cs252);
    createNode(26, "buylow", papers);
    createNode(55, "sellhigh", papers);
    createNode(4786, "market", demos);

    printf("in preorder:\n");
    printPreorder(root);
    printf("\n");
    printf("\n");
    printf("size of each dir:\n");
    printSize(root);
    return 0;
}
