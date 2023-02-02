#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<vector<int> > ans;
    vector<int> info(4, 0);
    string str;
    while(getline(cin, str)) {
        if(str.empty()) {
            break;
        }
        for(int i = 0; i < str.length(); i ++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                info[0] ++;
            } else if(str[i] >= 'A' && str[i] <= 'Z') {
                info[1] ++;
            } else if(str[i] >= '0' && str[i] <= '9') {
                info[2] ++;
            } else if(str[i] == ' ') {
                info[3] ++;
            }
        }
        ans.push_back(info);
        info[0] = info[1] = info[2] = info[3] = 0;
    }

    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i][0] << " " << ans[i][1] << " ";
        cout << ans[i][2] << " " << ans[i][3] << "\n";
    }


    return 0;
}