#include<iostream>
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

bool isLeaf(node* root) {
	return !root -> left && !root -> right;
}

void leftTreeExcludingLeaf(node* root , vector<int>&res) {
	node* curr = root -> left;
	while(curr) {
		if(!isLeaf(curr)) res.push_back(curr -> data);
		if(curr -> left) curr = curr -> left;
		else curr = curr -> right;
	}
}

void leafNodes(node* root , vector<int>&res) {
	if(isLeaf(root)) {
		res.push_back(root -> data);
		return;
	}
	if(root -> left) leafNodes(root -> left , res);
	if(root -> right) leafNodes(root -> right , res);
}

void RightTreeExcludingLeaf(node* root , vector<int>&res) {
	node* curr = root -> right;
	vector<int>temp;
	while(curr) {
		if(!isLeaf(curr)) temp.push_back(curr -> data);
		if(curr -> right) curr = curr -> right;	
		else curr = curr -> left;	
	}
	for(int i = temp.size()-1; i >= 0; i--) {
		res.push_back(temp[i]);
	}
}



int boundary(node* root , vector<int>&res) {

	if(!isLeaf(root)) res.push_back(root -> data);	
	leftTreeExcludingLeaf(root , res);
	leafNodes(root , res);
	RightTreeExcludingLeaf(root , res);
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	vector<int>res;
	boundary(root, res);
	for(auto it: res) {
		cout << it << " ";
	}
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}