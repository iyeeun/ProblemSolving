#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <map>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = -1;
    deque<long long> nums;
    deque<char> ops;
    map<char, int> m = {
        {'+', 0}, {'-', 1}, {'*', 2}
    };
    
    int priority[6][3] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0}
    };
        
    
    
    for(int p = 0; p < 6; p ++) {
        string num = "";
        
        for(int i = 0; i < expression.length(); i ++) {
            char c = expression[i];
            if(c >= '0' && c <= '9') {
                num += c;
            } else {
                nums.push_back(stoll(num));
                num = "";
                
                while(nums.size() >= 2 && priority[p][m[ops.back()]] > priority[p][m[c]]) {
                    long long num2 = nums.back();
                    nums.pop_back();
                    long long num1 = nums.back();
                    nums.pop_back();
                    char op = ops.back();
                    ops.pop_back();
                    long long res;
                    if(op == '+') res = num1 + num2;
                    else if(op == '-') res = num1 - num2;
                    else if(op == '*') res = num1 * num2;
                    nums.push_back(res);
                }
                
                if(ops.size() > 0 && c == '-' && ops.back() == '-') {
                    ops.pop_back();
                    long long num2 = nums.back();
                    nums.pop_back();
                    long long num1 = nums.back();
                    nums.pop_back();
                    nums.push_back(num1 - num2);
                }
                
                ops.push_back(c);
            }
        }
        
        if(num != "") nums.push_back(stoll(num));
        
        while(!ops.empty()) {
            long long num2 = nums.back();
            nums.pop_back();
            long long num1 = nums.back();
            nums.pop_back();
            char op = ops.back();
            ops.pop_back();
            long long res;
            if(op == '+') res = num1 + num2;
            else if(op == '-') res = num1 - num2;
            else if(op == '*') res = num1 * num2;
            nums.push_back(res);
        }
        
        if(answer == -1 || abs(nums.front()) > answer) {
            answer = abs(nums.front());
            cout << p << endl;
        }
        
        nums.clear();
        ops.clear();
        
    }
 
    return answer;
}