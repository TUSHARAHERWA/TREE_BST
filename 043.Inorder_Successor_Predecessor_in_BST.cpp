#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int val) {
		this -> data = val;
		this -> left = NULL;
		this -> right = NULL; 
	}
};

node* buildTree(node* root) {
	int ele;
	cin >> ele;
	root = new node(ele);
	if(ele == -1) return NULL;
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

void Successor(node* root, int x, int &store) {
	while(root != NULL) {
		if(root -> data <= x) {
			root = root -> right;
		}
		else {
			store = root -> data;
			root = root -> left;
		}
	}
}

void Predecessor(node* root, int x, int &store2) {
	while(root != NULL) {
		if(root -> data >= x) {
			root = root -> left;
		}
		else {
			store2 = root -> data;
			root = root -> right;
		}
	}
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	int store = 0;
	int store2 = 0;
	Successor(root, 13, store);
	Predecessor(root, 14, store2);
	cout << store << " ";
	cout << store2 << " ";
}
