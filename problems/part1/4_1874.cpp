#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    int n;
    int flag = 0;
    int idx = 1;
    cin >> n;
    stack<int> st;
    vector<int> v;
    vector<char> res;

    /*
    Example
    3 2 1 4 -> + + + - - - + -
    4 2 1 3 -> NO
    1 2 3 4 -> + - + - + - + -
    */

    for(int i = 0; i < n; i ++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // first element
    for(int i = 0; i < v[0]; i ++) {
        res.push_back('+');
        st.push(i+1);
    }
    res.push_back('-');
    st.pop();
    idx = v[0]+1;

    for(int i = 1; i < v.size(); i ++) {
        if(v[i-1] > v[i]) {
            if(!st.empty() && v[i] == st.top()) {
                res.push_back('-');
                st.pop();
            } else {
                flag = 1;
                break;
            }
        } else {
            while(idx != v[i]) {
                st.push(idx++);
                res.push_back('+');
            }
            st.push(idx++);
            st.pop();
            res.push_back('+');
            res.push_back('-');
        }
        
    }

    if(flag == 1) {
        cout << "NO" << '\n';
    } else {
        for(int i = 0; i < res.size(); i ++) {
            cout << res[i] << '\n';
        }
    }

    return 0;
}