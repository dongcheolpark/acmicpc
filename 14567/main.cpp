#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<vector<int>> list;
vector<int> countList;
vector<int> visit;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n>>m;
	list.resize(n+1);
	countList.resize(n+1,0);
	visit.resize(n+1,0);

	for(int i =0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		list[a].push_back(b);
		countList[b]++;
	}
	for(int turn = 1;;turn++) {
		int chk = false;
		for (int i = 1; i <= n; i++)
		{
			if(visit[i] == 0 && countList[i] == 0) {
				chk = true;
				visit[i] = turn;
				for(auto item : list[i]) {
					countList[item]--;
				}
			}
		}
		if(chk == false) {
			break;
		}
	}
	for(int i = 0;i<n;i++) {
		cout<<visit[i]<<" ";
	}
	return 0;
}