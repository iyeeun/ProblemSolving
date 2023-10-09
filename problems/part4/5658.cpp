#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int n, k;
    string str;
    
    map<char, string> m = {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"}, {'4', "0100"}, {'5', "0101"},
        {'6', "0110"}, {'7', "0111"}, {'8', "1000"}, {'9', "1001"}, {'A', "1010"},
        {'B', "1011"}, {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
    };
    
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) 
    {
        cin >> n >> k >> str;
        set<string, greater<string>> s;
        
        for(int i = 0; i < n/4; i ++) {
            string tmpstr = "";
            for(int tmp = 0; tmp < n; tmp ++) 
            {
                tmpstr += str[tmp];
                if(tmp % (n/4) == n/4-1) 
                {
                    string num = "";
                    for(auto c : tmpstr) {
                        num += m[c];
                    }
                    auto res = s.insert(num);
                    tmpstr = "";
                }
            }
            str += str[0];
            str = str.substr(1, n);
        }
        
        string ans;
        int i = 0;
        for(auto it = s.begin(); it != s.end(); it ++) {
        	if(i == k-1) {
            	ans = *it;
                break;
            }
            i ++;
        }
        unsigned long long number = 0;
        for(int b = 0; b < n; b ++) {
            if(ans[n-1-b] == '1') number += pow(2, b);
        }
        cout << '#' << test_case << ' ' << number << '\n';
	}
	return 0;
}