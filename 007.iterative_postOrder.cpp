#include<iostream>
#include<stack>
#include<vector>
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

void usingTwoStack(node* root) {
	stack<node*>s;
	stack<node*>s2;

	s.push(root);

	while(!s.empty()) {
		node* temp = s.top();
		s2.push(s.top());
		s.pop();
		if(temp -> left) {
			s.push(temp -> left);
		}
		if(temp -> right) {
			s.push(temp -> right);
		}
	}
	while(!s2.empty()) {
		cout << s2.top() -> data << " ";
		s2.pop();
	}
}


void usingOneStack(node* root) {
	stack<node*>st;
	vector<int>vec;
	// st.push(root);
	node* curr = root;
	node* temp;
	while(!st.empty() || curr != NULL) {
		if(curr != NULL) {
			st.push(curr);
			curr = curr -> left;
		}
		else {
			temp = st.top() -> right;
			if(temp == NULL) {
				temp = st.top();
				st.pop();
				vec.push_back(temp -> data);
				while(!st.empty() && temp == st.top() -> right) {
					temp = st.top() , st.pop();
					vec.push_back(temp -> data);
				}
			}
			else {
				curr = temp; 
			}
		}
	}
	// cout << vec.size();
	for(auto it: vec) {
		cout << it << " ";
	}
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	// usingTwoStack(root);
	usingOneStack(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve(); // using two stack and one stack
}