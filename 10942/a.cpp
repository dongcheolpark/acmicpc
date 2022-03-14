#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int n,m;
int dp[2001][2001];
int arr[2001];

bool func(int st,int end) {
	if(dp[st][end] != -1) return dp[st][end];
	if(st >= end) return true;
	dp[st][end] = (arr[st] == arr[end]) ? func(st+1,end-1) : 0;
	return dp[st][end];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i = 0;i<n;i++) {
		memset(dp[i],-1,sizeof(int)*n);
	}
	for(int i = 0;i<n;i++) {
		cin>>arr[i];
	}
	cin>>m;
	for(int i = 0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		cout<<func(a-1,b-1)<<'\n';
	}
}