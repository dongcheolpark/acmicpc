#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MOVE(X,Y) (Y<8?X:X+1),(Y<8?Y+1:0)

vector<vector<int > > v,visit;
int n = 9;

void print() {
	system("clear");
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cout<<v[i][j];
		}
		cout<<'\n';
	}
}

bool check(int x,int y) {
	vector<int> arr_x(10),arr_y(10),arr_square(10);
	if(v[x][y] == 0) return false;
	for(int i = 0;i<n;i++) {
		arr_x[i] = 0;
		arr_y[i] = 0;
		arr_square[i] = 0;
	}
	for(int i = 0;i<n;i++) {
		arr_x[v[x][i]]++;
		arr_y[v[i][y]]++;
		int sq_x = (x/3*3) + (i/3);
		int sq_y = (y/3*3) + (i%3);
		arr_square[v[sq_x][sq_y]]++;
	}
	if(arr_x[v[x][y]] > 1||arr_y[v[x][y]] > 1||arr_square[v[x][y]] > 1) return true;
	return false;
}

void func(int x,int y) {
	//print();
	if(x == 8&&y==8) {
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<n;j++) {
				cout<<v[i][j];
			}
			cout<<'\n';
		}
		exit(0);
	}
	if(v[x][y]) {
		func(MOVE(x,y));
		return;
	}
	for(int i = 1;i<=9;i++) {
		v[x][y] = i;
		if(check(x,y)) continue;
		func(MOVE(x,y));
	}
	v[x][y] = 0;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	v.resize(9);
	visit.resize(n,vector<int>(n,0));

	for(int i = 0;i<9;i++) {
		string tmp;
		cin>>tmp;
		for(int j = 0;j<n;j++) {
			int x = tmp[j] -'0';
			if(x != 0) {
				visit[i][j] = 1;
			}
			else visit[i][j] = 0;
			v[i].push_back(x);
		}
	}
	func(0,0);
}
