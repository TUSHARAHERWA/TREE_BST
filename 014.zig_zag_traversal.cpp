#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int element) {
		this -> data = element;
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

node* zigZag(node* root) {
	queue<node*>q;
	q.push(root);
	bool flag = true;
	vector<vector<int>>ans;

	while(!q.empty()) {
		int size = q.size();
		vector<int>row(size);
		for(int i = 0; i < size; i++) {
		node* temp = q.front();
		q.pop();
		
		int index = (flag) ? i : (size - 1 - i);
		row[index] = temp -> data;

		if(temp -> left) {
			q.push(temp -> left);
		}

		if(temp -> right) {
			q.push(temp -> right);
		}
	}
	flag = !flag;
	ans.push_back(row);
	}
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	zigZag(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}