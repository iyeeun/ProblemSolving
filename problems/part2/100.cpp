#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int num[] = {1, 2, 4};
    n--;
        
    while(n >= 0) {
        answer = to_string(num[n%3]) + answer;
        n/=3;
        n --;
    }
    
    return answer;
}