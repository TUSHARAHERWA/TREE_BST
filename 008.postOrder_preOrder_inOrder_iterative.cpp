#include<iostream>
#include<stack>
#include<bits/stdc++.h>
#include<vector>
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

void postPreInorder(node* root) {
	vector<int>pre1 , post2 , in3;
	stack<pair<node* , int >>s;
	s.push({root , 1});
	while(!s.empty()) {
		auto temp = s.top();
		s.pop();

		if(temp.second == 1) {
			pre1.push_back(temp.first -> data);
			temp.second++;
			s.push(temp);

			if(temp.first -> left) {
				s.push({temp.first -> left , 1});
			}
		}

		else if(temp.second == 2) {
			in3.push_back(temp.first -> data);
			temp.second++;
			s.push(temp);

			if(temp.first -> right) {
				s.push({temp.first -> right , 1});
			}
		}

		else if(temp.second == 3) {
			post2.push_back(temp.first -> data);

		}
	}
	cout << "postorder -->  ";
	for(auto it: post2) {
		cout << it << " ";
	}
	cout << "\n";

	cout << "inorder -->    ";
	for(auto it: in3) {
		cout << it << " ";
	}
	cout << "\n";

	cout << "preorder -->   ";
	for(auto it: pre1) {
		cout << it << " ";
	}
	cout << "\n";
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	postPreInorder(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}