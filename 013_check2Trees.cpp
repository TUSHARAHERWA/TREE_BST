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

bool checkIdentical(node* root , node* root2) {
	if(root == NULL || root2 == NULL) {
		// cout << "ENTER ";
		return (root == root2);
	}
	return (root -> data == root2 -> data) && checkIdentical(root -> left , root2 -> left) && checkIdentical(root -> right , root2 -> right);
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	node* root2 = NULL;
	root2 = buildTree(root2);
	if(checkIdentical(root , root2)) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}