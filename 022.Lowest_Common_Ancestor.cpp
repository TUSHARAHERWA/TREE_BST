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


node* LCA(node* root , int x , int y) {
	if(root == NULL) {
	   return NULL;
	}
	if(root -> data == x || root -> data == y) {
		return root;
	}
	node* left = LCA(root -> left , x , y);
	node* right = LCA(root -> right  , x , y);
    if(left && right) {
		return root;
	} 
	else if(left == NULL) {
		return right;
	}
	else {
		return left;
	}
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	node* ans = LCA(root , 2 , 3);
	cout<< ans -> data << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}