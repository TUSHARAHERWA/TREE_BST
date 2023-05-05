#include<iostream>
#include<vector>
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
	if(ele == -1) return NULL;
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

node* findRight(node* root) {
	if(root -> right == NULL) {
		return root;
	}
	return findRight(root -> right);
}

node* helper(node* root) {
	if(root -> left == NULL) {
		node* temp = root -> right;
		delete(root);
		return temp;
	}
	else if(root -> right == NULL) {
		node* temp2 = root -> left;
		delete(root);
		return temp2;
	}
	node* rightChild = root -> right;
	node* lastRight = findRight(root -> left);
	lastRight -> right = rightChild;
	node* r = root -> left;
	delete(root);
	return r;	
}

node* deleteBST(node* root , int key) {
	if(root == NULL) return NULL;
	if(root -> data == key) {
		return helper(root);
	}
	node* temp = root;
	while(root != NULL) {
		if(root -> data > key) {
			if(root -> left != NULL && root -> left -> data == key) {
				root -> left = helper(root -> left);
				break;
			}
			else {
				root = root -> left;
			}
		}
		else {
			if(root -> right != NULL && root -> right -> data == key) {
				root -> right = helper(root -> right);
				break;
			}
			else {
				root = root -> right;
			}
		}
	}
	return temp;
}

void prinT(node* root) {
	queue<node*>q;
	q.push(root);
	while(!q.empty()) {
		int size = q.size();
		vector<int>vec;
		for(int i = 0; i < size; i++) {
			node* temp = q.front();
			q.pop();
			if(temp -> left) {
				q.push(temp -> left);
			}
			if(temp -> right) {
				q.push(temp -> right);
			}
			vec.push_back(temp -> data);
		}
		for(int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << "\n";
	}
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	prinT(root);
	cout << "\n\n";
	node* root2 = deleteBST(root , 1);
	prinT(root2);
}
