#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int left,int right,char op) {
	switch (op)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	string str;
	cin>>n;
	cin>>str;
	m = n/2+1;
	vector<vector<int>> dp(m),min_dp(m);
	for(int i = 0;i<m;i++) {
		dp[i].resize(m,-((1<<31)-1));
		min_dp[i].resize(m,(1<<31)-1);
	}
	for(int i = 0;i<n;i+=2) {
		dp[i/2][i/2] = min_dp[i/2][i/2] = str[i]-'0';
	}

	for(int interval = 1;interval<m;interval++) {
		for(int i = 0;i<m-interval;i++) {
			int s = i;
			int e = i+interval;
			for(int j = s;j<e;j++) {
				int val = 0;
				char op = str[j*2+1];
				vector<int> tmp(4);
				tmp[0] = func(dp[s][j],dp[j+1][e],op);
				tmp[1] = func(dp[s][j],min_dp[j+1][e],op);
				tmp[2] = func(min_dp[s][j],dp[j+1][e],op);
				tmp[3] = func(min_dp[s][j],min_dp[j+1][e],op);
				sort(tmp.begin(),tmp.end());
				dp[s][e] = max(dp[s][e],tmp[3]);
				min_dp[s][e] = min(min_dp[s][e],tmp[0]);
			}
		}
	}

	cout<<dp[0][m-1];
	return 0;
}