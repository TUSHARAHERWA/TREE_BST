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

bool checkSymmetrical(node* root1 , node* root2) {
	if(root1 == NULL || root2 == NULL) return(root1 == root2);

	if(root1 -> data != root2 -> data) return false;

	return checkSymmetrical(root1 -> left , root2 -> right) 
	&& checkSymmetrical(root1 -> right , root2 -> left);
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	if(checkSymmetrical(root -> left , root -> right)) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}