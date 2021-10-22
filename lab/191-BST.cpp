#include<stdio.h>
#include<stdlib.h>


struct bst{
    int data;
    struct bst* left;
    struct bst* right;
};


void createBST(struct bst** root, int data){
    struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    struct bst *temp_root = *root;
    if(*root  == NULL){
        *root = temp;
        return;
    }
    if(data <= temp_root->data)
        createBST(&(temp_root->left),data);
    else
        createBST(&(temp_root->right),data);
}


void postOrderTraverse(struct bst* bst){
    if (bst==NULL)
        return;

    postOrderTraverse(bst->left);
    postOrderTraverse(bst->right);
    printf("%d ", bst->data);
}

void inOrderTraverse(struct bst* bst){
    if(bst==NULL)
        return;

    inOrderTraverse(bst->left);
    printf("%d ", bst->data);
    inOrderTraverse(bst->right);
}

void preOrderTraverse(struct bst* bst){
    if(bst == NULL)
        return;

    printf("%d ", bst->data);
    preOrderTraverse(bst->left);
    preOrderTraverse(bst->right);
}

int getMaxNum(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}

int getHeight(struct bst* bst){
        if(bst == NULL){
        return 0 ;
    }
    return getMaxNum(getHeight(bst->left),getHeight(bst->right)) + 1 ;
}

int main(){
    struct bst* root = NULL;
    int input;

    while(true){
        scanf("%d",&input);
        if(input == 0)
            break;
        createBST(&root,input);
    }

    if(getHeight(root) > 0 ){
        printf("height of tree is %d\n",getHeight(root)-1);

        printf("preorder: ");
        preOrderTraverse(root);
        printf("\n");

        printf("postorder: ");
        postOrderTraverse(root);
        printf("\n");

        printf("inorder: ");
        inOrderTraverse(root);
    }
    
    else{printf("empty tree");}
    return 0;
}
