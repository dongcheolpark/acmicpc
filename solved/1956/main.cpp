#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int v,e;
	cin>>v>>e;

	vector<vector<int>> dist(v);

	int INF = 987654321;
	for(int i = 0;i<v;i++) {
		dist[i].resize(v,INF);
	}

	for(int i = 0;i<e;i++) {
		int s,e,val;
		cin>>s>>e>>val;
		dist[s-1][e-1] = val;
	}

	for(int k = 0;k<v;k++) {
		for(int i = 0;i<v;i++) {
			for(int j = 0;j<v;j++) {
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = INF;

	for(int i = 0;i<v;i++) {
		ans = min(ans,dist[i][i]);
	}

	cout<<(ans != INF ? ans : -1);

	return 0;
}