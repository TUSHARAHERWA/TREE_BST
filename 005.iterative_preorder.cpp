#include<iostream>
#include<stack>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int ele) {
		this -> data = ele;
		this -> left = NULL;
		this -> right = NULL;
	}
};

node* buildTree(node* root) {
	int element;
	cin >> element;
	root = new node(element);
	if(element == -1) return NULL;

	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

void iterativePreorder(node* root) {
	stack<node*>s;
	s.push(root);

	while(!s.empty()) {
		root = s.top();
		s.pop();
		cout << root -> data << " ";
		if(root -> right) {
			s.push(root -> right);
		}
		if(root -> left) {
			s.push(root -> left);
		}
	}

}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	iterativePreorder(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}