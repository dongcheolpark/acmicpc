#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--) {
		int n,k,w;
		cin>>n>>k;
		vector<int> cost;
		cost.resize(n+1);
		for(int i = 1;i<=n;i++) {
			cin>>cost[i];
		}
		vector<vector<int>> nodelists;
		vector<int> cnt,visit;
		nodelists.resize(n+1);
		cnt.resize(n+1);
		visit.resize(n+1);
		for(int i = 0;i<k;i++) {
			int a,b;
			cin>>a>>b;
			nodelists[a].push_back(b);
			cnt[b]++;
		}
		cin>>w;
		vector<int> result;
		result.resize(n+1);

		queue<int> q;
		for(int i = 1;i<=n;i++) {
			if(cnt[i] == 0) {
				q.push(i);
			}
		}

		while(cnt[w] > 0) {
			int u = q.front();
			q.pop();
			for(int next : nodelists[u]) {
				result[next] = max(result[next],result[u] + cost[u]);
				if(--cnt[next] == 0)q.push(next);
			}
		}

		cout<<result[w]+cost[w]<<'\n';
	}
}