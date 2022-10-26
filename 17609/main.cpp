#include <iostream>
#include <vector>
#include <string>

using namespace std;

int func(string& str,int left,int right,bool del) {
	for(int i = left,j = right; i<j;i++,j--) {
		if(str[i] != str[j]) {
			if(del) {
				if(func(str,i+1,j,false) == 0 || func(str,i,j-1,false) == 0) return 1;
				return 2;
			}
			return 2;
		}
	}
	return 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin>>T;
	while(T--) {
		string str;
		cin>>str;
		int cnt = 1;
		cout<<func(str,0,str.length()-1,true)<<'\n';
	}
	return 0;
}