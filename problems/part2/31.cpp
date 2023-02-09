#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> scores;
    scores.insert(make_pair('R', 0));
    scores.insert(make_pair('T', 0));
    scores.insert(make_pair('C', 0));
    scores.insert(make_pair('F', 0));
    scores.insert(make_pair('J', 0));
    scores.insert(make_pair('M', 0));
    scores.insert(make_pair('A', 0));
    scores.insert(make_pair('N', 0));
    
    for(int i = 0; i < survey.size(); i ++) {
        string s = survey[i];
        char ch;
        int c = choices[i];
        if(c < 4) {
            ch = s[0];
            scores[ch] += 4-c;
        } else if(c > 4) {
            ch = s[1];
            scores[ch] += c-4;
        }
    }
    
    (scores['R'] >= scores['T'])? answer += 'R' : answer += 'T';
    (scores['C'] >= scores['F'])? answer += 'C' : answer += 'F';
    (scores['J'] >= scores['M'])? answer += 'J' : answer += 'M';
    (scores['A'] >= scores['N'])? answer += 'A' : answer += 'N';
    
    return answer;
}