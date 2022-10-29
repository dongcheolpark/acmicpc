#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,k;//k는 안쓰지 않나?
	cin>>n>>k;
	vector<vector<int>> dp(n);
	vector<int> v(n);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
		dp[i].resize(n);
	}

	for(int inter = 1;inter<n;inter++) {
		for(int i = 0;i<n-inter;i++) {
			int s = i;
			int e = i+inter;	
			int tmp = (1<<31)-1;
			for(int j = s;j<e;j++) {
				tmp = min(tmp,dp[s][j] + dp[j+1][e] + (v[s] != v[e]));
			}
			dp[s][e] = tmp;
		}
	}
	cout<<dp[0][n-1];
	return 0;
}