#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct compare {
	bool operator()(pair<int,int>& a,pair<int,int>& b) {
		return a.second < b.second;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<pair<int,int>,vector<pair<int,int> >,compare> gem;
	vector<int> bag;

	int n,k;
	cin>>n>>k;
	for(int i = 0;i<n;i++) {
		int a,b;
		cin>>a>>b; 
		gem.push(make_pair(a,b));
	}
	for(int i = 0;i<k;i++) {
		int a;
		cin>>a;
		bag.push_back(a);
	}
	sort(bag.begin(),bag.end(),greater<int>());
	long long res = 0;
	while(!bag.empty()) {
		auto _bag = bag.top();
		bag.pop();
		for(auto top = gem.top();!gem.empty();top = gem.top()) {
			gem.pop();
			if(top.first <= _bag) {
				res += top.second;
				break;
			}
		}
	}
	cout<<res;
}