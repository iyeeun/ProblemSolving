#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> arr;
    vector<vector<int>> result;

    // index == 0일 때 초기화
    arr.push_back(A[0]);
    result.push_back(arr);
    arr.clear();

    // index >= 1
    for(int i = 1; i < N; i ++) {
        // 내 앞에 있는 것들 중에 나보다 작은 수 중에 길이가 가장 긴 것 찾기        
        int max = 0;
        int index = -1;
        for(int j = 0; j < i; j ++) {
            if((A[j] < A[i]) && (max < result[j].size())) {
                max = result[j].size();
                index = j;
            }
        }
        if(index == -1) {
            arr.push_back(A[i]);
        } else {
            arr.assign(result[index].begin(), result[index].end());
            arr.push_back(A[i]);
        }
        result.push_back(arr);
        arr.clear();
    }

    int ans = 0;
    for(int i = 0; i < N; i ++) {
        if(result[ans].size() < result[i].size()) {
            ans = i;
        }
    }

    cout << result[ans].size() << '\n';
    for(int i = 0; i < result[ans].size(); i ++) {
        cout << result[ans][i] << " ";
    }
    cout << '\n';

    return 0;
}