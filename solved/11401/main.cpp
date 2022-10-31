#include <iostream>

using namespace std;

#define mod 1000000007

long long a = 1,b=1,half;
long long solve(int x)
{
	if (x == 0) return 1;

	if (x % 2 == 1) return b * solve(x - 1) % mod;
	else
	{
		half = solve(x / 2);
		return half * half % mod;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;
	for(int i = n;i>=n-k+1;i--) a=(a*i) % mod;

	for(int i = 1;i<=k;i++) b =(b*i) % mod;

	b = solve(mod-2);

	cout<<(a*b) % mod;
	return 0;
}