#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> v;

    /*
    7 5 12
    1+1+1 = 3
    
    */

    for(int i = 0; i < t; i ++) {
        int n;
        long sum = 0;
        cin >> n;
        for(int j = 0; j < n; j ++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        for(int j = 0; j < v.size(); j ++) {
            for(int h = j+1; h < v.size(); h ++) {
                int max = (v[j] < v[h])? v[h] : v[j];
                int min = (v[j] < v[h])? v[j] : v[h];
                while(min > 0) {
                    int tmp = max % min;
                    max = min;
                    min = tmp;
                }
                sum += max;
            }
        }
        cout << sum << '\n';
        sum = 0;
        v.clear();
    }

    return 0;
}