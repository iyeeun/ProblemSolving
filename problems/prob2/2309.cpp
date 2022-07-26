#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> height(9);
    int sum = 0;

    for(int i = 0; i < 9; i ++) {
        cin >> height[i];
        sum += height[i];
    }

    int index[2];
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            int num = height[i] + height[j];
            if(sum - num == 100) {
                if(i != j) {
                    index[0] = i;
                    index[1] = j;
                    break;
                }
            }
        }
    }


    if(index[0] < index[1]) {
        height.erase(height.begin() + index[1]);
        height.erase(height.begin() + index[0]);
    } else if(index[0] > index[1]) {
        height.erase(height.begin() + index[0]);
        height.erase(height.begin() + index[1]);
    }

    sort(height.begin(), height.end());

    for(int i = 0; i < height.size(); i ++) {
        cout << height[i] << '\n';
    }    

    return 0;
}