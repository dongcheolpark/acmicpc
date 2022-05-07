#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> pre(n);
	vector<vector<int > > next(n,vector<int>());
	for(int i = 0;i<m;i++) {
		string tmp;
		cin>>tmp;
		int _pre = -1;
		for(auto item : tmp) {
			if(item == ' ') continue;
			int a = item-'0';
			if(_pre != -1) {
				next[_pre].push_back(a);
				_pre = a;
			}
		}
	}
}