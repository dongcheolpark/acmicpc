#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int arr[101],v[101];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<101;i++) {
		arr[i] = i;
		v[i] = -1;
	}
	for(int i = 0;i<n+m;i++) {
		int a,b;
		cin>>a>>b;
		arr[a] = b;
	}
	//bfs
	queue<int> q;
	q.push(1);
	v[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y > 100) continue;
			y = arr[y]; 
			if (v[y] == -1) { 
				v[y] = v[x] + 1;
				q.push(y);
			}
		}
	}
	cout<<v[100]<<'\n';
	return 0;
}

