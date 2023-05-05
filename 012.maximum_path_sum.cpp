#include<iostream>
#include<algorithm>
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

node* buildTree(node* root) {
	int ele;
	cin >> ele;
	root = new node(ele);
	if(ele == -1) {
		return NULL;
	}
	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

int height(node * root) {
	
	if(root == NULL) {

		return 0;
	}
	int lh = height(root -> left);
	int rh = height(root -> right);

	// cout << max({lh ,rh}) + root -> data <<" ";
	return max(0 , root -> data + max(lh , rh));

}


int maximumPath(node* root, int &maxi) {
	if(root == NULL) return 0; 	

	int left = max(0 ,maximumPath(root -> left, maxi));
	int right = max(0,maximumPath(root -> right , maxi));
	// cout << left << " " << right <<" "<< root -> data <<"\n";
	maxi = max(maxi , left + right + root -> data);
	// cout << m axi <<  " ";
	return max(left , right) + root -> data;
	// int l = maximumPath(root -> left);
	// int r = maximumPath(root -> right);
	return maxi;
}

int maxim(node* root , int &maxi) {
	if(root == NULL) return 0;

	int left = max(0 , maxim(root -> left , maxi));
	int right = max(0 , maxim(root -> right , maxi));
	maxi = max(maxi , left + right + root -> data);
	return max(left , right) + root -> data;
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	int maxi = INT_MIN;
	 maximumPath(root , maxi);// tc -> o(N^2)
	cout << maxi << "\n";
	 maxi = INT_MIN;
	maxim(root , maxi);
	cout << maxi << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}