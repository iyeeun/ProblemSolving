#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	
	int n;
	char c;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	vector<int> groups;
	queue<pair<int, int>> q;
	
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};
	
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			cin >> c;
			arr[i][j] = c-'0';
		}
	}
	
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			if(arr[i][j] == 1) {
				q.push(make_pair(i, j));
				arr[i][j] = -1;
				int sz = 1;
				
				while(!q.empty()) {
					auto fr = q.front();
					q.pop();
					
					for(int t = 0; t < 4; t ++) {
						int nx = fr.first + dx[t];
						int ny = fr.second + dy[t];
						
						if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if(arr[nx][ny] == 1) {
							q.push(make_pair(nx, ny));
							sz ++;
							arr[nx][ny] = -1;
						}
					}
					
				}
                groups.push_back(sz);
			}
		}
	}
	
	sort(groups.begin(), groups.end());

    cout << groups.size() << '\n';
    for(auto i : groups) cout << i << ' ';
    cout << '\n';
	
	
	return 0;
}