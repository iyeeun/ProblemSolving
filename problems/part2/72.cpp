#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    // convert
    string s = "";
    while(n > k) {
        s = to_string(n % k) + s;
        n /= k;
    }
    s = to_string(n) + s;
    
    // find
    vector<string> v;
    string tmp = "";
    for(char c : s) {
        if(c == '0' && tmp.size() > 0) {
            v.push_back(tmp);
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if(tmp.size() > 0) v.push_back(tmp);
        
    // check
    for(int i = 0; i < v.size(); i ++) {
        unsigned long long num = stoull(v[i]);
        bool prime = true;
        for(long i = 2; i*i <= num; i ++) {
            if(num % i == 0) {
                prime = false;
                break;
            }
        }
        if(num >= 2 && prime) answer ++;
    }
    
    return answer;
}