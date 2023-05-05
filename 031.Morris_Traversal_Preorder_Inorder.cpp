#include<iostream>
#include<vector>
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

vector<int> morris_traversal(node* root) {
	vector<int>inorder;
	node* curr = root;
	while(curr != NULL) {
		if(curr -> left == NULL) {
			inorder.push_back(curr -> data);
			curr = curr -> right;
		}
		else {
			node* prev = curr -> left;
			while(prev -> right && prev -> right != curr) {
				prev = prev -> right;
			}
			if(prev -> right == NULL) {
				prev -> right = curr;
				curr = curr -> left;
			}
			else {
				prev -> right = NULL;
				inorder.push_back(curr -> data);
				curr = curr -> right;
			}
		}
	}
	return inorder;
}


vector<int> morris_traversal_preOrder(node* root) {
	vector<int>preorder;
	node* curr = root;
	while(curr != NULL) {
		if(curr -> left == NULL) {
			preorder.push_back(curr -> data);
			curr = curr -> right;
		}
		else {
			node* prev = curr -> left;
			while(prev -> right && prev -> right != curr) {
				prev = prev -> right;
			}
			if(prev -> right == NULL) {
				prev -> right = curr;
				preorder.push_back(curr -> data);
				curr = curr -> left;
			}
			else {
				prev -> right = NULL;
				curr = curr -> right;
			}
		}
	}
	return preorder;
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	vector<int>ans = morris_traversal_preOrder(root);
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}