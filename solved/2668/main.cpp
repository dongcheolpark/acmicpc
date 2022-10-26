#include <iostream>
#include <vector>

using namespace std;

vector<bool> vis;
vector<int> v,res;

void dfs(int s,int x) {
	if(vis[x]) {
		if(s == x) {
			res.push_back(s+1);
		}
	} 
	else {
		vis[x] = true;
		dfs(s,v[x]);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vis.resize(n);
	v.resize(n);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
		v[i]--;
	}
	for(int i = 0;i<n;i++) {
		vis.clear();
		vis.resize(n);
		dfs(i,i);
	}
	cout<<res.size()<<'\n';
	for(auto item : res) {
		cout<<item<<'\n';
	}
	return 0;
}