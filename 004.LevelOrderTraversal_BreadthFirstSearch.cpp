#include<iostream>
#include<queue>
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


// void LevelOrderTraversal(node* root) {

// 	// code help code
// 	queue<node*>q;

// 	q.push(root);
// 	q.push(NULL);
// 	while(!q.empty()) {
// 		node* temp = q.front();
// 		q.pop();
// 		if(temp == NULL) {
// 			cout << "\n";
// 			if(!q.empty()) q.push(NULL);
// 		}
// 		else {
// 		cout << temp -> data << " ";
// 		if(temp -> left) {
// 			q.push(temp -> left);
// 		}

// 		if(temp -> right) {
// 			q.push(temp -> right);
// 		}
// 	}
// 	}
// }

void LevelOrderTraversal(node* root) {

	// stiver code
	vector<vector<int>>ans;
	queue<node*>q;
	q.push(root);
	while(!q.empty()) {
		int size = q.size();
		vector<int>vec;
		for(int i = 0; i < size; i++) {
			node* temp = q.front();
			q.pop();
			if(temp -> left) 
				q.push(temp -> left);
			if(temp -> right)
				q.push(temp -> right);
			vec.push_back(temp -> data);
			cout << temp -> data << " ";
		}
		cout << "\n";
		ans.push_back(vec);
	}
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	// LevelOrderTraversal(root); // code help
	LevelOrderTraversal(root); // striver
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}