#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>

#define check(X,Y,N,M) (X < 0 || X >= N || Y < 0 || Y >= M) ? 0 : 1

using namespace std;

bool visit[1001][1001][2];
int arr[1001][1001];
int n,m;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i = 0;i<n;i++) {
		string tmp;
		cin>>tmp;
		for(int j = 0;j<m;j++) {
			arr[i][j] = tmp[j]-'0';
		}
	}
	queue<tuple<int,int,bool> > q;
	q.push(make_tuple(0,0,0));
	for(int i = 1;!q.empty();i++) {
		int q_size = q.size();	
		for(int j = 0;j<q_size;j++) {
			auto tmp = q.front();
			q.pop();
			int x = get<0>(tmp),y = get<1>(tmp),chk = get<2>(tmp);
			if(x == n-1 && y == m-1) {
				cout<<i;
				return 0;
			}
			if(visit[x][y][chk]) continue;
			visit[x][y][chk] = 1;
			if(check(x+1,y,n,m)&&arr[x+1][y] != 1) {
				q.push(make_tuple(x+1,y,chk));
			}
			else if(check(x+1,y,n,m)&&!chk) {
				q.push(make_tuple(x+1,y,1));
			}

			if(check(x-1,y,n,m)&&arr[x-1][y] != 1) {
				q.push(make_tuple(x-1,y,chk));
			}
			else if(check(x-1,y,n,m)&&!chk) {
				q.push(make_tuple(x-1,y,1));
			}

			if(check(x,y+1,n,m)&&arr[x][y+1] != 1) {
				q.push(make_tuple(x,y+1,chk));
			}
			else if(check(x,y+1,n,m)&&!chk) {
				q.push(make_tuple(x,y+1,1));
			}

			if(check(x,y-1,n,m)&&arr[x][y-1] != 1) {
				q.push(make_tuple(x,y-1,chk));
			}
			else if(check(x,y-1,n,m)&&!chk) {
				q.push(make_tuple(x,y-1,1));
			}

		}

	}
	cout<<-1;
	return 0;
}