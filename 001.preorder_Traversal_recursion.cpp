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

	if(root == NULL) 
		return;

	cout << root -> data << " ";
	print(root -> left);
	print(root -> right);
}

node* buildTree(node* root) {
	int ele;
	cin >> ele;
	root = new node(ele);
	if(ele == -1) return NULL;
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node* root = buildTree(root);
	print(root);
}