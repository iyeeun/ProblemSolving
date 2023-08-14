#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    int idx = 0;
    int sz = order.size();
    int num = 1;
    
    while(true) {
        if(num < order[idx]) {
            st.push(num);
            num ++;
        } else if(num == order[idx]) {
            answer ++;
            num ++;
            idx ++;
        } else if(!st.empty() && order[idx] == st.top()) {
            answer ++;
            st.pop();
            idx ++;
        } else {
            break;
        }
    }
    
    
    
    return answer;
}