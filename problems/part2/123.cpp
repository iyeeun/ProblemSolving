#include <string>
#include <vector>

using namespace std;

vector<int> makePrefixSum(vector<int> &sum, int n) {
    if(n == 1) return sum;
    vector<int> prefixSum;
    
    prefixSum.push_back(sum[n-1]);
    
    for(int i = 2*n-1; i < sum.size(); i += n) {
        prefixSum.push_back(sum[i] - sum[i-n]);
    }
    
    return prefixSum;
}

int solution(string s) {
    int answer = s.length();
    
    vector<int> v;
    vector<int> sum;
    for(char c : s) {
        v.push_back(c - 'a');
        if(sum.size() == 0) sum.push_back(v[0]);
        else sum.push_back(v.back() + sum.back());
    }
    
    for(int i = 1; i < s.length(); i ++) {
        vector<int> prefix;
        if(i > 1) prefix = makePrefixSum(sum, i);
        else prefix = v;
        
        int answer_i = s.length();
        
        int cnt = 0;
        for(int j = 0; j < prefix.size()-1; j ++) {
            if(prefix[j] == prefix[j+1]) {
                bool same = true;
                for(int t = 0; t < i; t ++) {
                    if(v[i*j + t] != v[i*(j+1) + t]) {
                        same = false;
                        break;
                    }
                }
                if(!same) {
                    if(cnt > 1) {
                        answer_i -= ((cnt*i) - (i+to_string(cnt).length()));
                        cnt = 0;
                    }
                    cnt = 0;
                } else {
                    if(cnt == 0) cnt = 2;
                    else cnt ++;
                }
            } else {
                if(cnt > 1) {
                    answer_i -= ((cnt*i) - (i+to_string(cnt).length()));
                    cnt = 0;
                }
            }
        }
        if(cnt > 1) {
            answer_i -= ((cnt*i) - (i+to_string(cnt).length()));
        }
        
        if(answer_i < answer) answer = answer_i;
    }
    
    return answer;
}