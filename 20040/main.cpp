#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> union_find;

void Union() {

}
void Find() {

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;	
	union_find.resize(n);
	for(int i = 0;i<n;i++) {
		union_find[i] = i;
	}
	for(int i = 0;i<m;i++) {

	}
}