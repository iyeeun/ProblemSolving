#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int num = storey;
    
    while(storey > 0) {
        cout << storey << endl;
        int last = storey % 10;
        storey /= 10;
        if(last > 5) {
            answer += (10 - last);
            storey ++;
        } else if(last < 5) {
            answer += last;
        } else {
            if(storey % 10 >= 5) {
                answer += (10 - last);
                storey ++;
            } else {
                answer += last;
            }
        }
    }
    
    return answer;
}