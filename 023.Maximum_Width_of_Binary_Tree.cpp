#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class tree {
public:
	int data;
	tree* left;
	tree* right;
	tree(int ele) {
		this -> data = ele;
		this -> left = NULL;
		this -> right = NULL;
	}
};

tree* buildTree(tree* root) {
	int e;
	cin >> e;
	root = new tree(e);
	if(e == -1) return NULL;
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

// void print(tree* root) {
// 	if(root == NULL) return;
// 	cout << root -> data << " ";
// 	print(root -> left);
// 	print(root -> right);

// }

void max_width(tree * root) {
	int ans = 0;
	queue<pair<tree*, int>>q;
	int ab , bc;
	q.push({root , 0});
	vector<int>a;
	while(!q.empty()) {
		int size = q.size();
		int mini = q.front().second;
		for(int i = 0; i < size; i++) {
		tree* node = q.front().first;
		int x = q.front().second - mini;
		q.pop();
		if(i == 0) ab = x;
		if(i == size - 1) bc = x;
		if(node -> left != NULL) {
			q.push({node -> left , 2*x+1});
		}
		if(node -> right != NULL) {
			q.push({node -> right , 2*x+2});
		}
	}
	ans = max(ans , bc - ab);
}
	cout << ans + 1 << " ";
}

void solve() {
	tree* root = NULL;
	root = buildTree(root);
	// print(root);
	max_width(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}