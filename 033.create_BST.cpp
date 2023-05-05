#include<iostream>
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

void LevelOrderTraversal(node* root) {
	queue<node*>q;

	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* temp = q.front();
		q.pop();
		if(temp == NULL) {
			cout << "\n";
			if(!q.empty()) q.push(NULL);
		}
		else {
		cout << temp -> data << " ";
		if(temp -> left) {
			q.push(temp -> left);
		}

		if(temp -> right) {
			q.push(temp -> right);
		}
	}
	}
} 



node* insertBST(node* &root , int da) {
	if(root == NULL) {
		root = new node(da);
		return root;
	}
	if(da > root -> data) {
		root -> right = insertBST(root -> right , da);
		
	}
	else {
		root -> left = insertBST(root->left, da);
      
	}
	return root;
}

void takeInput(node* &root) {
	int d;
	cin >> d;
	while(d != -1) {
		root = insertBST(root , d);
		cin >> d;
	}
}


void solve() {
	node* root = NULL;

	takeInput(root);
	LevelOrderTraversal(root);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}