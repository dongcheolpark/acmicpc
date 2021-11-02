#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

class shark {
public:
	int x;
	int y;
	int size;
	shark(int x,int y,int size) : x(x),y(y),size(size) {

	}	
};

shark make_shark(int x,int y,int size) {
	shark a(x,y,size);
	return a;
}

int arr[20][20];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int x,y;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin>>arr[i][j];
			if(arr[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}
	queue<shark> q;
	q.push(make_shark(x,y,1));
	int sec = 0;
	while(!q.empty()) {
		int q_size = q.size();
		for(int i = 0;i<q_size;i++) {
		}
		sec++;
	}

}