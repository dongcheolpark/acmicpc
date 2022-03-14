#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

class info {
public:
	int age;
	int order;
	string name;
	bool operator<(info & a) {
		if(this->age == a.age) {
			return this->order < a.order;
		}
		else {
			return this->age < a.age;
		}
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<info> v1;
	v1.resize(n);
	for(int i = 0;i<n;i++) {
		cin>>v1[i].age>>v1[i].name;
		v1[i].order = i;
	}
	sort(v1.begin(),v1.end());
	for(int i = 0;i<n;i++) {
		cout<<v1[i].age<<' '<<v1[i].name<<'\n';
	}
	return 0;
}