#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2, 0);
    
    int width = park[0].length();
    int height = park.size();
    
    for(int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j ++) {
            if(park[i][j] == 'S') {
                answer[0] = i;
                answer[1] = j;
            }
        }
    }
    
    for(auto r : routes) {
        char cmd = r[0];
        int num = r[2] - '0';
        bool possible = true;
        if(cmd == 'E') {
            for(int i = 1; i <= num; i ++) {
                if(answer[1]+i > width-1 || park[answer[0]][answer[1]+i] == 'X') {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                answer[1] += num;
            }
        } else if(cmd == 'W') {
            for(int i = 1; i <= num; i ++) {
                if(answer[1]-i < 0 || park[answer[0]][answer[1]-i] == 'X') {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                answer[1] -= num;
            }
        } else if(cmd == 'S') {
            for(int i = 1; i <= num; i ++) {
                if(answer[0]+i > height-1 || park[answer[0]+i][answer[1]] == 'X') {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                answer[0] += num;
            }
        } else if(cmd == 'N') {
            for(int i = 1; i <= num; i ++) {
                if(answer[0]-i < 0 || park[answer[0]-i][answer[1]] == 'X') {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                answer[0] -= num;
            }
        }
    }
    
    return answer;
}