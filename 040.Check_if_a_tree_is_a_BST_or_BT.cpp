#include<iostream>
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

bool isBst(node* root , int mini , int maxi) {
	if(root == NULL) 
		return true;

	if(root -> data >= maxi || root -> data <= mini) return false;
	return isBst(root -> left , mini, root -> data) && isBst(root -> right , root -> data , maxi);
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	int maxi = INT_MAX;
	int mini = INT_MIN;
	if(isBst(root, mini, maxi)) {
		cout << "true\n";
	}
	else {
		cout << "false\n";				
	}

}