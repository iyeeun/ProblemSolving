#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> uplens(n);
    vector<int> downlens(n);
    vector<int> bilens(n);

    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    uplens[0] = downlens[0] = bilens[0] = 1;

    for(int i = 1; i < n; i ++) {
        uplens[i] = downlens[i] = 1;
        for(int j = 0; j < i; j ++) {
            if(nums[j] < nums[i] && uplens[j] + 1 > uplens[i]) {
                uplens[i] = uplens[j] + 1;
            }
            if(nums[j] > nums[i] && downlens[j] + 1 > downlens[i]) {
                downlens[i] = downlens[j] + 1;
            }
        }
    }

    for(int i = 1; i < n; i ++) {
        bilens[i] = max(max(uplens[i], downlens[i]), uplens[i]+downlens[i]);
    }

    cout << bilens[n-1] << endl;


    return 0;
}