#include <iostream>
#include <vector>

using namespace std;

int n,m;
int union_find[500000];

int Find(int x) {
	if(x == union_find[x]) return x;
	return union_find[x] = Find(union_find[x]);
}

bool Union(int x,int dest) {
	int a = Find(x);	
	int b = Find(dest);	
	if(a == b) return true;
	if(x < dest) union_find[x] = dest;
	else union_find[dest] = x;
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;	
	for(int i = 0;i<n;i++) {
		union_find[i] = i;
	}
	for(int i = 0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		if(Union(a,b)) {
			cout<<i+1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}