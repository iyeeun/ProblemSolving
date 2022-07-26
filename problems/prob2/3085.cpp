#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printArray(vector<string> arr, int n) {
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int findCandies(int n, vector<string> str) {
    int max_cnt = 1;
    int row_cnt = 1;
    int col_cnt = 1;

    for(int i = 0; i < n; i ++) {
        int j = 0;
        while(j < n-1) {
            if(str[i][j] == str[i][j+1]) {
                row_cnt ++;
            }
            if(str[j][i] == str[j+1][i]) {
                col_cnt ++;
            }
            j ++;
        }
        max_cnt = max(max_cnt, row_cnt);
        max_cnt = max(max_cnt, col_cnt);
        row_cnt = col_cnt = 0;
    }

    return max_cnt;
}



int main() {

    int n;
    cin >> n;

    vector<string> arr(n);
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    cout << findCandies(n, arr);

    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n-1; j ++) {  
            if(arr[i][j] != arr[i][j+1]) {
                swap(arr[i][j], arr[i][j+1]);
                //printArray(arr, n);
                cnt = max(findCandies(n, arr), cnt);
                swap(arr[i][j], arr[i][j+1]);
            }    
                
            if(arr[i][j] != arr[i][j+1]) {
                swap(arr[j][i], arr[j+1][i]);
                //printArray(arr, n);
                cnt = max(findCandies(n, arr), cnt);
                swap(arr[j][i], arr[j+1][i]);
            }            
        }
    }

    //cout << cnt << '\n';

    return 0;
}