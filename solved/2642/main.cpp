#include <iostream>
#include <vector>
#include <utility>

#define N 6

using namespace std;
vector<vector<int>> v(N);
vector<int> vis(N+1);

vector<pair<int,int>> dirl = {{-1,0},{0,-1},{1,0},{0,1}};
int dfs(int x,int y,int cnt,int dir) {
	if(x<0||y<0||x>=N||y>=N||v[x][y] == 0) return 0;
	if(dir == -1) {
		vis[v[x][y]] = 1;
		for(int i = 0;i<4;i++) {
			int a = dirl[i].first,b = dirl[i].second;
			int tmp = dfs(x + a,y + b,1,i);
			if(tmp != 0) return tmp;
		}	
	}
	else {
		if(cnt == 0) {
			if(vis[v[x][y]] == 0) {
				vis[v[x][y]] = 1;
				return v[x][y];
			} 
			return 0;
		}
		else {
			int a = dirl[dir].first,b = dirl[dir].second;
			return dfs(x+a,y+b,0,dir);
		} 
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for(int i = 0;i<N;i++) {
		v[i].resize(N);
	}

	int chk = 0;
	vector<pair<int,int>> point(7);
	for(int i = 0;i<N;i++) {
		for(int j = 0;j<N;j++) {
			cin>>v[i][j];
			if(v[i][j] != 0) {
				chk |= 1<<(v[i][j]-1);
				point[v[i][j]] = make_pair(i,j);
			} 
		}
	}
	if(chk != ((1<<6) - 1)) {
		cout<<0;
		return 0;
	}
	int res = 0;
	for(int i = 1;i<=N;i++) {
		int x = point[i].first;
		int y = point[i].second;
		int tmp = dfs(x,y,2,-1);	
		if(tmp == 0) {
			cout<<0;
			return 0;
		}
		if(i == 1) res = tmp;
	}
	cout<<res;
	return 0;
}