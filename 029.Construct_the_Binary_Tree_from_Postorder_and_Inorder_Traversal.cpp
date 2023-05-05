#include<iostream>
#include<vector>
#include<unordered_map>
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
	if(root == NULL) {
		return;
	}
	print(root -> left);
	print(root -> right);
	cout << root -> data << " ";
}
	
node* constructBinaryTree(vector<int> &postorder, int postStart , int postEnd,
				 vector<int> &inorder, int inStart , int inEnd, unordered_map<int,int> &mp) {
	if(postStart > postEnd || inStart > inEnd) return NULL;
	node* root = new node(postorder[postEnd]);
	int nElements = mp[postorder[postEnd]]; 	
	root -> left = constructBinaryTree(postorder , postStart, postStart + nElements - inStart - 1, inorder, inStart, nElements - 1, mp);
	root -> right = constructBinaryTree(postorder , postStart + nElements - inStart  , postEnd - 1 , inorder , nElements + 1 , inEnd , mp);
	return root;
}

int main() {		   
	vector<int>inorder{40,20,50,10,60,30};
	vector<int>postorder{40,50,20,60,30,10};
	unordered_map<int,int>mp;
	for(int i = 0; i < inorder.size(); i++) {
		mp[inorder[i]] = i;
	}
	node* root = constructBinaryTree(postorder, 0 , postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
	print(root);
}