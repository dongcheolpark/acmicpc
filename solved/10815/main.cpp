#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,T;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}
	cin>>T;
	sort(v.begin(),v.end());
	while(T--) {
		int tmp;
		cin>>tmp;
		cout<<binary_search(v.begin(),v.end(),tmp)<<' ';
	}
	return 0;
}