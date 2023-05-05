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
	if(ele == -1) {
		return NULL;
	}
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

int findLeftHeight(node* root) {
	int ans = 0;
	while(root) {
		root = root -> left;
		ans++;
	}
	return ans;
}

int findRightHeight(node* root) {
	int a = 0;
	while(root) {
		a++;
		root = root -> right;
	}
	return a;

}

int countTotalNodes(node* root) {
	if(root == NULL) return 0;
	int leftHeight = findLeftHeight(root);
	int rightHeight = findRightHeight(root);
	if(leftHeight == rightHeight) return (1 << rightHeight) - 1;
	return 1 + countTotalNodes(root -> left) + countTotalNodes(root -> right);
}


int main() {
	node* root = NULL;
	root = buildTree(root);
	cout << countTotalNodes(root);
}