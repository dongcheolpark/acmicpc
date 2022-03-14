#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int main() {
	int n;
	cin>>n;
	queue<pair<int,int>> q;
	q.push(n,0);
	while(q.size()) {
		pair<int,int> tmp = q.top();
		q.pop();
		if(tmp == 1) {
			cout<<tmp.second;
			break;
		}
		else if(tmp.first % 3 == 0 && (tmp.first/3) > 0) {
			q.push(tmp.first/3,tmp.second+1);
		}
		else if(tmp.first % 2 == 0 && (tmp.first/2) > 0) {
			q.push(tmp.first/2,tmp.second+1);
		}
	}
	return 0;
}