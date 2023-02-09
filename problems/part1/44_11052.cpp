#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, price;
    cin >> n;
    vector<int> prices(n+1);
    vector<int> arr(n+1, 0);

    for(int i = 1; i <= n; i ++) {
        cin >> price;
        prices[i] = price;
    }

    arr[1] = prices[1];
    for(int i = 2; i <= n; i ++) {
        int price = prices[i];
        for(int j = 1; j <= i/2; j ++) {
            if(prices[j] + arr[i-j] > price) {
                price = prices[j] + arr[i-j];
            }
        }
        arr[i] = price;
        
    }

    cout << arr[n] << endl;

    return 0;
}