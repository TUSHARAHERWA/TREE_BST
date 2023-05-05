#include<iostream>
#include<algorithm>
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
	// base case 
	if(ele == -1) return NULL;
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

int height(node* root){

	if(root == NULL) {
		return 0;
	}
	int LH = height(root -> left);
	int RH = height(root -> right);
	return max(LH , RH) + 1;
}


// int diameterOfTree(node* root , int &maxi) {
// 	if(root == NULL) {
// 		return 0;
// 	}

// 	int leftHeight = height(root -> left);
// 	int rightHeight = height(root -> right);
// 	maxi = max(maxi , leftHeight+rightHeight);

// 	int left = diameterOfTree(root -> left , maxi);
// 	int right = diameterOfTree(root -> right, maxi);

// 	return maxi;
// }

int diameterOfTree(node* root , int &maxi) {

	if(root == NULL) {
		return 0;
	}

	int lh =  diameterOfTree(root -> left , maxi);
	int rh =  diameterOfTree(root -> right , maxi);
	maxi = max(maxi , lh + rh);
	return max(lh , rh) + 1;
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	int maxi = 0;
	// diameterOfTree(root, maxi); // time complexity --> O(N^2)
	// cout << maxi << "\n";
	diameterOfTree(root , maxi); // time complexity --> O(N)
	cout << maxi << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}