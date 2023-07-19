#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> info;
    
    for(int i = 0; i < records.size(); i ++) {
        string record = records[i];
        if(record[11] == 'I') {
            string carnum = record.substr(6, 4);
            int inh = stoi(record.substr(0, 2));
            int inm = stoi(record.substr(3, 2));
            int outh = -1;
            int outm;
            for(int j = i+1; j < records.size(); j ++) {
                if(records[j][11] == 'O' && carnum == records[j].substr(6, 4)) {
                    outh = stoi(records[j].substr(0, 2));
                    outm = stoi(records[j].substr(3, 2));
                    break;
                }
            }
            if(outh == -1) {
                outh = 23;
                outm = 59;
            }
            int time = (outh-inh) * 60 + (outm-inm);
            info.insert(make_pair(carnum, 0));
            info[carnum] += time;
        }
    }
        
    for(auto i : info) {
        if(i.second < fees[0]) {
            answer.push_back(fees[1]);
        } else {
            answer.push_back(fees[1] + (fees[3] * (ceil((i.second - fees[0]) / (float) fees[2]))));
        }
    }
    
    return answer;
}