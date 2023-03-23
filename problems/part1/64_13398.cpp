#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    vector<long> sums(n, 0);
    vector<int> exceptidx(n, -1);
    sums[0] = nums[0];
    long maxsum = sums[0];
    int maxidx = 0;

    for(int i = 1; i < n; i ++) {
        int mode = 0;
        sums[i] = nums[i];  
        if(sums[i-1] > sums[i]) {
            sums[i] = sums[i-1];
            exceptidx[i] = exceptidx[i-1];
        }

        if(sums[i] < sums[i-1] + nums[i]) {
            sums[i] = sums[i-1] + nums[i];
            exceptidx[i] = exceptidx[i-1];
        }

        for(int j = maxidx+1; j <= i; j ++) {
            if(nums[j] < 0) {
                int tmp = sums[maxidx];
                if(exceptidx[maxidx] != -1) {
                    tmp += nums[exceptidx[maxidx]];
                }
                cout << i << " " << tmp << endl;
                // tmp += nums[j];
                if(tmp >= sums[i]) {
                    sums[i] = tmp;
                    exceptidx[i] = j;
                }
            }
        }

        if(sums[i] > maxsum) {
            maxsum = sums[i];
            maxidx = i;
        }
    }

    for(auto i : sums) {
        cout << i << " ";
    }
    cout << endl;
    for(auto i : exceptidx) {
        cout << i << " ";
    }
    cout << endl;

    cout << sums[n-1] << endl;


    return 0;
}