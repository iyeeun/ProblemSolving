#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> res;
    vector<int> num(n1+1, 0);

    int idx = 0;
    int cnt = 0;
    while(true) {
        if(res.size() == n1) {
            break;
        }
        idx ++;
        idx = idx % n1;
        if(idx == 0) {
            idx = n1;
        }
        if(num[idx] == 0) {
            cnt ++;
        }
        if(cnt == n2) {
            num[idx] = 1;
            cnt = 0;
            res.push_back(idx);
        }
    }

    cout << "<";
    for(int i = 0; i < res.size()-1; i ++) {
        cout << res[i] << ", ";
    }
    cout << res[res.size()-1] << ">\n";

    return 0;
}