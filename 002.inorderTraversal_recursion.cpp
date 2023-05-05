#include<iostream>
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

void inorder(node * root) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left);
	cout << root -> data << " ";
	inorder(root -> right);
}

void solve() {
	node * root = NULL;
	root = buildTree(root);
	inorder(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}