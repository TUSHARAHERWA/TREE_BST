#include<iostream>
#include<map>
#include<set>
#include<queue>
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
	cin>> ele;
	root = new node(ele);
	if(ele == -1) return NULL;

	root -> left = buildTree(root -> left);
	root -> right = buildTree(root -> right);
	return root;
}

void verticalOrderTraversal(node* root) {
	map<int,map<int,multiset<int>>>mp;
	queue<pair<node*,pair<int,int>>>q;

	// pushing staring node and 0 in queue
	q.push({root, {0,0}});

	while(!q.empty()) {
		auto new_a = q.front();
		q.pop();
		node* it = new_a.first;
		int x = new_a.second.first , y = new_a.second.second;
		mp[x][y].insert(it -> data);
		if(it -> left) {
			q.push({it -> left , {x-1 , y+1}});
		}
		if(it -> right) {
			q.push({it -> right , {x+1 , y+1}});
		}
	}
	vector<vector<int>>ans;
	for(auto p: mp)
	{
		vector<int>col;
		for(auto it: p.second) {
			col.insert(col.end(), it.second.begin() , it.second.end());
		}
		ans.push_back(col);
	}
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve() {
	node* root = NULL;
	root = buildTree(root);
	verticalOrderTraversal(root);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}