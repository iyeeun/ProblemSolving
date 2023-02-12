#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    for(int i = 0; i < t; i ++) {
        cin >> n;
        vector<vector<int> > scores(2, vector<int>(n, 0));
        for(int j = 0; j < 2; j ++) {
            for(int t = 0; t < n; t ++) {
                cin >> scores[j][t];
            }
        }

        vector<long> up(n, 0);
        vector<long> down(n, 0);
        vector<long> none(n, 0);

        up[0] = scores[0][0]; down[0] = scores[1][0];
        for(int j = 1; j < n; j ++) {
            up[j] = max(none[j-1], down[j-1]) + scores[0][j];
            down[j] = max(none[j-1], up[j-1]) + scores[1][j];
            none[j] = max(up[j-1], down[j-1]);
        }

        long maxnum = (up[n-1] > down[n-1])? up[n-1] : down[n-1];
        maxnum = (maxnum < none[n-1])? none[n-1] : maxnum;

        cout << maxnum << '\n';

    }

    return 0;
}