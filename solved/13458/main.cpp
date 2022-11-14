#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,b,c;
	long long ans = 0;	
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}
	cin>>b>>c;
	for(int i = 0;i<n;i++) {
		int tmp = v[i];
		ans++;
		tmp-=b;
		if(tmp <= 0) continue;
		ans+= (tmp/c) + (tmp%c > 0);
	}
	cout<<ans;

	return 0;
}