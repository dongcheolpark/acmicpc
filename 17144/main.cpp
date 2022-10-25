#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, r, T;
	cin >> n >> r >> T;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i].resize(r);
	}

	pair<int, int> p1(0, 0), p2(0, 0);
	bool chk = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < r; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == -1)
			{
				if (chk)
					p2 = make_pair(i, j);
				else
				{
					p1 = make_pair(i, j);
					chk = true;
				}
			}
		}
	}
	vector<vector<int>> tmpV(n);
	for (int i = 0; i < n; i++)
	{
		tmpV[i].resize(r);
	}
	
	while (T--)
	{
		//확산
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<r;j++) {
				auto func = [v,n,r,i,j](int x,int y,vector<vector<int>>& tmpV) {
					if(0 <= x && x<n && 0<=y && y<r && v[x][y] != -1) {
						tmpV[x][y] += v[i][j]/5;
						return 1;
					}
					return 0;
				};
				int cnt = 0;
				cnt += func(i,j-1,tmpV);
				cnt += func(i,j+1,tmpV);
				cnt += func(i-1,j,tmpV);
				cnt += func(i+1,j,tmpV);
				v[i][j] -= (v[i][j]/5 * cnt);
			}
		}
		for(int i = 0;i<n;i++) {
			for(int j = 0;j<r;j++) {
				v[i][j] += tmpV[i][j];
			}
		}
		//공기청정기
		int x_dir[4] = {1,0,-1,0},y_dir[4] = {0,1,0,-1};
		auto func = [](int * x_dir,int * y_dir) {

		};
	}
	return 0;
}