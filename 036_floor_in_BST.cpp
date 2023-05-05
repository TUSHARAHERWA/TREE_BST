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
	if(ele == -1) return NULL;
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

void SearchF(node* root , int target) {
	int ans = -1;
	while(root != NULL) {
		if(root -> data > target) {
			root = root -> left;
		}
		else {
			ans = root -> data;
			root = root -> right;
		}
	}
	cout << ans;
}


void solve() {

	node* root = NULL;
	root = buildTree(root);
	int target = 11;
	SearchF(root , target);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}