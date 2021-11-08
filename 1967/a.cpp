#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int n;
vector<pair<int,int> > v[10001];
int arr[10001][10001] = {0,};

void dfs(int a) {
	for(int i = 0;i<v[a].size();i++) {
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n;
	for(int i = 0;i<n;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	for(int i = 0;i<n;i++) {

	}
}