#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v,dist;
int n,res = (1<<31)-1;

void func(int visit,int x,int sum) {
	visit |= (1<<x);
	if(visit == (1<<n)-1) {
		res = min(res,sum);
	}
	else {
		for(int i = 0;i<n;i++) {
			if(!(visit & (1<<i))) {
				func(visit,i,sum + v[x][i]);
			}
		}	
	}
	visit ^= (1<<x);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int s;
	cin>>n>>s;
	v.resize(n);
	for(int i =0;i<n;i++) {
		v[i].resize(n);
	}

	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin>>v[i][j];
		}
	}
	for(int k = 0;k<n;k++) {
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++) {
				v[i][j] = min(v[i][j],v[i][k] + v[k][j]);
			}
		}
	}
	func(0,s,0);
	cout<<res;
	return 0;
}