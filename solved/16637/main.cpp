#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,max = 0;
	string input;
	cin>>n;
	cin>>input;
	
	int size = pow(2,(n+1)/2);
	for(int i = 0;i<size;i++) {
		stack<char> st;
		int cnt = 0;
		int prev = 1;
		for(int x = i;x>0;x/=2) {
			if(x%2) {
				if(prev != 1 && cnt % 2) {
					cnt = 1;break;
				}
				cnt++;
				prev = 1;
			}
			else prev = 0;
		}			
		if(cnt % 2) continue;
		string res = "";
		bool chk = 0;
		for(int j = 0,x = i;j<n;j++) {
			if('0' <= input[j] && input[j] <= '9') {
				res.push_back(input[j]);
				int tmp = i;
				for(int k = 0;k<j/2;k++,tmp/=2); 
				if(tmp%2) {
					if(chk == 0) {
						st.push('(');
					}	
					else {
						for(char top = st.top();top != '(';top = st.top()) {
							res.push_back(top);
							st.pop();
							if(st.empty()) break;
						}
						if(st.top() == '(') st.pop();
					}
					chk = chk ? 0 : 1;
				}
			} 
			else {
				if(st.empty()) st.push(input[j]);
				else {
					if(input[j] != '*') {
						for(char top = st.top();top == '*';top = st.top()) {
							res.push_back(top);
							st.pop();
							if(st.empty()) break;
						}
					}
					st.push(input[j]);
				}
			}
		}
		for(char top = st.top();!st.empty();top = st.top()) {
			if(top != '(') {
				res.push_back(top);
			}
			st.pop();
			if(st.empty()) break;
		}
		cout<<res<<'\n';
		stack<int> resSt;
		for(int j = 0;j<n;j++) {
			if('0' <= res[j] && res[j] <= '9') {
				resSt.push(res[j] - '0');
			}
			else {
				int b = resSt.top();	
				resSt.pop();
				int a = resSt.top();
				resSt.pop();
				int ans = 0;
				if(res[j] == '*') {
					ans = a*b;
				}
				else if (res[j] == '+') {
					ans = a+b;
				}
				else if (res[j] == '-') {
					ans = a-b;
				}
				resSt.push(ans);
			}
		}
		int ans = resSt.top();
		cout<<ans<<'\n';
		if(max < ans) max = ans;
	}
	cout<<max;
	return 0;
}