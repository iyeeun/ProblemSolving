#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<string, string> a, pair<string, string> b) {
    return a.second.length() > b.second.length();
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<pair<string, string>> musics;
    
    string nm = "";
    for(int i = 0; i < m.length(); i ++) {
        if(i != m.length()-1 && m[i+1] == '#') {
            nm += m[i] - 'A' + 'a';
            i ++;
        } else nm += m[i];
    }
        
    for(string info : musicinfos) {
        int h1 = stoi(info.substr(0, 2)), m1 = stoi(info.substr(3, 2));
        int h2 = stoi(info.substr(6, 2)), m2 = stoi(info.substr(9, 2));
        string title = "";
        string song = "";
        string real = "";
        
        int mins = m2 + (h2-h1)*60 - m1;
        
        bool front = true;
        for(int i = 12; i < info.length(); i ++) {
            if(info[i] == ',') {
                front = false;
            } else if(front) {
                title += info[i];
            } else if(!front) {
                if(i != info.length()-1 && info[i+1] == '#') {
                    song += info[i] - 'A' + 'a';
                    i ++;
                } else {
                    song += info[i];
                }
            }
        }   
        
        int num = 0;
        while(num < mins) {
            real += song[num % song.length()];
            num ++;
        }
        
        if(real.find(nm) != -1) {
            musics.push_back(make_pair(title, real));
        }
    }
    
    if(musics.size() == 1) {
        return musics[0].first;
    } else if(musics.size() == 0) {
        return "(None)";
    } else {
        stable_sort(musics.begin(), musics.end(), cmp);
        return musics[0].first;
    }
    
}