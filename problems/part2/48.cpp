#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(a != b) {
        a = ceil(a/2.0);
        b = ceil(b/2.0);
        answer ++;
    }

    return answer;
}