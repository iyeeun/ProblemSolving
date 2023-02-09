#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i = 0; i < babbling.size(); i ++) {
        string str = babbling[i];
        while(str.find("aya") != -1) {
            str.replace(str.find("aya"), 3, "1");
        }
        while(str.find("ye") != -1) {
            str.replace(str.find("ye"), 2, "2");
        }
        while(str.find("woo") != -1) {
            str.replace(str.find("woo"), 3, "3");
        }
        while(str.find("ma") != -1) {
            str.replace(str.find("ma"), 2, "4");
        }
        
        int isok = 0;
        for(int j = 0; j < str.length(); j ++) {
            if(str[j] >= '1' && str[j] <= '4') {
                if(j != 0 && str[j-1] == str[j]) {
                    isok = 0;
                    break;
                }
                if(j != str.length()-1 && str[j+1] == str[j]) {
                    isok = 0;
                    break;
                }
                isok = 1;
            } else {
                isok = 0;
                break;
            }
        }
        if(isok) answer ++;
    }
    
    return answer;
}