#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<vector<int>> linknodes;
	vector<int> count,visit;

	int n,m;
	cin>>n>>m;
	linknodes.resize(n+1);
	count.resize(n+1);
	visit.resize(n+1);
	for(int i = 0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		linknodes[a].push_back(b);
		count[b]++;
	}
	queue<int> q;
	while(1) {
		int chk = true;
		for(int i = 1;i<=n;i++) {
			if(count[i] == 0&&visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
				chk = false;
				for(auto item : linknodes[i]) {
					count[item]--;
				}
			}
		}
		if(chk) break;;
		while(!q.empty()) {
			cout<<q.front()<<' ';
			q.pop();
		}
	}
}