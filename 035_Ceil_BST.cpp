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

void Ceil(Node* root , int target) {
	int c = -1;
	while(root != NULL) {
		if(root -> data == target) {
			c = target;
			break;
		}

		if(target > root -> data) {
			root = root -> right;
		}
		else {
			c = root -> data;
			root = root -> left;
		}
	}
	cout << c;
}

void solve() {
	Node* root = NULL;
	root = buildTree(root);
	Ceil(root , 4);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}