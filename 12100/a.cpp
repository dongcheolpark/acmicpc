#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n;

void func(int cnt,pair<int,int> dir,vector<vector<int>> v) {
	if(cnt == 5) {

	}
	vector<vector<int>> tmp(v);
	if(cnt != 0) {
		for(int i = 0;i<n-1;i++) {
			for(int j = 0;j<n;j++) {
			}
		}

	}
	func(cnt++,make_pair(1,1),tmp);
	func(cnt++,make_pair(1,0),tmp);
	func(cnt++,make_pair(0,1),tmp);
	func(cnt++,make_pair(0,0),tmp);

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n;
	vector<vector<int>> v;
	v.resize(n);
	for(int i = 0;i<n;i++) {
		v[i].resize(n);
	}
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin>>v[i][j];
		}
	}

	func(0,make_pair(0,0),v);

}