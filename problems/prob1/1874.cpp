#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    int num;
    bool isPossible = true;
    int curr = 0;

    vector<char> result;
    
    scanf("%d", &n);

    int * flag = new int[n+1] {0,};
    flag[0] = 2;

    for(int i = 0; i < n; i ++) {
        scanf("%d", &num);

        if(num > curr) {
            for(int j = curr; j <= num; j ++) {
                if(flag[j] == 0) {
                    result.push_back('+');
                    flag[j] = 1;
                }   
            }
            flag[num] = 2;
            result.push_back('-');
        } else if (num < curr) {
            for(int j = curr; j >= num; j --) {
                if(flag[j] == 1) {
                    result.push_back('-');
                    flag[j] = 2;
                }
            }
        }
        curr = num;
    
        int t = 0;
        for(int j = 0; j < n; j ++) {
            if (flag[j] == 2) {
                t ++;
            }
        }
        if(t == n && i != n-1) {
            isPossible = false;
            break;
        }

    }

    if(isPossible) {
        for(int i = 0; i < result.size(); i ++) {
            cout << result[i] << "\n";
        }
    } else
        printf("NO\n");

    delete[] flag;

    return 0;
}