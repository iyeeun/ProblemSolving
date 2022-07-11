#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int a, b;
    int cnt1, cnt2;
    bool isPossible = false;

    while(true) {
        scanf("%d", &num);

        if(num == 0) {
            break;
        }

        a = 3;
        b = num - 3;
        while(true) {
            if(a%2 != 0 && b%2 != 0) {
                cnt1 = 0;
                for(int i = 2; i <= sqrt(a); i ++) {
                    if(a%i == 0) cnt1 ++;
                    if(cnt1 > 0) break;
                }
                cnt2 = 0;
                for(int i = 2; i <= sqrt(b); i ++) {
                    if(b%i == 0) cnt2 ++;
                    if(cnt2 > 0) break;
                }
                if(cnt1 == 0 && cnt2 == 0) {
                    isPossible = true;
                    break;
                }
            }
            a += 2;
            b -= 2;
        }
        if(isPossible)
            printf("%d = %d + %d\n", num, a, b);     
        else
            printf("Goldbach's conjecture is wrong.\n");   

    }

    return 0;
}