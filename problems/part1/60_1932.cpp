#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > tri(n+1);
  vector<vector<long> > dp(n+1);
  
  
  for(int i = 1; i <= n; i ++) {
    for(int j = 0; j < i; j ++) {
      int tmp;
      cin >> tmp;
      tri[i].push_back(tmp);
    }
  }
  dp[1].push_back(tri[1][0]);
  
  for(int i = 2; i <= n; i ++) {
    for(int j = 0; j < tri[i].size(); j ++) {
      if(j == 0) {
        dp[i].push_back(dp[i-1][0] + tri[i][j]);
      } else if(j == tri[i].size()-1) {
        dp[i].push_back(dp[i-1][i-2] + tri[i][j]);
      } else {
        dp[i].push_back(max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j]);
      }
    }
  }

  cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
  
}
