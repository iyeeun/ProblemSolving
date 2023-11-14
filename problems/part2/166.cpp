#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    
    if(sticker.size() == 1) return sticker[0];

    vector<int> dp1(sticker.size(), 0);
    vector<int> dp2(sticker.size(), 0);
    dp1[0] = sticker[0];
    dp1[1] = max(sticker[0], sticker[1]);
    
    dp2[0] = 0;
    dp2[1] = sticker[1];
    
    for(int i = 2; i < sticker.size(); i ++) {
        dp1[i] = max(dp1[i-2]+sticker[i], dp1[i-1]);
        dp2[i] = max(dp2[i-2]+sticker[i], dp2[i-1]);
    }
    dp1[sticker.size()-1] = dp1[sticker.size()-2];
    
    answer = max(dp1[sticker.size()-1], dp2[sticker.size()-1]);

    return answer;
}