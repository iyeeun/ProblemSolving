#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> maxs(n, 0);
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    maxs[0] = nums[0];
    for(int i = 1; i < n; i ++) {
        maxs[i] = nums[i];
        for(int j = 0; j < i; j ++) {
            if(nums[j] < nums[i] && maxs[j] + nums[i] > maxs[i]) {
                maxs[i] = maxs[j] + nums[i];
            }
        }
    }

    cout << *max_element(maxs.begin(), maxs.end()) << endl;

    return 0;
}