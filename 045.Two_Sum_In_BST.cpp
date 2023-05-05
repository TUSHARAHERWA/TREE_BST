#include<iostream>
#include<vector>
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
	stack<node*>st;
	bool reverse = true;
public:
	BSTiterator(node* root, bool isReverse) {
		reverse = isReverse;
		pushAll(root);
	}

	bool hasNext() {
		return !st.empty();
	}

	int next() {
		node* temp = st.top();
		st.pop(); 
		if(reverse == false) {
			pushAll(temp -> right);
		}
		else pushAll(temp -> left);
		return temp -> data;
	}
private:
	pushAll(node* root) {
		for(;root!= NULL;) {
			st.push(root);
			if(reverse == true) {
				root = root -> right;
			}
			else {
				root = root -> left;
			}
		}
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

void storeInVector(node* root, vector<int> &inorder) {
	if(root == NULL) return;
	storeInVector(root -> left, inorder);
	inorder.push_back(root -> data);
	storeInVector(root -> right, inorder);
}

bool findTarget(node* root, int &k) {
	if(!root) return false;
	BSTiterator l(root, false); // if next is called move 1 step right push all the left nodes
	BSTiterator r(root, true); // if next is called move 1 step left push all the right nodes
	int i = l.next();
	int j = r.next();
	// cout << i << " " << j;
	while(i < j) {
		if(i + j == k) return true;
		else if(i + j < k) i = l.next();
		else j = r.next();
	}
	return false;
}

int main() {
	node* root = NULL;
	root = buildTree(root);
	vector<int>inorder;
	storeInVector(root , inorder);

	// brute force using two pointer
	// int i = 0, j = inorder.size() - 1, target = 6;

	// while(i < j) {
	// 	if(inorder[i] + inorder[j] == target) {
	// 		cout << "YES\n";
	// 		break;
	// 	}
	// 	else if(inorder[i] + inorder[j] > target) {
	// 		j--;
	// 	}
	// 	else {
	// 		i++;
	// 	}
	// }

	// optimized using iterator
    int k = 3;
	bool ans = findTarget(root, k);
	cout << ans << " ";
	
}