#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> v;
queue<int> q;

void func(int left,int right) {
	if(left > right) return;
	int pos = left;
	int val = q.front();q.pop();
	for(int i = left;i<=right;i++) {
		if(val == v[i]) {
			pos = i; break;
		}
	}
	func(left,pos-1);
	func(pos+1,right);
	cout<<val<<' ';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		v.clear();
		v.resize(n);
		for(int i = 0;i<n;i++) {
			int tmp;
			cin>>tmp;
			q.push(tmp);
		}
		for(int i = 0;i<n;i++) {
			cin>>v[i];
		}
		func(0,n-1);
		cout<<'\n';
	}
	return 0;
}