#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    int n = arr.size();
    int size = n;
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            answer[arr[i][j]] ++;
        }
    }
    
    while(size > 1) {
        for(int i = 0; i < n; i += size) {
            for(int j = 0; j < n; j += size) {
                int sum = 0;
                for(int t1 = 0; t1 < size; t1 ++) {
                    for(int t2 = 0; t2 < size; t2 ++) {
                        sum += arr[i+t1][j+t2];
                    }
                }
                if(sum == 0) {
                    answer[0] -= size * size;
                    answer[0] ++;
                    for(int t1 = 0; t1 < size; t1 ++) {
                        for(int t2 = 0; t2 < size; t2 ++) {
                            arr[i+t1][j+t2] = -1;
                        }
                    }
                } else if(sum == size * size) {
                    answer[1] -= size * size;
                    answer[1] ++;
                    for(int t1 = 0; t1 < size; t1 ++) {
                        for(int t2 = 0; t2 < size; t2 ++) {
                            arr[i+t1][j+t2] = -1;
                        }
                    }
                }
            }
        }
        size /= 2;
    }
    
    
    return answer;
}