#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    for(int i = 0; i < nums.size(); i ++) {
        for(int j = i+1; j < nums.size(); j ++) {
            for(int t = j+1; t < nums.size(); t ++) {
                int num = nums[i] + nums[j] + nums[t];
                int cnt = 0;
                for(int m = 2; m < num; m ++) {
                    if(num % m == 0) cnt ++;
                }
                if(cnt == 0) answer ++;
            }
        }
    }

    return answer;
}