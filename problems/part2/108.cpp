#include <string>
#include <vector>
#include <stack>

using namespace std;

string solve(string inp) {
    if(inp == "") return "";
    
    string u = "", v = "";
    int s1 = 0, s2 = 0;
    for(int i = 0; i < inp.length(); i ++) {
        if(inp[i] == '(') s1 ++;
        else s2 ++;
        if(s1 == s2) {
            u = inp.substr(0, i+1);
            v = inp.substr(i+1, inp.length()-i);
            break;
        }
    }
    
    stack<char> st;
    bool ok = true;
    for(int i = 0; i < u.length(); i ++) {
        if(u[i] == '(') st.push(u[i]);
        else {
            if(!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                ok = false;
                break;
            }
        }
    }
    
    if(!st.empty()) ok = false;
    
    string res = solve(v);
    
    if(ok) {
        return u + res;
    } else {
        string t = '(' + res + ')';
        u = u.substr(1, u.length()-2);
        for(char c : u) {
            if(c == '(') t += ')';
            else t += '(';
        }
        return t;
    }
    
}

string solution(string p) {
    return solve(p);
}