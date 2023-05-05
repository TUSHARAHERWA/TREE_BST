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

void print(node* root) {
	if(root == NULL) return;
	cout << root -> data << " ";
	print(root -> left);
	print(root -> right);
}

int main() {
	node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> right -> right = new node(44);
	print(root);
}