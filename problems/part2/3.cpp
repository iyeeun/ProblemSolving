#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> v;
    
    for(int i = 0; i < n; i ++) {
        int res = (arr1[i] | arr2[i]);
        string line = "";
        for(int j = n; j > 0; j --) {
            v.push_back(res%2);
            res /= 2;
        }
        for(int j = n-1; j >= 0; j --) {
            if(v[j] == 1) {
                line += "#";
            } else {
                line += " ";
            }   
        }
        // Using bit operation
        /*
        for(int j = n-1; j >= 0; j --) {
            if((res >> j) & 1) {
                line += "#";
            } else {
                line += " ";
            }
        }
        */

        // Using bitset
        /*
        bitset<16> binary_res(res);
        for(int j = 0; j < n; j ++) {
            if(binary_res[j] == 1) {
                line = "#" + line;
            } else {
                line = " " + line;    
            }
        }
       */
        answer.push_back(line);
        v.clear();
    }
    
    return answer;
}