#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long> > arr(n+1, vector<long>(2, 0));
    arr[1][1] = 1; 
    if(n > 1) arr[2][0] = 1;

    for(int i = 3; i <= n; i ++) {
        arr[i][0] = 2*arr[i-2][0] + arr[i-2][1];
        arr[i][1] = arr[i-2][0] + arr[i-2][1];
    }

    cout << arr[n][0]+arr[n][1] << endl;

    return 0;
}