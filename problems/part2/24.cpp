#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<char> x_arr;
    vector<char> y_arr;
    
    for(long i = 0; i < X.length(); i ++) {
        x_arr.push_back(X[i]);
    }
    
    for(long i = 0; i < Y.length(); i ++) {
        y_arr.push_back(Y[i]);
    }
    
    sort(x_arr.begin(), x_arr.end(), greater<char>());
    sort(y_arr.begin(), y_arr.end(), greater<char>());
    
    long x_idx = 0, y_idx = 0;
    long end = min(x_arr.size(), y_arr.size());
    while(x_idx < end || y_idx < end) {
        if(x_arr[x_idx] == y_arr[y_idx]) {
            answer += x_arr[x_idx]; 
            x_idx ++;
            y_idx ++;
        } else if(x_arr[x_idx] > y_arr[y_idx]) {
            x_idx ++;
        } else if(x_arr[x_idx] < y_arr[y_idx]) {
            y_idx ++;
        }
    }
    
    if(answer.length() == 0) answer = "-1";
    
    long numzero = 0;
    for(int i = 0; i < answer.length(); i ++) {
        if(answer[i] == '0') numzero ++;
    }
    if(numzero == answer.length()) answer = "0";
    
    return answer;
}