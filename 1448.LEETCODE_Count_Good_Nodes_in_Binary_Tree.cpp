#include<iostream>
#include<limits.h>
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

node* buildTree(node * root) {
	int element;
	cin >> element;
	root = new node(element);

	if(element == -1) 
		return NULL;

	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

void countNode(node* root, int &maxi, int &cnt) {
	if(root == NULL) return;
	if(root -> data >= maxi) {
		maxi = root -> data;
		cnt++;
    }
	countNode(root -> left, maxi, cnt);
	countNode(root -> right, maxi, cnt);
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	int maxi = INT_MIN;
	int cnt = 0;
	countNode(root, maxi , cnt);
	cout << cnt << " ";
}