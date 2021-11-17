#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;
int main() {
	char * str;
	cin>>str;
	for(int i = 0;str[i];i++) {
		cout<<str[i];
		if(i%10 == 0) cout<<'\n';
	}
	return 0;
}