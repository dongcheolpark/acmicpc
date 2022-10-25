#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;

	vector<int> arr(n+1),res(n+1);

	for(int i = 1;i<=n;i++) {
		cin>>arr[i];
	}
 	res[0] = 0;
	int max = 0;
	for(int i = 1;i<=n;i++) {
		int sum = 0;
		for(int j = 1;j<i;j++) {
			if(arr[j] < arr[i] && sum < res[j]) sum = res[j];
		}
		res[i] = sum+arr[i];
		if(max < res[i]) max = res[i];
	}

	cout<<max;
	return 0;
}