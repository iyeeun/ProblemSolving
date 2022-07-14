#include <iostream>
#include <vector>

using namespace std;

int main() {

    int T;
    cin >> T;

    vector<int> arr(12);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int j = 4; j <= 12; j ++) {
        arr[j] = arr[j-1] + arr[j-2] + arr[j-3];
    }

    for(int i = 0; i < T; i ++) {
        int num;
        cin >> num;

        cout << arr[num] << '\n';

    }

    return 0;
}