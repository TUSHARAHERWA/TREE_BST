#include<iostream>
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

node* kLargest(node* root, int &k) {
	if(root == NULL) return NULL;
	node* right = kLargest(root -> right , k);
	if(right != NULL) {
		return right;
	}
	k--;	
	if(k==0) {
		return root;
	}
	return kLargest(root -> left,k);
}

node* kSmallest(node* root , int &k) {
	if(root == NULL) return NULL;
	node* left = kSmallest(root -> left , k);
	if(left != NULL) {
		return left;
	}
	k--;
	if(k==0) 
	return root;
	return kSmallest(root -> right ,k);
}

void smallest(node* root , int &k , int &ans, int &cnt) {
	if(root == NULL || cnt == k) return ;
	smallest(root -> left, k, ans, cnt);
	cnt++;
	if(cnt == k) ans = root -> data;
	smallest(root -> right, k, ans, cnt);
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	int k = 2, ans = 0 , cnt = 0;
	smallest(root, k, ans, cnt);
	cout << ans << " ";

	// striver approach 
	// node* ans = kLargest(root, k);
	// node* ans = kSmallest(root , k);
	// cout << ans -> data << " ";

}
