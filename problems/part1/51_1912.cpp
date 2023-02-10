#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> max_arr(n);
    long totalmax = 0;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    max_arr[0] = arr[0];
    totalmax = arr[0];

    for(int i = 1; i < n; i ++) {
        if(max_arr[i-1]+arr[i] > arr[i]) {
            max_arr[i] = max_arr[i-1] + arr[i];
        } else {
            max_arr[i] = arr[i];
        }
        if(totalmax < max_arr[i]) {
            totalmax = max_arr[i];
        }
    }

    cout << totalmax << endl;


    return 0;
}