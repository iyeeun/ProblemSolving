#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4, -1);
    for(int i = 0; i < wallpaper.size(); i ++) {
        for(int j = 0; j < wallpaper[i].length(); j ++) {
            char c = wallpaper[i][j];
            if(c == '#') {
                if(answer[0] == -1) {
                    answer[0] = i;
                }
                if(answer[1] == -1 || j < answer[1]) {
                    answer[1] = j;
                }
                if(answer[2] == -1 || i+1 > answer[2]) {
                    answer[2] = i+1;
                }
                if(answer[3] == -1 || j+1 > answer[3]) {
                    answer[3] = j+1;
                }
            }
        }
    }
    return answer;
}