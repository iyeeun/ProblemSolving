#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string nums[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
    for(int i = 0; i < 10; i ++) {
        while(true) {
            int idx = s.find(numbers[i]);
            if(idx == -1) {
                break;
            } else {
                s.replace(idx, numbers[i].length(), nums[i]);
            }
        }
    }
    
    answer = stoi(s);
    
    return answer;
}