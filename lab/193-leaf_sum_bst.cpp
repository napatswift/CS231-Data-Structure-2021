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

void sumLeafNode(Node *root, long &sum){
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr){
        sum += root->data;
    }
    
    sumLeafNode(root->left, sum);
    sumLeafNode(root->right, sum);
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
        long sum = 0;
        sumLeafNode(root, sum);
        cout << sum;

    }

    else{
        cout << "empty tree";

    }

    return 0;
}
