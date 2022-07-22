#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacent(n, vector<int>(n));

    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        adjacent[a][b] = 1;
        adjacent[b][a] = 1;
    }


    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(adjacent[i][j] == 1) {

            }
        }
        cout << '\n';
    }



    return 0;
}