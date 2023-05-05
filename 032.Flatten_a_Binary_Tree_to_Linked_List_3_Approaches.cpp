#include<iostream>
#include<stack>
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

void usingRecursion(node* root, node* &prev) {
	if(root == NULL) return;
	usingRecursion(root -> right, prev);
	usingRecursion(root -> left, prev);
	root -> right = prev;
	root -> left = NULL;
	prev = root;
}

void usingStack(node* root, stack<node*> &st) {
	st.push(root);
	while(!st.empty()) {
		node* curr = st.top();
		st.pop();
		if(curr -> right) st.push(curr -> right);
		if(curr -> left) st.push(curr -> left);
		if(!st.empty()) {
			curr -> right = st.top();
		}
		curr -> left = NULL;
	}
}


void usingThread(node* root) {
	node* curr = root;
	while(curr != NULL) {
		if(curr -> left != NULL) {
		node* prev = curr -> left;
		while(prev -> right) prev = prev -> right;
		prev -> right = curr -> right;
		curr -> right = curr -> left;
		curr -> left = NULL;
		}
		curr = curr -> right;
	}
}

int main() {
	node* root = NULL;
	node* prev = NULL;
	root = buildTree(root);

	// 1st
/*	usingRecursion(root, prev);
	while(root -> right != NULL) {
		cout << root -> data << " ";
		root = root -> right;
	}
	cout << root -> data << " ";
*/
	
	// 2nd	
/*	stack<node*>st;
	usingStack(root, st);
	while(root -> right != NULL) {
		cout << root -> data << " ";
		root = root -> right;
	}
	cout << root -> data << " ";
*/
	
	// 3rd
/* usingThread(root);
	while(root -> right != NULL) {
		cout << root -> data << " ";
		root = root -> right;
	}
	cout << root -> data << " ";
*/
	
}