#include <iostream>
#include <vector>

using namespace std;

bool nums[2000001] = {false};

void go(int m, vector<int> &s, int cnt, int num) {
    if(cnt == m) {
        nums[num] = true;
        return;
    }

    go(m, s, cnt+1, num+s[cnt]);
    go(m, s, cnt+1, num);
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
    }

    for(int i = 1; i <= n; i ++) {
        go(i, s, 0, 0);
    }

    for(int i = 1; i <= 2000000; i ++) {
        if(!nums[i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}