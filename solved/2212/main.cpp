#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

 	int n,k;
	cin>>n>>k;
	vector<int> v(n),min(n-1);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}

	sort(v.begin(),v.end());
	for(int i = 0;i<n-1;i++) {
		min[i] = v[i+1]-v[i];
	}
	sort(min.begin(),min.end());

	int res = 0;
	for(int i = 0;i<n-k;i++) {
		res += min[i];
	}

	cout<<res<<'\n';

	return 0;
}