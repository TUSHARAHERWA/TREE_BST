#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int ele) {
		this -> data = ele;
		this -> left = NULL;
		this -> right = NULL;
	}
};

Node* buildTree(Node* root) {
	int d;
	cin >> d;
	root = new Node(d);
	if(d == -1) return NULL;
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

void print(Node* root) {
	if(root == NULL) return;
	cout << root -> data <<" ";
	print(root -> left);
	print(root -> right);
}

void SearchBST(Node* root , int target) {
	bool flag = false;
	while(root != NULL) {
		if(root -> data == target) {
			flag = true;
		}
		if(root -> data < target) {
			root = root -> right;
		}
		else {
			root = root -> left;
		}
	}
	if(flag) cout << "Present";
	else cout << "Not Present";
}

void solve() {
	Node* root = NULL;
	root = buildTree(root);
	SearchBST(root , 15);
	// print(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}