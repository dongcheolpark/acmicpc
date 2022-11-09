#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin>>T;
	stack<int> st;
	while(T--) {
		string str;
		cin>>str;
		if(str.compare("push") == 0) {
			int tmp;
			cin>>tmp;
			st.push(tmp);
		}
		else if(str.compare("pop") == 0) {
			if(!st.empty()) {
				cout<<st.top()<<'\n';
				st.pop();
			}
			else cout<<-1<<'\n';
		}
		else if(str.compare("size") == 0) {
			cout<<st.size()<<'\n';
		}
		else if(str.compare("empty") == 0) {
			cout<<st.empty()<<'\n';
		}
		else if(str.compare("top") == 0) {
			if(!st.empty()) {
				cout<<st.top()<<'\n';
			}
			else cout<<-1<<'\n';
		}
	}
	return 0;
}