#include <iostream>
#include <vector>

using namespace std;

long long ans;
vector<int> v;
vector<int> tmp;

void merge(int left,int right,int mid) {
	int idx = left;
	int i = left, j = mid+1;
	int cnt = 0;
	while(i<=mid | j<=right){
		if(i > mid){
			tmp[idx++] = v[j++]; cnt++;
		}else if(j > right){
			tmp[idx++] = v[i++]; ans += (long long)cnt;
		}else if(v[i] <= v[j]){
			tmp[idx++] = v[i++]; ans += (long long)cnt;
		}else{
			tmp[idx++] = v[j++]; cnt++;
		}
	}
	for(i=left; i<=right; i++) v[i] = tmp[i];
}

void merge_sort(int left,int right) {
	if(left == right) return;
	int mid = (left+right)/2;

	merge_sort(left,mid);
	merge_sort(mid+1,right);
	merge(left,right,mid);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin>>n;
	v.resize(n+10);
	tmp.resize(n+10);
	for(int i = 0;i<n;i++) {
		cin>>v[i];
	}

	merge_sort(0,n-1);
	cout<<ans;
	return 0;
}