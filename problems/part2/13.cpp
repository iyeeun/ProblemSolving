#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for(int i = 1; i < food.size(); i ++) {
        int num = food[i] / 2;
        for(int j = 0; j < num; j ++) {
            answer += to_string(i);
        }
    }
    answer += "0";
    string tmp = "";
    for(int i = answer.length()-2; i >= 0; i --) {
        tmp += answer[i];
    }
    answer += tmp;
    
    return answer;
}