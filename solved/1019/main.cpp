#include <iostream>
#include <vector>

using namespace std;
vector<long long> ans(10);

void calc(long long x,long long point) {
	while(x > 0) {
		ans[x%10] += point;
		x/=10;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int s = 1,e,point = 1;
	cin>>e;
	while(s <= e) {
		while(s%10 != 0 && s<=e) {
			calc(s,point);
			s++;
		}
		if(s>e) break;
		while(e%10 != 9 && s<=e) {
			calc(e,point);
			e--;
		}
		long long cnt = e/10 - s/10 + 1;
		for(int i = 0;i<10;i++) {
			ans[i] += cnt * point;
		}
		point *= 10;
		s/=10;
		e/=10;
	}
	for(int i = 0;i<10;i++) {
		cout<<ans[i]<<' ';
	}
	return 0;
}