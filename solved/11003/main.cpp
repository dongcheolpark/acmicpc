#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,l;
	cin>>n>>l;
	deque<pair<int,int>> dq;
	for(int i = 0;i<n;i++) {
		int tmp;
		cin>>tmp;
		while(!dq.empty()&&dq.front().first < i-l+1) dq.pop_front();
		while(!dq.empty()&&dq.back().second >= tmp) dq.pop_back();
		dq.push_back(make_pair(i,tmp));
		cout<<dq.front().second<<" ";
	}
	return 0;
}