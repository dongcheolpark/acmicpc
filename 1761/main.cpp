#include <iostream>
#include <vector>

#define MAX 1000000

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int start,end;

	cin>>start>>end;

	vector<vector<int>> path(2500,vector<int>(1500,0));
	vector<pair<int,int>> index(MAX+1);
	vector<int> row_go = {-1,-2,-1,1,2,1};
	vector<int> col_go = {1,0,-1,-1,0,1,};
	vector<int> move_cnt = {1,0,1,1,1,1};
	pair<int,int> start_pos;


	int row = 1250;
	int col = 600;
	int sel = 0;
	if(start == 1)start_pos = make_pair(row,col);
	int dir = 0;
	int cnt = 2;
	for(int i = 2;i<=MAX;i++) {
		index[i] = make_pair(row,col);
		path[row][col] = i;
		row += row_go[0];
		col += col_go[0];
	}

	return 0;
}