#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long num : numbers) {
        if(num % 2 == 0) {
            answer.push_back(num+1);
        } else {
            long long idx = 0;
            long long tmp = num;
            while(tmp >= 0) {
                if(tmp % 2 == 0) {
                    break;
                }
                idx ++;
                tmp /= 2;
            }
            num += pow(2, idx);
            num -= pow(2, idx-1);
            answer.push_back(num);
        }
    }
    
    return answer;
}