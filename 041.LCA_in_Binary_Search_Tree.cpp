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

node* findLca(node* root , int x , int y) {
	while(root != NULL) {
		if(root -> data > x && root -> data > y) {
			root = root -> left;
		}
		else if(root -> data < x && root -> data < y) {
			root = root -> right;
		}
		else {
			return root;
			break;
		}
	}
	return root;
}



int main() {
	node* root = NULL;
	root = buildTree(root);
	node* ans = findLca(root, 1, 3);
	cout << ans -> data << " ";
}
