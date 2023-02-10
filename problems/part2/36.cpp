#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int min, max;
    
    int idx = s.find(" ");
    int num = stoi(s.substr(0, idx));
    min = max = num;
    s = s.substr(idx+1, s.length()-idx-1);
    while(s.length() > 0) {
        idx = s.find(" ");
        if(idx == -1) {
            num = stoi(s);
            if(num < min) min = num;
            if(num > max) max = num;
            break;
        } else {
            num = stoi(s.substr(0, idx));
            if(num < min) min = num;
            if(num > max) max = num;
            s = s.substr(idx+1, s.length()-idx-1);
        }
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}