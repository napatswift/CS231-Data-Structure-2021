#include <iostream>
using namespace std;
 
struct Node
{
    long data;
    Node *left, *right;
};
 
Node* newNode(long key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
 
Node* insert(Node* root, long key){
    if (root == nullptr) {
        return newNode(key);
    }
 
    if (key <= root->data) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}

int max(int x, int y) {
   return (x >= y)? x: y;
}

int height(Node* node) { 
    if (node == NULL)
        return 0;
        
    return 1 + max(height(node->left), height(node->right));
}

bool AVL(Node *root) {
   int lh;
   int rh;
   if(root == NULL)
      return 1;
   lh = height(root->left);
   rh = height(root->right);
   if (abs(lh-rh) <= 1 && AVL(root->left) && AVL(root->right)) return 1;
   return 0;
}

int main(){
    long keys[10000];
    for (int i = 0 ; ; i++ ){
        cin >> keys[i];
        if (keys[i] == 0){
            break;
        }
    }

    if (keys[0] != 0){
        Node* root = nullptr;
        for (long key: keys) {
            if (key == 0){
                break;
            }
            root = insert(root, key);
        }

        if (AVL(root)){
            cout << "This tree has AVL property";
        }else{
            cout << "This tree doesn't have AVL property";
        }
    }

    else{
        cout << "empty tree";

    }

    return 0;
}