#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		vector<int> sum(n);
		vector<vector<int>> dp(n);
		for(int i = 0;i<n;i++) {
			dp[i].resize(n);
		}
		for(int i = 0;i<n;i++) {
			int tmp;
			cin>>tmp;
			if(i == 0) sum[i] = tmp;
			else sum[i] = sum[i-1] + tmp;
		}
		for(int i = 1;i<=n;i++) {
			for(int j = 0;j<n-i;j++) {
				dp[j][i+j] = (1<<31)-1;
				for(int k = j;k<i+j;k++) {
					dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
				}
			}
		}
		cout<<dp[0][n-1]<<'\n';
	}
	

	return 0;
}