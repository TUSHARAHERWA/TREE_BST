#include<iostream>
#include<unordered_map>
#include<queue>
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

node* markParentPointers(node* root , unordered_map<node*,node*> &parent , int nodeVal) {
	queue<node*>q;
	q.push(root);
	node* parentN;

	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			node* temp = q.front();
			if(temp -> data == nodeVal) parentN = temp;
			q.pop();
			if(temp -> left) {
				q.push(temp -> left);
				parent[temp -> left] = temp;
			}
			if(temp -> right) {
				q.push(temp -> right);
				parent[temp -> right] = temp;
			}
		}
	}
	return parentN;
}

int timeToBurn(unordered_map<node*,node*> &parent, node* target) {
	queue<node*>q;
	unordered_map<node*,bool>visited;
	int ans = 0;
	q.push(target);
	visited[target] = true;
	while(!q.empty()) {
		int size = q.size();
		bool flag = false;
		for(int i = 0; i < size; i++) {
			node* nodes = q.front();
			q.pop();
			if(nodes -> left && !visited[nodes -> left]) {
				q.push(nodes -> left);
				visited[nodes -> left] = true;
				flag = true;
			}
			if(nodes -> right && !visited[nodes -> right]) {
				q.push(nodes -> right);
				visited[nodes -> right] = true;
				flag = true;
			}
			if(parent[nodes] && !visited[parent[nodes]]) {
				q.push(parent[nodes]);
				visited[parent[nodes]] = true;
				flag = true;
			}
		}
		if(flag) ans++;
	}
	return ans;
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	int nodeVal = 3;
	unordered_map<node*,node*>parent;
	node* target = markParentPointers(root, parent, nodeVal);
	int maxi = timeToBurn(parent , target);
	cout << maxi << "\n";
}