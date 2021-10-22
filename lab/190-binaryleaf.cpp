#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct node {
    int key;
    string label;
    int parent;
    struct node* left;
    struct node* right; 
}Node;

Node* createNode(string label, int key, int parent) {
    Node* node = new Node();

    node->key = key;
    node->parent = parent;
    node->label = label;

    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void addNode(vector<Node*> *t, int parent, int child, string label) {
    Node* node = createNode(label, child, parent);
    t->push_back(node);
}


void linkNode(vector<Node*> *t, Node *node) {

    for(int i = 0;i < t->size(); ++i) {
        Node* currNode = t->at(i);
        if(currNode->key == node->parent) {
            if(node->label == "R" && currNode->right == NULL) {
                currNode->right = node;
            }
            else if(node->label == "L" && currNode->left == NULL) {
                currNode->left = node;
            }
            return;
        }
    }
}

void linkTree(vector<Node*> *t) {

    for(int i = 0; i < t->size(); ++i) {
        linkNode(t, t->at(i));
    }

}


// Node* addNode(node* root, int parent, int child, string label) {

//     if(root == NULL)
//         return NULL;

//     if(root->key != parent) {
//         Node* leftNode = linkNode(root->left, parent, child, label);
        
//         if(leftNode == NULL)
//             linkNode(root->right, parent, child, label);
        
//         return NULL;
//     }

//     Node *node = createNode(label, parent, child);
//     if(label == "L" && root->left == NULL) {
//         root->left = node; 
//         return node;
//     }
//     else if(label == "R" && root->right == NULL) {
//         root->right = node;
//         return node;
//     }

//     return NULL;
// }

int countLabel(string label, Node *root) {
    int cnt = 0;

    if(root == NULL)
        return 0;

    cnt += countLabel(label, root->left);

    if(root->label == label && root->left == NULL && root->right == NULL)
        ++cnt;

    cnt += countLabel(label, root->right);

    return cnt;
}

int countExternalNode(Node* root) {
    int cnt = 0;

    if(root == NULL)
        return 0;

    cnt += countExternalNode(root->left);

    if(root->left == NULL && root->right == NULL)
        ++cnt;

    cnt += countExternalNode(root->right);

    return cnt;
}

void inOrder(Node* root) {
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->key << endl;
    inOrder(root->right);
}

void printTree(vector<Node*> t) {
    for(int i = 0; i < t.size(); ++i)
        cout << t.at(i)->key << endl;
}

int main() {

    int r = 0, n, parent, child;
    string label;
    vector<Node*> t;

    cin >> r >> n;

    Node* root = createNode("Root", r, -1);
    t.push_back(root);

    for(int i = 0; i < n; ++i) {
        cin >> parent >> child >> label;
        addNode(&t, parent, child, label);
    }

    linkTree(&t);

    // inOrder(root);

    // printTree(t);

    // cout << t.at(0)->right->key << endl;

    cout << countLabel("L", root) << " " << countLabel("R", root) << endl; 
    // cout << countExternalNode(root);
    
}