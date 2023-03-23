#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > cost(n, vector<int>(3));
    for(int i = 0; i < n; i ++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; 
    }

    vector<vector<int> > colors(n, vector<int>(3, 0)); // RGB

    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < n; j ++) {
            if(j == 0) {
                colors[j][i%3] = cost[0][i%3];
                colors[j][(i+1)%3] = 1001;
                colors[j][(i+2)%3] = 1001;
            // } else if(j == n-1) {

            } else {
                colors[i][0] = min(colors[i-1][1], colors[i-1][2]) + cost[i][0];
                colors[i][1] = min(colors[i-1][0], colors[i-1][2]) + cost[i][1];
                colors[i][2] = min(colors[i-1][0], colors[i-1][1]) + cost[i][2];
            }
        }
    }

    cout << *min_element(colors[n-1].begin(), colors[n-1].end()) << endl;

    return 0;
}