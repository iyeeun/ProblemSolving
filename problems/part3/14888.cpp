#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long minval = 1000000000;
long maxval = -1000000000;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    vector<int> ops;
    int op;
    for(int i = 0; i < 4; i ++) {
        cin >> op;
        char c;
        for(int j = 0; j < op; j ++) {
            ops.push_back(i);
        }
    }

    while(true) {
        long num = arr[0];
        for(int i = 0; i < ops.size(); i ++) {
            if(ops[i] == 0) {
                num += arr[i+1];
            } else if(ops[i] == 1) {
                num -= arr[i+1];
            } else if(ops[i] == 2) {
                num *= arr[i+1];
            } else if(ops[i] == 3) {
                num /= arr[i+1];
            }
        }
        if(num > maxval) maxval = num;
        if(num < minval) minval = num;
        if(!next_permutation(ops.begin(), ops.end())) break;
    }

    cout << maxval << "\n" << minval << "\n";

    return 0;
}