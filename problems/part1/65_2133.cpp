#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i += 2) {
        arr[i] = 0;
    }
    arr[2] = 3;

    




    return 0;
}