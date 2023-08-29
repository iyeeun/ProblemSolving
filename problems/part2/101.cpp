#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;

    for (char num : number) {
        while (!s.empty() && k > 0 && s.top() < num) {
            s.pop();
            k--;
        }
        s.push(num);
    }

    while (k > 0) {
        s.pop();
        k--;
    }

    while (!s.empty()) {
        answer = s.top() + answer;
        s.pop();
    }

    return answer;
}
