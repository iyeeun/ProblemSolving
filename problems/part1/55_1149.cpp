#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > input(n, vector<int>(3, 0));
    vector<vector<int> > arr(n, vector<int>(3, 0));

    for(int i = 0; i < n; i ++) {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    for(int i = 0; i < 3; i ++) {
        arr[0][i] = input[0][i];
    }

    for(int i = 1; i < n; i ++) {
        arr[i][0] = input[i][0];
        arr[i][0] += (arr[i-1][1] < arr[i-1][2])? arr[i-1][1] : arr[i-1][2];
        arr[i][1] = input[i][1];
        arr[i][1] += (arr[i-1][0] < arr[i-1][2])? arr[i-1][0] : arr[i-1][2];
        arr[i][2] = input[i][2];
        arr[i][2] += (arr[i-1][0] < arr[i-1][1])? arr[i-1][0] : arr[i-1][1];
    }

    cout << *min_element(arr[n-1].begin(), arr[n-1].end()) << endl;

    return 0;
}