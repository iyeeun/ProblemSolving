#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned long t, n;
    vector<unsigned long> nums;

    cin >> t;
    for(unsigned long i = 0; i < t; i ++) {
        cin >> n;
        nums.push_back(n);
    }

    unsigned long max = *max_element(nums.begin(), nums.end());

    vector<vector<unsigned long> > arr(max+1, vector<unsigned long>(3, 0));
    arr[1][0] = 1; arr[2][1] = 1; arr[3][0] = arr[3][1] = arr[3][2] = 1;

    for(unsigned long i = 4; i <= max; i ++) {
        arr[i][0] = (arr[i-1][1] + arr[i-1][2]) % 1000000009;
        arr[i][1] = (arr[i-2][0] + arr[i-2][2]) % 1000000009;
        arr[i][2] = (arr[i-3][0] + arr[i-3][1]) % 1000000009;
    }

    for(long i = 0; i < nums.size(); i ++) {
        unsigned long sum = 0;
        for(int j = 0; j < 3; j ++) {
            sum += arr[nums[i]][j] % 1000000009;
        }
        cout << sum % 1000000009 << endl;
    }

    return 0;
}