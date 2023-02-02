#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {

    int n;
    cin >> n;
    cin.ignore();

    /*
    1 2 3 * + 4 5 / -
    -> 1 6 | + 4 5 / -
    -> 7 | 4 5 / -
    -> 7 0.8 | -
    -> 6.20
    */

    vector<double> v(n);
    stack<double> st;

    string str;
    getline(cin, str);

    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    for(int i = 0; i < str.length(); i ++) {
        char c = str[i];
        if(c == '+' || c == '-' || c == '*' || c == '/') {
            if(st.size() >= 2 && c == '+') {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(a+b);
            } else if(st.size() >= 2 && c == '-') {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(b-a);
            } else if(st.size() >= 2 && c == '*') {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(a*b);
            } else if(st.size() >= 2 && c == '/') {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(b/a);
            }
        } else {
            st.push(v[c-'A']);
        }
    }

    std::cout << fixed;
    std::cout.precision(2);
    if(!st.empty()) {
        std::cout << st.top() << '\n';
    }

    return 0;
}