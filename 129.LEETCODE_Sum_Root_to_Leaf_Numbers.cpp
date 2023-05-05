#include<iostream>
#include<vector>
#include<string>
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

node* buildTrees(node* &root) {
	int e;
	cin >> e;
	root = new node(e);
	if(e == -1) {
		return NULL;
	}
	root -> left = buildTrees(root -> left);
	root -> right = buildTrees(root -> right);
	return root;
}

// void sumRoot(node* root , vector<int>&v , vector<vector<int>>&v2) {
// 	if(root == NULL) return;

// 	v.push_back(root -> data);
// 	if(root -> left == NULL && root -> right == NULL) {
// 		v2.push_back(v);
// 		return;
// 	}
// 	sumRoot(root -> left , v , v2);
// 	v.pop_back();
// 	sumRoot(root -> right , v , v2);
// 	v.pop_back();

// }

void Sumr(node* root , int &total , int sum) {
	 if(root == NULL) return;
       
        sum = sum * 10 + root -> data; 
        // cout << sum << " ";
        if(root -> left == NULL && root -> right == NULL) {
            total += sum;
            // cout << total << " ";
            return ;
        }
        Sumr(root -> left ,total , sum);
        // cout << sum << " ";
        // sum = sum / 10;
        Sumr(root -> right,total, sum);
        // sum = sum / 10;       
}

void solve() {
	node* root = NULL;
	root = buildTrees(root);
	int total = 0, sum = 0;
	Sumr(root , total , sum);
	cout << total << " ";



	// vector<int>v;
	// vector<vector<int>>v2;

	// sumRoot(root , v,  v2);

	// string s;
	// int answer = 0;
	// // cout << s ;
	// int ans = 0;
	// for(int i = 0; i < v2.size(); i++) {
	// 	for(int j = 0; j < v2[i].size(); j++) {
	// 		ans = v2[i][j];
	// 		s += to_string(ans);
	// 	}
	// 	answer += stoi(s);
	// }
	// cout << answer << " ";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}