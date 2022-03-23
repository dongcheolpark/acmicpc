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
		int n,k;
		cin>>n>>k;
		vector<int> cost;
		cost.resize(n+1);
		for(int i = 0;i<k;i++) {
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

		while(1) {
			for(int i = 1;i<=n;i++) {
				if(visit[i] == 0&&cnt[i]==0) {

				}
			}
		}
	}
}