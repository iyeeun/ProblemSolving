#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int nums[10] = {0};
int arr[10] = {0};
set<string> log;

void make_array(int idx, int n, int m, int start) {
    if(idx == m) {
        string str = "";
        for(int i = 0; i < m; i ++) {
            str += (to_string(nums[arr[i]]) + " ");
        }
        auto l = log.insert(str);
        if(l.second) {
            cout << str << "\n";
        }
        return;
    }

    for(int i = 0; i < n; i ++) {
        arr[idx] = i;
        make_array(idx+1, n, m, i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    sort(nums, nums+n);

    make_array(0, n, m, 0);

    return 0;
}