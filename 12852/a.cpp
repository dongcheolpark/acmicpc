#include <iostream>
#include <string>
#include <list>
#include <vector>

#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;
	bool arr[1000000];
	queue<pair<list<int>,int>> q;
	list<int> tmp;
	tmp.push_back(N);
	q.push(make_pair(tmp,N));
	while(1) {
		auto item = q.front();
		q.pop();
		if(item.second == 1) {
			for(auto item2 : item.first) {
				cout<<item2<<' ';
			}
		}
		auto first = item.first;
		int second = item.second;
		if(second)
		first.push_back(item);
		q.push();
	}
	return 0;
}