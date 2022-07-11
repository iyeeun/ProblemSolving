#include <iostream>
#include <queue>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    cin.ignore();

    queue<int> q;
    queue<int> result;

    for(int i = 0; i < n; i ++) {
        q.push(i);
    }

    while(result.size() < n) {

        // k-1개 pop
        for(int i = 0; i < k-1; i ++) {
            q.push(q.front());
            q.pop();
        }
        result.push(q.front());
        q.pop();

    }

    cout << "<";
    for(int i = 0; i < n-1; i ++) {
        cout << result.front()+1 << ", ";
        result.pop();
    }
    cout << result.front()+1 << ">";

    return 0;
}