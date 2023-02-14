#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    vector<int> minlens(n);
    minlens[0] = 1;

    for(int i = 1; i < n; i ++) {
        minlens[i] = 1;
        for(int j = 0; j < i; j ++) {
            if(nums[j] > nums[i] && minlens[j]+ 1 > minlens[i]) {
                minlens[i] = minlens[j] + 1;
            }
        }
    }

    cout << *max_element(minlens.begin(), minlens.end()) << endl;

    return 0;
}