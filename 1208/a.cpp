#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> v;
map<int,int> mp;

int half,n,s;
long long ans = 0;

void funcleft(int st,int sum) {
	if(st == half) {
		mp[sum]++;
		return;
	}
	funcleft(st+1,sum + v[st]);
	funcleft(st+1,sum);
}

void funcright(int mid,int sum) {
	if(mid == n) {
		ans += mp[s-sum];
		return;
	}
	funcright(mid+1,sum+v[mid]);
	funcright(mid+1,sum);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>s;
	v.resize(n);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}
	half = n/2;
	funcleft(0,0);
	funcright(half,0);
	if(s==0) ans--;
	cout<<ans;
}