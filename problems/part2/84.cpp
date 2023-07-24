#include <string>
#include <set>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    set<pair<pair<int, int>, pair<int, int>>> route;
    int x = 0; 
    int y = 0;
    int nx = 0; 
    int ny = 0;
    
    for(char c : dirs) {
        x = nx;
        y = ny;
        if(c == 'U') {
            ny ++;
            if(ny > 5) ny = 5;
        } else if(c == 'D') {
            ny --;
            if(ny < -5) ny = -5;
        } else if(c == 'L') {
            nx --;
            if(nx < -5) nx = -5;
        } else if(c == 'R') {
            nx ++;
            if(nx > 5) nx = 5;
        }
        if(x == nx && y == ny) continue;
        auto res1 = route.insert(make_pair(make_pair(x, y), make_pair(nx, ny)));
        auto res2 = route.insert(make_pair(make_pair(nx, ny), make_pair(x, y)));
        if(res1.second && res2.second) answer ++;
    }
    
    return answer;
}