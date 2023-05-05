#include<iostream>
#include<limits.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int element) {
		this -> data = element;
		this -> left = NULL;
		this -> right = NULL;
	}
};

node* buildTree(node * root) {
	int element;
	cin >> element;
	root = new node(element);

	if(element == -1) 
		return NULL;

	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

class NodeValue {
public:
	int maxNode, minNode, maxSize;
	NodeValue(int minNode, int maxNode, int maxSize) {
		this -> maxNode = maxNode;
		this -> minNode = minNode;
		this -> maxSize = maxSize;
	}
};

NodeValue largestBST(node* root) {
	if(!root) {
		return NodeValue(INT_MAX, INT_MIN, 0);
	}

	NodeValue left = largestBST(root -> left);
	NodeValue right = largestBST(root -> right);

	if(left.maxNode < root -> data && root -> data < right.minNode) {
		return NodeValue(min(root -> data, left.minNode), max(root-> data, right.maxNode), left.maxSize + right.maxSize + 1);
	}

	return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int main() {
	node* root = NULL;
	root = buildTree(root);
 	int ans = largestBST(root).maxSize;
 	cout << ans << " ";
}