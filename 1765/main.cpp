#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int n,m;
	cin>>n>>m;
	vector<vector<pair<char,int>>> v(n);
	vector<bool> visit(n);
	for(int i = 0;i<m;i++) {
		char ch;
		int tmp1,tmp2;	
		cin>>ch>>tmp1>>tmp2;
		v[tmp1-1].push_back(make_pair(ch,tmp2-1));
		v[tmp2-1].push_back(make_pair(ch,tmp1-1));
	}
	int res = 0;

	for(int i = 0;i<n;i++) {
		if(!visit[i]) res++;
		visit[i] = true;
		for(int j = 0; j<v[i].size();j++) {
			if(v[i][j].first == 'F') visit[v[i][j].second] = true;
			else {
				auto& enemyV = v[v[i][j].second];
				for(int k = 0;k<enemyV.size();k++) {
					if(enemyV[k].second == i) continue;
					if(enemyV[k].first == 'E'){
						visit[enemyV[k].second] = true;
					}
				}
			}
		}
	}

	cout<<res;
	return 0;
}