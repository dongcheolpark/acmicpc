#include <iostream>
#include <vector>

#define MAX(X,Y) (X) > (Y) ? (X) : (Y)

using namespace std;

vector<int> value,cost;
vector<vector<int> > dp;

int main() {
	int n,m;
	cin>>n>>m;
	int max = 0;
	dp.resize(n);
	for(int i = 0;i<n;i++) {
		int a;
		cin>>a;
		value.push_back(a);
	}	
	for(int i = 0;i<n;i++) {
		int a;
		cin>>a;
		max += a;
		cost.push_back(a);
	}
	for(int i = 0;i<n;i++) {
		dp[i].resize(max);
	}
	for(int j = 0;j<=max;j++) {
			if(j - cost[0] >= 0) {
				dp[0][j] = value[0];
			}
	}

	for(int i = 1;i<n;i++) {
		for(int j = 0;j<=max;j++) {
			if(j - cost[i] >= 0) {
				dp[i][j] = MAX(dp[i][j],dp[i-1][j-cost[i]] + value[i]);
			}
			dp[i][j] = MAX(dp[i][j],dp[i-1][j]);
		}
	}
	for (int i = 0; i <= max; i++)
	{
		if (dp[n-1][i] >= m)
		{
			cout << i << endl;
			break;
		}	
	}

	
}