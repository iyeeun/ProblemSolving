#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> bg;
    
    for(int i = 0; i < ingredient.size(); i ++) {
        bg.push(ingredient[i]);
        while(bg.size() >= 4) {
            if(bg.top() == 1) {
                bg.pop();
                if(bg.top() == 3) {
                    bg.pop();
                    if(bg.top() == 2) {
                        bg.pop();
                        if(bg.top() == 1) {
                            bg.pop();
                            answer ++;
                            break;
                        } else {
                            bg.push(2);
                            bg.push(3);
                            bg.push(1);
                            break;
                        }
                    } else {
                        bg.push(3);
                        bg.push(1);
                        break;
                    }
                } else {
                    bg.push(1);
                    break;
                }
            } else {
                break;
            }
        }
    }
    
    
    return answer;
}