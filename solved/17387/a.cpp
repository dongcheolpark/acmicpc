#include <iostream>

using namespace std;

typedef long long ll;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}

int main() {
	pair<ll,ll> p1,p2,p3,p4;
	cin>>p1.first>>p1.second;
	cin>>p2.first>>p2.second;
	cin>>p3.first>>p3.second;
	cin>>p4.first>>p4.second;

	int ab = ccw(p1,p2,p3) * ccw(p1,p2,p4);
	int cd = ccw(p3,p4,p2) * ccw(p3,p4,p1);
	if(ab == 0 && cd == 0) {
		if(p1 > p2) {
			auto tmp = p1;
			p1 = p2;
			p2 = tmp;
		}
		if(p3 > p4) {
			auto tmp = p3;
			p3 = p4;
			p4 = tmp;
		}
		cout<<((p3<=p2)&&(p1<=p4));
	}
	else cout<<(ab <= 0&&cd <= 0);
}