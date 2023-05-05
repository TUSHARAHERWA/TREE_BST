#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
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

void storeInVector(node* root, vector<int> &inorder) {
	if(root == NULL) return;
	storeInVector(root -> left, inorder);
	inorder.push_back(root -> data);
	storeInVector(root -> right, inorder);
}

void traversalSwap(node* root, vector<int> &inorder, int &i) {
	if(root == NULL) return;
	traversalSwap(root -> left , inorder, i);
	if(root -> data != inorder[i]) {
		root -> data = inorder[i];
	}
	i++;
	traversalSwap(root -> right, inorder, i);
}

void print(node* root) {
	if(root == NULL) return;
	print(root -> left);
	cout << root -> data << " ";
	print(root -> right);
}

void inorder(node* root, node* &first, node* &prev, node* &middle, node* &last) {
	if(root == NULL) return;
	inorder(root -> left, first, prev, middle, last);

	if(prev != NULL && (root -> data < prev -> data)) {
		if(first == NULL) {
			first = prev;
			middle = root;
			// cout <<" " <<  first -> data << " " << middle -> data << " ";
		}
		else {
			last = root;
		}
	}
	// cout << prev -> data << " " << root -> data << "\n";
	prev = root;
	inorder(root -> right, first, prev, middle, last);
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	// brute force
	// vector<int>inorder;
	// storeInVector(root, inorder);
	// sort(inorder.begin(), inorder.end());
	// print(root);
	// int i = 0;
	// cout << "\n";
	// traversalSwap(root, inorder, i);
	// print(root);

	// optimized 
	print(root);
	cout << "\n";
	node* first;
	node* prev;
	node* middle;
	node* last;
	first = middle = last = NULL;
	prev = new node(INT_MIN);
	inorder(root, first, prev, middle, last);
	if(first && last) swap(first -> data , last -> data);
	else if(first && middle) swap(first -> data, middle -> data);
	print(root);


	
}