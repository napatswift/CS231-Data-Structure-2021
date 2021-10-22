#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 

struct node {
    int key;
    struct node* parent;
    struct node* left;
    struct node* right;
};  
struct node* parnod;

struct node* createRoot(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void findKey(struct node* root,int parent_int) {
    struct node* child = root;
    for(child = child->left ; child != NULL ; child = child->right){
        findKey(child,parent_int);
    }
    if(root->key == parent_int){
        parnod = root;
    }
}

struct node* createNode(int parent_int, int child_int, struct node* root){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    findKey(root, parent_int);
    node->key = child_int;
    node->parent = parnod;
    node->left = NULL;
    node->right = NULL;
    if(node->parent != NULL) {

    if(node->parent->left != NULL) {
        struct node* child = node->parent->left;
        while(child->right != NULL) {
            child = child->right;
            }
        child->right = node;
    }
    else {
    node->parent->left = node;
    }
    }
    return node;
}

int main() {   
    vector<string> vec;
    char str[100], str2[100], arr[100][100];
    int num,parent,child,root,target, index;
    root = 0;
    scanf("%d",&num);
    scanf("%s",&str);
    strcpy(arr[0], str); 
    // scanf("%d",&root);
    struct node *root_tree[1000];
    root_tree[root] = createRoot(root);
    index = 1;

    for(int i =0 ; i<num ;i++){
        
        scanf("%s %s",&str2,&str);
        strcpy(arr[index], str); 

        for(int j = 0; j<100; j++) {
            if (strcmp(arr[j], str2) == 0) {
                parent = j;
                break;
            }
        }

        child = index;
        root_tree[child]=createNode(parent,child,root_tree[root]);
        index++;
    }

    int no_path = -1;
    scanf("%s",&str);
    for(int j = 0; j<100; j++) {
            if (strcmp(arr[j], str) == 0) {
                target = j;
                no_path = target;
                break;
            }
        }
    
    if (no_path == -1) {
        cout << "No Path!"; 
        return 0;
    } 

    int path[num+2];

    for(int i =0; i<num+2;i++){
        path[i]=9999;
    }
    
    int i=0;
    struct node *ptr=root_tree[target];

    while(true){
        path[i] = ptr->key;
        if(ptr->parent==NULL) break;
        ptr=ptr->parent;
        i++;
    }

    for(int i=num+1;i>=0;i--){
        if(path[i]==9999) continue;
        if(i==0) printf("%s", arr[path[i]]);
        else printf("%s/",arr[path[i]]);
    }
    
    return 0; 
}