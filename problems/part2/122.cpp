#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), [&col](vector<int> d1, vector<int> d2) {
        if(d1[col-1] == d2[col-1]) {
            return d1[0] > d2[0];
        } else return d1[col-1] < d2[col-1];
    });
    
    for(int i = row_begin-1; i < row_end; i ++) {
        int tmp = 0;
        for(int j = 0; j < data[i].size(); j ++) {
            tmp += (data[i][j] % (i+1));
        }
        answer ^= tmp;
    }
    
    
    return answer;
}