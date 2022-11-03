#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo(1500050);

void func() {
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i = 2;i<1500000;i++) {
		fibo[i] = (fibo[i-1] + fibo[i-2]) % 1000000;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n;
	func();
	cin>>n;
	cout<<fibo[n%1500000];
	return 0;
}