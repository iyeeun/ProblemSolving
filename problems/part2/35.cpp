#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> termmap;
    
    for(int i = 0; i < terms.size(); i ++) {
        int duration = stoi(terms[i].substr(2, terms[i].length()-2));
        termmap[terms[i][0]] = duration;
    }
    
    for(int i = 0; i < privacies.size(); i ++) {
        int blank_idx = privacies[i].find(" ");
        int months = termmap[privacies[i][11]];
                
        int today_year = stoi(today.substr(0, 4));
        int today_month = stoi(today.substr(5, 2));
        int today_day = stoi(today.substr(8, 2));
        
        int expire_year = stoi(privacies[i].substr(0, 4));
        int expire_month = stoi(privacies[i].substr(5, 2)); + months;
        int expire_day = stoi(privacies[i].substr(8, 2));;
        
        expire_month += months;
        if(expire_day == 1) {
            expire_day = 28;
            expire_month -= 1;
        } else {
            expire_day -= 1;
        }
        
        expire_year += (expire_month-1) / 12;
        expire_month %= 12;
        if(expire_month == 0) expire_month = 12;
        
        cout << expire_year << "." << expire_month << "." << expire_day << endl;
            
        if(today_year > expire_year) {
            answer.push_back(i+1);
        } else if (today_year == expire_year){
            if(today_month > expire_month) {
                answer.push_back(i+1);
            } else if(today_month == expire_month) {
                if(today_day > expire_day) {
                    answer.push_back(i+1);
                }
            }
        }
        
    }
    
    
    return answer;
}