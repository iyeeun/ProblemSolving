#include <iostream>
#include <vector>

using namespace std;

int main() {

    int M, N;

    cin >> M >> N;

    // 1. 배열 만들기 및 초기화
    vector<bool> vec(N+1, true);
    vec[0] = false;
    vec[1] = false;

    // 2. 지우기
    for(int i = 0; i*i <= N; i ++) { 
        if(vec[i]) { // 소수라면
            for(int j = 2*i; j <= N; j += i) { // j=i*i로 최적화 가능
                vec[j] = false; // 그 배수들은 소수가 아니다
            }
        }
    }

    // 3. 출력하기
    for(int i = M; i <= N; i ++) {
        if(vec[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}