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
	
node* constructBinaryTree(vector<int> &preorder, int preStart , int preEnd,
				 vector<int> &inorder, int inStart , int inEnd, unordered_map<int,int> &mp) {
	if(preStart > preEnd || inStart > inEnd) return NULL;
	node* root = new node(preorder[preStart]);
	int storeInorderRoot = mp[root -> data];
	int nElements = storeInorderRoot - inStart;
	root -> left = constructBinaryTree(preorder , preStart + 1 , preStart + nElements, inorder, inStart, storeInorderRoot - 1, mp);
	root -> right = constructBinaryTree(preorder , preStart + nElements + 1 , preEnd , inorder , storeInorderRoot + 1 , inEnd , mp);
	return root;

}

int main() {		   
	vector<int>inorder{40,20,50,10,60,30};
	vector<int>preorder{10,20,40,50,30,60};
	unordered_map<int,int>mp;
	for(int i = 0; i < inorder.size(); i++) {
		mp[inorder[i]] = i;
	}
	node* root = constructBinaryTree(preorder, 0 , preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
	print(root);
}