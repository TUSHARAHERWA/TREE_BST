#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
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

node* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &mp) {

	if(preStart > preEnd || inStart > inEnd) return NULL;
	node* root = new node(preorder[preStart]);
	int inmap = mp[root -> data];
	int ans = inmap - inStart;
	root -> left = buildTree(preorder, preStart + 1, preStart + ans, inorder, inStart, inmap - 1, mp);
	root -> right = buildTree(preorder, preStart + ans + 1, preEnd, inorder, inmap + 1, inEnd, mp);
	return root;
}
	
void print(node* root) {
	if(root == NULL) return;
	print(root -> left);
	cout << root -> data << " ";
	print(root -> right);
}

node* buildTreeUsingPreorder(vector<int> &preorder, int &i, int bound) {
	if(i == preorder.size() || preorder[i] > bound) return NULL;
	node* root = new node(preorder[i++]);
	root -> left = buildTreeUsingPreorder(preorder , i , root -> data);
	root -> right = buildTreeUsingPreorder(preorder , i , bound);
	return root;
}

int main() {
	vector<int>preorder = {8,5,1,7,10,12};
	// vector<int>inorder = {8,5,1,7,10,12};
	// sort(inorder.begin(), inorder.end());
	// brute force -> store preorder in vector then sort that vector to get inorder, build tree
	// unordered_map<int,int>mp;
	// for(int i = 0; i < inorder.size(); i++) {
	// 	mp[inorder[i]] = i; 
	// }
	// node* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
	// print(root);

	// optimized 
	int i = 0;
	node* root = buildTreeUsingPreorder(preorder, i, INT_MAX);
	print(root);

}