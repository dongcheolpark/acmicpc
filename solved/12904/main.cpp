#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s,t;
	cin>>s>>t;
	auto left = t.begin(),right = t.end()-1;
	int n = t.length() - s.length();
	bool re = false;
	for(int i = 0;i<n;i++) {
		if(!re) {
			//안 뒤집혔으면
			if(*right == 'A') {
				right--;
			}
			else {
				right--;
				re = !re;
			}
		}
		else {
			//뒤집혔으면
			if(*left == 'A') {
				left++;
			}
			else {
				left++;
				re = !re;
			}
		}
	}

 if(re) {
		for(auto i = left,ci = s.end()-1;i<=right;i++,ci--) {
			if(*i != *ci) {
				cout<<0;
				return 0;
			}
		}
 }
 else {
		for(auto i = left,ci = s.begin();i<=right;i++,ci++) {
			if(*i != *ci) {
				cout<<0;
				return 0;
			}
		}
	}
	cout<<1;	
	return 0;
}