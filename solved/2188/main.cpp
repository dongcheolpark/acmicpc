#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<vector<int>> v;	
vector<int> A,B;
vector<bool> vis;

bool func(int x) {
	vis[x] = true;
	for(int b : v[x]) {
		if(B[b] == -1 || !vis[B[b]] && func(B[b])) {
			B[b] = x;
			A[x] = b;
			return true;
		}
	}
	return false;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>m;
	A.resize(n,-1);
	B.resize(m,-1);
	v.resize(n);
	vis.resize(n,false);

	for(int i = 0;i<n;i++) {
		int k,tmp;
		cin>>k;
		for(int j = 0;j<k;j++) {
			cin>>tmp;
			v[i].push_back(tmp-1);
		}
	}
	int res = 0;

	for(int i = 0;i<n;i++) {
		if(A[i] == -1) {
			fill(vis.begin(),vis.end(),false);
			if(func(i)) res++;
		}
	}
	cout<<res<<'\n';

	return 0;
}