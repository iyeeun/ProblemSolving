#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> nums(t);

    for(int i = 0; i < t; i ++) {
        cin >> nums[i];
    }

    int max = *max_element(nums.begin(), nums.end());

    vector<long> arr(max+1);
    arr[1] = 1; arr[2] = 2; arr[3] = 4;
    for(int i = 4; i <= max; i ++) {
        arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % 1000000009;
    }

    for(int i = 0; i < t; i ++) {
        cout << arr[nums[i]] << endl;
    }

    return 0;
}