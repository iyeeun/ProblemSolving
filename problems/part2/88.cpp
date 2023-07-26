#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> parse(string str) {
    string head = "";
    string number = "";
    bool ishead = true;
    for(int i = 0; i < str.length(); i ++) {
        if(str[i] >= '0' && str[i] <= '9') {
            if(ishead) {
                ishead = false;
            }
            number += str[i];
        } else {
            if(!ishead) break;
            if(str[i] >= 'A' && str[i] <= 'Z') {
                if(ishead) head += (str[i] - 'A' + 'a');
            } else {
                if(ishead) head += str[i];
            }
        }
    }
    vector<string> res;
    res.push_back(head);
    res.push_back(number);
    return res;
}

bool filesort(string a, string b) {
    vector<string> ares = parse(a);
    vector<string> bres = parse(b);
    
    if(ares[0] != bres[0]) {
        return ares[0] < bres[0];
    } else {
        return stoi(ares[1]) < stoi(bres[1]);
    }
    
}

vector<string> solution(vector<string> files) {
    vector<string> answer(files);
    
    stable_sort(answer.begin(), answer.end(), filesort);
    
    return answer;
}