#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<long long> v;

	for(int i = 0;i<n;i++) {
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	long long min = 1000000000;
	long long sum = 0;
	int idx1,idx2,idx3;
	for(int i = 0;i<n;i++) {
		int j = i+1;
		int k = n-1;
		while(j<k) {
			sum = v[j] + v[k] + v[i];
			if(llabs(sum) < min) {
				min = llabs(sum);
				idx1 = i;
				idx2 = j;
				idx3 = k;
			}
			if(sum < 0) {
				j++;
			}
			else {
				k--;
			}
		}
	}
	cout<<v[idx1]<<' '<<v[idx2]<<' '<<v[idx3];
}