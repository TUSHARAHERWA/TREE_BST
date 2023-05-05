#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int ele) {
		this -> data = ele;
		this -> left = NULL;
		this -> right = NULL;
	}
};

node* buildTree(node* root) {
	int element;
	cin >> element;
	root = new node(element);

	if(element == -1) return NULL;

	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);

	return root;
}

void postOrder(node* root) {
	if(root ==  NULL) return;

	postOrder(root -> left);
	postOrder(root -> right);
	cout << root -> data << " ";
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	postOrder(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}