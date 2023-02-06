#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> answer_num(3, 0);
    
    int num1[] = {1, 2, 3, 4, 5};
    int num2[] = {2, 1, 2, 3, 2, 4, 2, 5};    
    int num3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for(int i = 0; i < answers.size(); i ++) {
        int sol = answers[i];
        
        if(num1[i%5] == sol) {
            answer_num[0] ++;
        }
        if(num2[i%8] == sol) {
            answer_num[1] ++;
        }
        if(sol == num3[i%10]) {
            answer_num[2] ++;
        }
    }
    
    int max = *max_element(answer_num.begin(), answer_num.end());
    for(int i = 0; i < 3; i ++) {
        if(answer_num[i] == max) answer.push_back(i+1);
    }
    
    return answer;
}