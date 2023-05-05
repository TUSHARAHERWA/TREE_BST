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

bool left_Right(node* root , vector<int> &ans , int x) {
	
	if(root == NULL) return false;

	ans.push_back(root -> data);

	if(root -> data == x) return true;
	if(left_Right(root -> left , ans , x) || left_Right(root -> right , ans , x)) return true;

	ans.pop_back();
	return false;
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	vector<int>ans;
	if(left_Right(root , ans , 7)) {
		for(auto it: ans) {
			cout << it << " ";
		}
	}
	else {
		cout << "NOT FOUND\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}