#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& item : commands) {
        auto st = array.begin();
        auto end = array.end();
        for(int i = 0;i<item[0];i++,st++);
        for(int i = array.size();i>=item[1];i--,end--);
        sort(st,end);
        answer.push_back(array[item[0]+item[2]]);
    }
    return answer;
}

int main() {
	auto a = solution({1, 5, 2, 6, 3, 7, 4},{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});
	for(auto item : a) {
		cout<<item<<' ';
	}
}