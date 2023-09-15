#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int win[][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

bool isEnd(int idx, vector<int> &v) {
    
    vector<int> hit(8, 0);
    
    for(int i = 0; i < idx; i ++) {
        for(int j = 0; j < 8; j ++) {
            for(int t = 0; t < 3; t ++) {
                if(win[j][t] == v[i]) hit[j] ++;
            }
        }
    }
    
    for(int i = 0; i < 8; i ++) {
        if(hit[i] == 3) return true;
    }
        
    return false;
}

int solution(vector<string> board) {    
    int o = 0;
    int x = 0;
    vector<int> ov;
    vector<int> xv;
    
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            if(board[i][j] == 'O') {
                o ++;
                ov.push_back(i*3+j);
            } else if(board[i][j] == 'X') {
                x ++;
                xv.push_back(i*3+j);
            }
        }
    }
    
    if(x > o) return 0;
    if(o-x > 1) return 0;

    if(o < 3) return 1;
    else if(o == 3 && x == 2) return 1;
    else if((o == 3 && x == 3) || (o == 4 && x == 4)) {
        if(isEnd(o, ov)) return 0;
        else return 1;
    } else if((o == 4 && x == 3) || o == 5 && x == 4) {
        if(isEnd(x, xv)) {
            return 0;
        } else return 1;
    } else return 0;
    
    return 0;
}