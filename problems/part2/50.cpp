#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int ans = 1;
    
    while(n > 1) {
        if(n % 2 == 1) {
            ans ++;
            n --;
        } else {
            n /= 2;
        }
    }
    
    return ans;
}