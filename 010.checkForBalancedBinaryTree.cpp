#include<iostream>
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

// int height(node* root) { //root = 7
// 	if(root == NULL) {
// 		return 0;
// 	}

// 	int lh = height(root -> left);
// 	int rh = height(root -> right);
// 	return 1 + max(lh , rh);
// }

// bool check(node* root) {

// 	if(root == NULL) {
// 		return true;
// 	}

// 	int left = height(root -> left);
// 	int right = height(root -> right);

// 	if(abs(left-right) > 1) {
// 		return false; 
// 	}
// 	bool l = check(root -> left);
// 	bool r = check(root -> right);
// 	if(!l || !r) {
// 		cout << l << " " << r << " ";
// 		return false;
// 	} 
// 	return true;
// }

int isBalanced(node* root) {

	if(root == NULL) return 0;
	int left = isBalanced(root -> left);
	if(left == -1) return -1;

	int right = isBalanced(root -> right);
	if(right == -1) return	-1;
	cout << left << " " << right << "\n";
	if(abs(right - left) > 1) return -1;
	return max(left ,right) + 1;
}



void solve() {
	node* root = NULL;
	root = buildTree(root);
	if(isBalanced(root) != -1) cout << "YES\n";
	else cout << "NO\n";

	// if(check(root) == true) 
	// 	cout << "YES" <<  " ";
	// else
	// 	cout << "NO";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}

// check -> time complexity -> O(N^2)
		 // space compleixty -> O(1) 
		 // Recursive Stack Space -> O(HEIGHT)