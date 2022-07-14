#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;
    vector<vector<int>> v(N+1, vector<int>(N+1,0));

    vector<int> A(N+1);
    for(int i = 1; i <= N; i ++) {
        cin >> A[i];
        v[i][i] = 1;
    }

    for(int i = 1; i < N; i ++) {
        for(int j = i+1; j <= N; j ++) {
            if(A[i] < A[j]) {
                v[i][j] = 2;
            }
        }
    }

    for(int i = 1; i < N; i ++) {
        for(int j = i+1; j <= N; j ++) {
            for(int t = i+1; t < j; t ++) {
                if(A[t] < A[j]) {
                    if(v[i][t] + v[t][j] - 1 > v[i][j]) {
                        v[i][j] = v[i][t] + v[t][j] - 1;
                    }
                }
            }
        }
    }

    // for(int i = 1; i <= N; i ++) {
    //     for(int j = 1; j <= N; j ++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int max = 0;
    for(int i = 1; i <= N; i ++) {
        int tmp = *max_element(v[i].begin()+1,v[i].begin()+N+1);
        if(tmp > max)
            max = tmp;
    }
    cout << max << '\n';

    return 0;
}