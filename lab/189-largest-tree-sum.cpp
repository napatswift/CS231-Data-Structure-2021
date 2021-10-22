#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	vector<Node*> child;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	return temp;
}

int total = 0;
void maxSumUtil(Node* root)
{  
	if (root == NULL)
		return;

	int count = root->child.size();

	for (int i = 0; i < count; i++) {
        total += root->child[i]->key;
	}

    for (int i = 0; i < count; i++){
        maxSumUtil(root->child[i]);
    }
}

list<int> sumList;
void maxSum(Node* root)
{
    //Tree
    total += root->key;
    maxSumUtil(root);
    sumList.push_back(total);

    //SubTree
    for (int i = 0; i < (int)(root->child).size(); i++){
        total = 0;
        total += root->child[i]->key;
        maxSumUtil(root->child[i]);
        sumList.push_back(total);
    }

    
}

void findHigherChild (vector<Node*> root, int parentData, int childData){
    for (int i = 0; i < (int)root.size() ; i++){
        if (root[i]->key == parentData){
            (root[i]->child).push_back(newNode(childData));
            return;
        }
    }

    for (int i = 0; i < (int)root.size(); i++){
        findHigherChild(root[i]->child, parentData, childData);
    }
}

int main()
{
    int rootData, numNode;
    cin >> rootData >> numNode;
	Node* root = newNode(rootData);

    for (int i = 1; i < numNode; i++){
        int parentNodeData, childNodeData;
        cin >> parentNodeData >> childNodeData;
        if (parentNodeData == rootData){
            (root->child).push_back(newNode(childNodeData));
        }
        else{
            findHigherChild(root->child, parentNodeData, childNodeData);
        }
    }
    maxSum(root);

    int higher = numeric_limits<int>::min();
    for (int sum : sumList){
        if (sum > higher) higher = sum;
    }
	cout << higher;
	return 0;
}