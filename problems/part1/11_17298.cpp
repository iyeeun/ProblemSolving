#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    int max = 0;

    vector<int> arr(n);
    vector<int> res(n);

    stack<int> st;

    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    
    for(int i = n-1; i >= 0; i --) {
        while((!st.empty()) && (st.top() <= arr[i])) {
            st.pop();
        }
        if(st.empty()) {
            res[i] = -1;
        } else {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }

    for(int i = 0; i < n; i ++) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}