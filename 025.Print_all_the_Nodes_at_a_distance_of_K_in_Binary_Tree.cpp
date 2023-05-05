#include<iostream>
#include<unordered_map>
#include<queue>
#include<unordered_set>
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
	if(ele == -1) {
		return NULL;
	}
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

node* printDistanceK(node* root , unordered_map<node*,node*> &parent, node* target, int &k, vector<int> &ans) {
	unordered_map<node*,bool>visited;
	queue<node*>qu;
	qu.push(target);
	visited[target] = true;
	int curr_level = 0;
	while(!qu.empty()) {
		int size = qu.size();
		if(curr_level++ == k) break;
		for(int i = 0; i < size; i++) {
			node* n = qu.front(); 	 
			qu.pop();
			if(n -> left && !visited[n -> left]) {
				qu.push(n -> left);
				visited[n -> left] = true;
			}
			if(n -> right && !visited[n -> right]) {
				qu.push(n -> right);
				visited[n -> right] = true;
			}
			if(parent[n] && !visited[parent[n]]) {
				qu.push(parent[n]);
				visited[parent[n]] = true;
			}
		}
	}
	while(!qu.empty()) {
		node* tempp = qu.front();
		qu.pop();
		ans.push_back(tempp -> data);
	}

}

node* markParentPointer(node* root , unordered_map<node*,node*> &parent) {
	queue<node*>q;
	q.push(root);
	while(!q.empty()) {
		node* temp = q.front();
		q.pop();
		if(temp -> left) {
			parent[temp -> left] = temp;
			q.push(temp -> left);
		}
		if(temp -> right) {
			parent[temp -> right] = temp;
			q.push(temp -> right);
		}
	}
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	unordered_map<node*, node*>parent;
	markParentPointer(root , parent); // using level order traversal
	node* target = root;
	int k = 1;
	vector<int>ans;
	printDistanceK(root , parent , target , k , ans);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}