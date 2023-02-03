#include <iostream>
#include <vector>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    vector<int> arr(b+1, 1);
    arr[1] = arr[0] = 0;
    for(int i = 2; i*i <= b; i ++) {
        if(arr[i] == 0) continue;
        else {
            for(int j = 2*i; j <= b; j += i) {
                arr[j] = 0;
            }
        }
    }

    for(int i = a; i <= b; i ++) {
        if(arr[i] == 1) cout << i << '\n';
    }

    return 0;
}