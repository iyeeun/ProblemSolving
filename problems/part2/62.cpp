#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int sz = sequence.size();
    
    vector<int> arr1(sz);
    vector<int> arr2(sz);
    
    vector<long long> dp1(sz);
    vector<long long> dp2(sz);
    
    for(int i = 0; i < sequence.size(); i ++) {
        arr1[i] = sequence[i] * pow(-1, i);
        arr2[i] = sequence[i] * pow(-1, i+1);
    }
    
    dp1[0] = arr1[0];
    dp2[0] = arr2[0];
    
    for(int i = 1; i < sz; i ++) {
        dp1[i] = arr1[i];
        dp2[i] = arr2[i];
        if(dp1[i-1] + arr1[i] > dp1[i]) dp1[i] = dp1[i-1] + arr1[i];
        if(dp2[i-1] + arr2[i] > dp2[i]) dp2[i] = dp2[i-1] + arr2[i];
    }
    
    long long t1 = *max_element(dp1.begin(), dp1.end());
    long long t2 = *max_element(dp2.begin(), dp2.end());
    answer = (t1 > t2)? t1 : t2;
    
    return answer;
}