#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    /*
    arr[i]는 i가 1로 만들어지기 위해 필요한 최소 연산 횟수
    */

    vector<int> arr(N+1, 100000);

    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    int tmp = 0;

    for(int i = 4; i <= N; i ++) {
        // 3으로 나눠지는 경우
        if(i%3 == 0) {
            tmp = 1 + arr[i/3];
            if(tmp < arr[i]) {
                arr[i] = tmp;
            }
        }

        // 2로 나눠지는 경우
        if(i%2 == 0) {
            tmp = 1 + arr[i/2];
            if(tmp < arr[i]) {
                arr[i] = tmp;
            }
        }
        
        // 1로 빼는 경우
        tmp = 1 + arr[i-1];
        if(tmp < arr[i]) {
            arr[i] = tmp;
        }
        
    }

    cout << arr[N] << '\n';
    
    return 0;
}