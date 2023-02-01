#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int num;
    cin >> num;

    vector<int> v1(num);
    vector<int> v2(num);
    vector<int> m(1000000);
    stack<int> st;

    for(int i = 0; i < num; i ++) {
        cin >> v1[i];
        m[v1[i]] ++;
    }

    for(int i = num-1; i >= 0; i --) {
        while(!st.empty() && m[v1[i]] >= m[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            v2[i] = -1;
        } else {
            v2[i] = st.top();
        }
        st.push(v1[i]);
    }    

    for(int i = 0; i < num; i ++) {
        cout << v2[i] << " ";
    }
    cout << '\n';

    return 0;
}