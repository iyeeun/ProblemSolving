#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();

    for(int i = 1; i < n; i ++) {
        for(int j = 0; j < 4; j ++) {
            vector<int> tmp(land[i-1].begin(), land[i-1].end());
            tmp.erase(tmp.begin()+j);
            land[i][j] += *max_element(tmp.begin(), tmp.end());
        }
    }

    answer = *max_element(land[n-1].begin(), land[n-1].end());
    
    return answer;
}