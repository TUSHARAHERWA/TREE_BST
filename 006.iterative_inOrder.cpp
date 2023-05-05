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

void inorder(node* root) {
	stack<node*>s;
	node* temp = root;
	while(true) {
		if(temp != NULL) {
			s.push(temp);
			temp = temp -> left;
		}
		else {
			if(s.empty()) break;
			temp = s.top();
			s.pop();
			cout << temp -> data << " ";
			temp = temp -> right;
		}
	}
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	inorder(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}