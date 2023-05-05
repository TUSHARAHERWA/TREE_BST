#include<iostream>
#include<algorithm>
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
	root -> right =buildTree(root -> right);
	return root;
}

int maxDepth(node* root) {
	if(root == NULL) return 0;

	int leftHeight = maxDepth(root -> left);
	int rightHeight = maxDepth(root -> right);

	return max(leftHeight , rightHeight) + 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node* root = buildTree(root);
	cout << maxDepth(root);
}

// time complexity -> O(N)

// space compleixty -> O(1) , 
// Recursion Stack space -> O(H) where “H”  is the height of the binary tree