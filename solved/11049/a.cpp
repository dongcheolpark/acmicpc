#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	pair<int,int> arr[502];
	int dp[502][502];		
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>arr[i].first>>arr[i].second;
	}
	for(int i = 1;i<=n;i++) {
		dp[i][i+1] = arr[i].first * arr[i].second * arr[i+1].second;
	}
	for(int m = 2;m<=n;m++) {
		for(int i = 1;i<=n-m;i++) {
			int j = i+m;
			for(int k = i;k<j;k++) {
				int res = dp[i][k] + dp[k+1][j] + (arr[i].first * arr[k].second * arr[j].second);
				if(!dp[i][j] || res < dp[i][j]) dp[i][j] = res;
			}
		}
	}
	cout<<dp[1][n];
}