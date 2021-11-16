#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int arr[100002],n,m;

int main() {
	cin>>n>>m;
	int s = 0;
	for(int i = 0;i<n;i++) {
		cin>>arr[i];
	}
	int res = 1<<21;
	int i = 0,j = 0,sum = 0;
	while(1) {
		if(sum > m)  {
			sum -= arr[i];
			i++;
		}
		else if(sum < m) {
			sum += arr[j];
			j++;
		}
		else {
			if(res > i-j) {
				res = i-j;
			} 
		}
	}
	cout<<res;
	return 0;
}