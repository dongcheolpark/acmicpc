#include <iostream>
#include <vector>

#define INF 2100000000

#define MIN(X,Y) ((X)<(Y)?(X):(Y))

using namespace std;

int n,answer_bit ;
vector<vector<int>> arr,cost;

int dfs(int x,int bit) {
	if(bit == answer_bit) {
		if(arr[x][0] == 0) return INF;
		else return arr[x][0];
	}

	if (cost[x][bit] != -1) return cost[x][bit];
    cost[x][bit] = INF;

	for(int i = 0;i<n;i++) {
		if(arr[x][i] == 0) continue; // 현재 노드면 컨티뉴 
		if((bit & (1<<i)) == 1<<i) continue; // 간적이 있으면 컨티뉴 

		cost[x][bit] = MIN(cost[x][bit],arr[x][i] + dfs(i,bit | 1<<i));
	}
	return cost[x][bit];
}

int main() {
	std::cin>>n;	
	arr.resize(n);
	cost.resize(n);
	answer_bit = (2<<(n-1))-1;
	for(int i = 0;i<n;i++) {
		arr[i].resize(n);
		cost[i].resize(2<<n);
		fill(cost[i].begin(),cost[i].end(),-1);
		for(int j = 0;j<n;j++) {
			cin>>arr[i][j];
		}
	}

	cout<<dfs(0,1);
}