#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int hit_cnt = 0, miss_cnt = 0;
    
    if(cacheSize == 0) {
        return 5*cities.size();
    }
    
    vector<pair<string, int>> cache;
    
    for(int i = 0; i < cities.size(); i ++) {
        for(int j = 0; j < cities[i].length(); j ++) {
            if(cities[i][j] >= 'A' && cities[i][j] <= 'Z') {
                cities[i][j] = cities[i][j]-'A'+'a';
            }
        }
    }
    
    for(int i = 0; i < cities.size(); i ++) {
        string target = cities[i];
        
        bool hit = false;
        if(cache.size() == 0) {
            miss_cnt ++;
            cache.push_back(make_pair(target, i));
        } else if(cache.size() < cacheSize) {
            for(int j = 0; j < cache.size(); j ++) {
                if(cache[j].first == target) {
                    hit_cnt ++;
                    cache[j].second = i;
                    hit = true;
                    break;
                }
            }
            if(!hit) {
                miss_cnt ++;
                cache.push_back(make_pair(target, i));
            }
        } else {
            for(int j = 0; j < cacheSize; j ++) {
                if(cache[j].first == target) {
                    hit_cnt ++;
                    cache[j].second = i;
                    hit = true;
                    break;
                }
            }
            if(!hit) {
                miss_cnt ++;
                int lru = cache[0].second;
                int lruidx = 0;
                for(int j = 1; j < cacheSize; j ++) {
                    if(cache[j].second < lru) {
                        lru = cache[j].second;
                        lruidx = j;
                    }
                }
                cache[lruidx].first = target;
                cache[lruidx].second = i;
            }
        }
    }
    
    answer = 5*miss_cnt + hit_cnt;
    return answer;
}