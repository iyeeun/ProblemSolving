#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    vector<int> arr(1000001, 1);

    arr[0] = arr[1] = 0;

    for(int i = 2; i < 1000001; i ++) {
        if(arr[i] == 0) continue;
        for(int j = 2*i; j < 1000001; j += i) {
            arr[j] = 0;
        }
    }

    for(int i = 0; i < t; i ++) {
        int num = 0, n;
        cin >> n;

        int end = n/2;
        if(n%2 != 0) end ++;
        for(int j = 2; j <= end; j ++) {
            if(arr[j] && arr[n-j]) num ++;
        }

        cout << num << '\n';
    }

    return 0;
}