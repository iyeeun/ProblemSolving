#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> nums;
    vector<double> areas;
    
    int n = k;
    nums.push_back(n);
    while(n > 1) {
        if(n % 2 == 0) n /= 2;
        else n = (n * 3) + 1;
        areas.push_back((nums.back() + n) / 2.0);
        nums.push_back(n);
    }
    
    vector<double> sums;
    sums.push_back(0);
    for(double d : areas) {
        sums.push_back(sums.back() + d);
    }
    
    for(vector<int> range : ranges) {
        int start = range[0];
        int end = nums.size() - 1 + range[1];
        
        if(start == end) answer.push_back(0.0);
        else if(start > end) answer.push_back(-1.0);
        else answer.push_back(sums[end] - sums[start]);
    }
    
    return answer;
}