#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<unsigned long> arr_1(100001, 0); // 끝자리가 1
    vector<unsigned long> arr_2(100001, 0);
    vector<unsigned long> arr_3(100001, 0);

    arr_1[1] = 1;
    arr_2[2] = 1;
    arr_1[3] = 1; arr_2[3] = 1; arr_3[3] = 1;

    for(int i = 0; i < T; i ++) {
        int n;
        cin >> n;

        for(int j = 4; j <= n; j ++) {
            arr_1[j] = (arr_2[j-1] + arr_3[j-1])%1000000009;
            arr_2[j] = (arr_1[j-2] + arr_3[j-2])%1000000009;
            arr_3[j] = (arr_1[j-3] + arr_2[j-3])%1000000009;
        }

        cout << (arr_1[n] + arr_2[n] + arr_3[n])%1000000009 << '\n';

    }

    return 0;
}