#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int global_n;

bool compare(string a, string b) {
    if(a[global_n] == b[global_n]) {
        return (a < b);
    } else {
        return (a[global_n] < b[global_n]);
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    global_n = n;
    sort(strings.begin(), strings.end(), compare);
    answer = strings;
    
    return answer;
}