#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>> pqLeft;
priority_queue<int,vector<int>,greater<int>> pqRight;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;
	for(int i = 0;i<n;i++) {
		int tmp;
		cin>>tmp;
		if(pqLeft.size() == pqRight.size()) pqLeft.push(tmp);
		else pqRight.push(tmp);

		if(!pqLeft.empty() && !pqRight.empty()) {
			if(pqLeft.top() > pqRight.top()) {
				int max = pqRight.top();
				int min = pqLeft.top();
				pqRight.pop();
				pqLeft.pop();
				pqLeft.push(max);
				pqRight.push(min);
			}
		}
		cout<<pqLeft.top()<<'\n';
	}
	return 0;
}