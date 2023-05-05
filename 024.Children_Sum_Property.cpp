#include<iostream>
using namespace std;

class node {
public:
	int d;
	node* left;
	node* right;
	node(int val) {
		this -> d = val;
		this -> left = NULL;
		this -> right = NULL;
	}
};

node* build(node* root) {
	int ele;
	cin >> ele;
	if(ele == -1) return NULL;
	root = new node(ele);
	root -> left = build(root -> left);
	root -> right = build(root -> right);
	return root;
}

void prinT(node* root) {
	if(root == NULL) return;
	cout << root -> d << " ";
	prinT(root -> left);
	prinT(root -> right);
}

void SUM(node* root) {
	if(root == NULL) return;

	int child = 0;
	if(root -> left) child += root -> left -> d;
	if(root -> right) child += root -> right -> d;

	if(child >= root -> d) {
		root -> d = child;
	}
	else {
		if(root -> left) root -> left -> d = root -> d;
		if(root -> right) root -> right -> d = root -> d;
	}

	SUM(root -> left);
	SUM(root -> right);

	int total = 0;
	if(root -> left) total += root -> left -> d;
	if(root -> right) total += root -> right -> d;

	if(root -> left || root -> right) {
		root -> d = total;
	}
}

void solve() {
	node* root = NULL;
	root = build(root);
	prinT(root);
	cout << "\n";
	SUM(root);
	prinT(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}