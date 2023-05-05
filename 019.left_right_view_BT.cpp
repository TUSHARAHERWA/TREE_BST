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

void left_Right(node * root , vector<int> &ans, int level) {
	if(root == NULL) return;
	
	if(level == ans.size()) ans.push_back(root -> data);
	left_Right(root -> right , ans , level + 1); // change root -> right to root -> left for left view
	left_Right(root -> left , ans , level + 1);	// change root -> left to root -> right for left view
}

void solve() {
	vector<int>ans;
	node* root = NULL;
	root = buildTree(root);
	left_Right(root , ans, 0);
	for(auto it: ans) {
		cout << it << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}