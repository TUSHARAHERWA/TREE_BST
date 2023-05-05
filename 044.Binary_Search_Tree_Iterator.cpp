#include<iostream>
#include<stack>
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

class BSTiterator {
private:
	stack<node*>myStack;
public:
	BSTiterator(node* root) {
		pushAll(root);
	}

	bool hasNext() {
		return !myStack.empty();
	}

	int next() {
		node* tempnode = myStack.top();
		myStack.pop();
		pushAll(tempnode -> right);
		return tempnode -> data;
	}
private:
	void pushAll(node* ro) {
		for(; ro != NULL; myStack.push(ro), ro = ro -> left);
	}
};

void print(node* root) {
	if(root == NULL) return;
	print(root -> left);
	cout << root -> data << " ";
	print(root -> right);
}

node* buildTree(node* root) {
	int ele;
	cin >> ele;
	root = new node(ele);
	if(ele == -1) return NULL;
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	BSTiterator b(root);
	// b.pushAll(root);
	cout << b.next() << " ";
	cout << b.next() << " ";
	// cout << b.next() << " ";
	// cout << b.next() << " ";
	// cout << b.next() << " ";
	// cout << b.next() << " ";
	// cout << b.next() << " ";
	// cout << b.next() << " ";
	// cout << b.next() << " ";
	cout << b.hasNext();
}
