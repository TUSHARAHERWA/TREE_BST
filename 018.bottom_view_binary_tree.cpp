#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int data) {
		this -> data = data;
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

void topView(node* root) {
	queue<pair<node*,int>>qu;
	map<int,int>mp;

	qu.push({root , 0}); 

	while(!qu.empty()) {
		auto temp = qu.front();
		qu.pop();
		node* n = temp.first;
		int x = temp.second;
		mp[x] = n -> data;
		if(n -> left) {
			qu.push({n -> left , x - 1});
		}
		if(n -> right) {
			qu.push({n -> right , x + 1});
		}
	}
	vector<int>ans;
	for(auto it: mp) {
		ans.push_back(it.second);
	}
	for(auto t: ans) {
		cout << t << " ";
	}
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	topView(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}