#include <cmath>
#include <iostream>
#include <vector>

#define CATCH_CONFIG_MAIN

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int n;
	cin>>n;
	int p1 = 0;
	for(int i = 0;i<n;i++) {
		int tmp = 0;
		cin>>tmp;
		v.push_back(tmp);
	}
	int left = 0,right = n-1;
	int res = abs(v[left] + v[right]);
	int resA = v[left];
	int resB = v[right];
	while(left < right) {
		int tmp =v[left] + v[right];
		if(abs(tmp) < res) {
			res = abs(tmp);
			resA = v[left];
			resB = v[right];
		}
		if(tmp < 0) {
			left++;
		}
		else right--;
	}
	cout<<resA<<' '<<resB;
}