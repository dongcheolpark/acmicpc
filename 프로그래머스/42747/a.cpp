#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater<int>());
    int n = citations.size();
    for(int i = citations[0];i>0;i--) {
        int a = 0;
        for(int j = 0;j<n;j++) {
            if(citations[j] < i) break;
            a++;
        }
        if(a>i&&n-a>i) return i;
    }
    //6 5 3 1 0 n=5
    return answer;
}

int main() {
	cout<<solution({3,0,6,1,5});
}