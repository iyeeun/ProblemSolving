#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left[] = {3, 0};
    int right[] = {3, 2};
    
    for(int i = 0; i < numbers.size(); i ++) {
        if(numbers[i] == 0 || numbers[i] % 3 == 2) {
            int a, b;
            if(numbers[i] == 0) {
                a = 3; b = 1;
            } else {
                a = (numbers[i]/3); b = 1;
            }
            int ldist = abs(a-left[0]) + abs(b-left[1]);
            int rdist = abs(a-right[0]) + abs(b-right[1]);
            if(ldist < rdist) {
                answer += "L";
                if(numbers[i] == 0) left[0] = 3;
                else left[0] = numbers[i]/3;
                left[1] = 1;
            } else if(ldist > rdist) {
                answer += "R";
                if(numbers[i] == 0) right[0] = 3;
                else right[0] = numbers[i]/3;
                right[1] = 1;
            } else {
                if(hand == "left") {
                    answer += "L";
                    if(numbers[i] == 0) left[0] = 3;
                    else left[0] = numbers[i]/3;
                    left[1] = 1;
                } else {
                    answer += "R";
                    if(numbers[i] == 0) right[0] = 3;
                    else right[0] = numbers[i]/3;
                    right[1] = 1;
                }
            }
        } else if(numbers[i] % 3 == 1) {
            answer += "L";
            left[0] = numbers[i]/3;
            left[1] = 0;
        } else if(numbers[i] % 3 == 0) {
            answer += "R";
            right[0] = (numbers[i]-1)/3;
            right[1] = 2;
        }
    }
    
    return answer;
}