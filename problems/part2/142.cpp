#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int len = words[0].length();
    
    // if target does not exist in word list
    int cnt = 0;
    for(auto w : words) {
        if(w.compare(target) == 0) cnt ++;
    }
    if(cnt == 0) return 0;
    
    // make mapping
    map<string, int> wordmap;
    for(int i = 0; i < words.size(); i ++) {
        wordmap[words[i]] = i+2;
    }
    wordmap[begin] = 0;
    wordmap[target] = 1;
    
    // make adj list
    vector<vector<int>> adj(wordmap.size()+2);
    for(auto it1 = wordmap.begin(); it1 != wordmap.end(); it1 ++) {
        for(auto it2 = wordmap.begin(); it2 != wordmap.end(); it2 ++) {
            int cnt = 0;
            for(int i = 0; i < len; i ++) {
                if((it1->first[i] - it2->first[i]) != 0) cnt ++;
            }
            if(cnt == 1) {
                adj[it1->second].push_back(it2->second);
            }
        }
    }
    
    // find dist (bfs)
    queue<int> q;
    vector<int> dist(wordmap.size()+2, -1);
    q.push(0);
    dist[0] = 0;
    
    while(!q.empty()) {
        int fr = q.front();
        q.pop();
        
        if(fr == 1) break;
        
        for(auto i : adj[fr]) {
            if(dist[i] == -1) {
                q.push(i);
                dist[i] = dist[fr] + 1;
            }
        }
        
    }
    
    if(dist[1] == -1) answer = 0;
    else answer = dist[1];
    
    return answer;
}