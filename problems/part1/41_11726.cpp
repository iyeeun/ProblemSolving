#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1);

    /*
    || --
    || --

    |-- --| |||
    |-- --| |||

    |||| ||-- --|| ---- |--| 3*1+2*2-2 = 5
    |||| ||-- --|| ---- |--| 
    */

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for(int i = 3; i <= n; i ++) {

    }

    cout << arr[n] << endl;


    return 0;
}