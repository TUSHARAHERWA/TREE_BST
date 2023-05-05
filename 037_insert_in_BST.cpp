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

void insertInBst(node* root , int val) {
	while(root != NULL) {
		if(root -> data > val) {
			if(root -> left != NULL) {
			root = root -> left;
			}
		else {
			root -> left = new node(val);
			break;
			}
		}
		else {
			if(root -> right != NULL)
			root = root -> right;
			else {
			root -> right = new node(val);
			break;
			}
		}

	}
}

void print(node* root) {
	if(root == NULL) return;
	cout << root -> data << " ";
	print(root -> left);
	print(root -> right);
}


void solve() {

	node* root = NULL;
	root = buildTree(root);
	int val = 9;
	print(root);
	cout << "after\n";
	insertInBst(root , val);
	print(root);



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}