#include<iostream>
#include<queue>
#include<sstream>
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

string serialize(node* root) {
	queue<node*>q;
	q.push(root);
	string s = "";
	while(!q.empty()) {
		node* node = q.front();
		q.pop();
		if(node == NULL) s.append("#,");
		else {
			s.append(to_string(node -> data)+ ',');
		}
		if(node != NULL) {
			q.push(node -> left);
			q.push(node -> right);
		}
	}
	// cout << s << " ";
	return s;
}

void print(node*r) {
	if(r == NULL) return;
	cout << r -> data << " ";
	print(r -> left);
	print(r -> right);
}

node* deserialize(string str) {
	if(str.size() == 0) return NULL;
	stringstream ss(str);
	string sstring;
	getline(ss , sstring , ',');
	queue<node*>q;
	node* ro = new node(stoi(sstring));
	q.push(ro);
	while(!q.empty()) {
		node* n = q.front();
		q.pop();
		getline(ss , sstring , ',');
		if(sstring == "#") {
			n -> left = NULL;
		}
		else {
			node* leftnode = new node(stoi(sstring));
			n -> left = leftnode;
			q.push(leftnode);
		}
		getline(ss , sstring , ',');
		
		if(sstring == "#") {
			n -> right = NULL;
		}
		else {
			node* rightnode = new node(stoi(sstring));
			n -> right = rightnode;
			q.push(rightnode);
		}

	}
	cout << "printing tree ";
	print(ro);
	return ro;
}


int main() {
	node* root = NULL;
	root = buildTree(root);
	string str = serialize(root);
	node* r = deserialize(str);
	// print(r);
}