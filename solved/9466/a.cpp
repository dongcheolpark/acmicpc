#include <iostream>
#include <string>
#include <vector>
using namespace std;



bool dfs(vector<int>& arr,vector<int> &visit, int i,int start) {
	if(visit[i] == 1) {
		if(i == start) return 1;
		else return 0;
	} 
	visit[i] = 1;
	if(dfs(arr,visit,arr[i],start)) return 1;
	if(arr[i] == i) return 0;
	visit[i] = 0;
	return 0;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin>>T;
	while(T--) {
		int n;
		vector<int> arr;
		vector<int> visit;
		cin>>n;
		arr.resize(n+1);
		visit.resize(n+1);
		for(int i = 1;i<=n;i++) {
			cin>>arr[i];
			visit[i] = false;
		}
		int res = 0;
		for(int i = 1;i<=n;i++) {
			if(!dfs(arr,visit,i,i)) res++;
		}
		cout<<res<<'\n';	
	}
}