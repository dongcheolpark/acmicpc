#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,q;
vector<vector<pair<int,int>>> v;
vector<bool> vis;

int bfs(int k,int s) {
	queue<pair<int,int>> q;
	vis[s] = true;
	q.push(make_pair((1<<31)-1,s));
	int ans = 0;
	while(!q.empty()) {
		auto x = q.front();
		q.pop();
		for(auto item : v[x.second]) {

			if(vis[item.first]) continue;
			int minival = min(x.first,item.second);

			if(k<= minival) {
				ans++;
				vis[item.first] = true;
				q.push(make_pair(minival,item.first));
			}
		}
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n>>q;
	v.resize(n);
	vis.resize(n);

	for(int i = 0;i<n-1;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		a-= 1;
		b-= 1;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}

	for(int i = 0;i<q;i++) {
		fill(vis.begin(),vis.end(),false);	
		int a,b;
		cin>>a>>b;
		cout<<bfs(a,b-1)<<'\n';
	}
	return 0;
}