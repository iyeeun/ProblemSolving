#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0;
        
    vector<bool> num(10000000, false);
    // find prime numbers
    vector<bool> prime(10000000, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i*i < 10000000; i ++) {
        if(prime[i]) {
            for(int j = 2*i; j < 10000000; j += i) {
                prime[j] = false;
            }
        }
    }
    
    vector<int> n;
    for(int i = 0; i < numbers.length(); i ++) {
        n.push_back(numbers[i]-'0');
    }
    
    sort(n.begin(), n.end());
 
    while(true) {
        string tmp = "";
        for(auto i : n) {
            tmp += to_string(i);
        }
        for(int i = 0; i < numbers.length(); i ++) {
            int t = stoi(tmp.substr(0, i+1));
            if(!num[t] && prime[t]) {
                answer ++;
                num[t] = true;
            }
        }
        if(!next_permutation(n.begin(), n.end())) break;
    }
    
    return answer;
}