#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned long int n;
    vector<int> res;
    cin >> n;

    int arr[n];
    fill_n(arr, n+1, 1);
    arr[0] = arr[1] = 0;
    
    for(long i = 2; i*i < n; i ++) {
        if(arr[i]) {
            for(long j = 2*i; j < n; j += i) {
                arr[j] = 0;
            }
        }
    }

    while(n > 1) {
        long i = 2;
        while(i <= n) {
            if(n%i==0 && arr[i] == 1) {
                res.push_back(i);
                n /= i;
            }
            i ++;
        }
    }

    sort(res.begin(), res.end());

    for(int i = 0; i < res.size(); i ++) {
        cout << res[i] << endl;
    }

    return 0;
}