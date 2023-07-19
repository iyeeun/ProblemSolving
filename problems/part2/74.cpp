#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int num = 0;
    vector<char> arr;
    arr.push_back('0');
    while(arr.size() < t*m) {
        int tmp = num;
        vector<int> t;
        while(tmp > 0) {
            t.push_back(tmp%n);
            tmp /= n;
        }
        reverse(t.begin(), t.end());
        for(int i : t) {
            if(i < 10) arr.push_back(i+'0');
            else arr.push_back('A'+i-10);
        }
        num ++;
    }
        
    for(int i = p-1; i < arr.size(); i += m) {
        answer += arr[i];
        if(answer.length() == t) break;
    }
    
    return answer;
}