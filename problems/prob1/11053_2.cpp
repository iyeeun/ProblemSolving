#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> list(N+1, 1); // 각 원소를 골랐을 때의 최장 길이
    vector<vector<int>> v(N+1, vector<int>(N+1,0));

    vector<int> A(N+1);
    for(int i = 1; i <= N; i ++) {
        cin >> A[i];
    }

    for(int i = 1; i <= N; i ++) {
        for(int j = 1; j < i; j ++) {
            if(A[j] < A[i]) {
                int new_length = list[j] + 1;
                if(list[i] < new_length) {
                    list[i] = new_length;
                }
            }
        }
    }

    cout << *max_element(list.begin()+1, list.begin()+N+1) << '\n';

    return 0;
}