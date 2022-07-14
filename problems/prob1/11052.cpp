#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> price(N+1);

    for(int i = 1; i <= N; i ++) {
        cin >> price[i];
    }

    for(int i = 2; i <= N; i ++) {
        int j = 1;
        while(true) {
            int new_price = price[j] + price[i-j];
            if(new_price > price[i]) {
                price[i] = new_price;
            }
            j ++;
            if(j > i-j)
                break;
        }
        cout << "\n";
    }  

    cout << price[N] << '\n';  

    return 0;
}