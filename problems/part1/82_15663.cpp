#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int nums[10] = {0};
bool chosen[10] = {false, };
int arr[10] = {0};
set<string> log;

void make_array(int idx, int n, int m) {
    if(idx == m) {
        string str = "";
        for(int i = 0; i < m; i ++) {
            str += (to_string(nums[arr[i]]) + " ");
        }
        auto i = log.insert(str);
        if(i.second) {
            cout << str << "\n";
        }
        return;
    }

    for(int i = 0; i < n; i ++) {
        if(chosen[i]) continue;
        chosen[i] = true;
        arr[idx] = i;
        make_array(idx+1, n, m);
        chosen[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    sort(nums, nums+n);

    make_array(0, n, m);

    return 0;
}