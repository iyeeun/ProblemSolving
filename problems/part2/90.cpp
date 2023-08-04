#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> count1;
    map<int, int> count2;
    
    for(int t : topping) {
        count1[t] ++;
    }
    int num1 = count1.size();
    int num2 = 0;
    
    for(int t : topping) {
        count1[t] --;
        if(count1[t] == 0) num1 --;
        if(count2[t] == 0) num2 ++;
        count2[t] ++;
        if(num1 == num2) answer ++;
    }
    
    
    return answer;
}