#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, deque<pair<int, int>>> m;
    map<string, int> genrescore;
    
    for(int i = 0; i < genres.size(); i ++) {
        genrescore[genres[i]] += plays[i];
        if(m[genres[i]].empty()) {
            m[genres[i]].push_back(make_pair(i, plays[i]));
        } else {
            if(m[genres[i]][0].second < plays[i]) {
                m[genres[i]].push_front(make_pair(i, plays[i]));
                if(m[genres[i]].size() > 2) m[genres[i]].pop_back();
            } else if(m[genres[i]][0].second >= plays[i]) {
                if(m[genres[i]].size() == 1) {
                    m[genres[i]].push_back(make_pair(i, plays[i]));
                } else if(m[genres[i]][1].second < plays[i]) {
                    m[genres[i]][1].first = i;
                    m[genres[i]][1].second = plays[i];
                }
            }
        }
    }
    
    vector<pair<string, int>> score(genrescore.begin(), genrescore.end());
    sort(score.begin(), score.end(), [](pair<string, int> a, pair<string, int> b){
        return a.second > b.second;
    });
    
    for(auto s : score) {
        answer.push_back(m[s.first][0].first);
        if(m[s.first].size() == 2) answer.push_back(m[s.first][1].first);
    }
        
    return answer;
}