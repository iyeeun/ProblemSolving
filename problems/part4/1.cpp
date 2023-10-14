#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(m)); // 공격력
    vector<vector<int>> attlog(n, vector<int>(m, 0)); // 마지막 공격 시점
    vector<vector<int>> dmglog(n, vector<int>(m, 0)); // 마지막 공격 받은 시점
    vector<pair<int, int>> lst; // 남은 포탑

    int dx1[] = {0, 1, 0, -1};
    int dy1[] = {1, 0, -1, 0};
    int dx2[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy2[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> arr[i][j];
            if(arr[i][j] > 0) lst.push_back(make_pair(i, j));
        }
    }

    int cnt = 1;

    while(cnt <= k) {

        sort(lst.begin(), lst.end(), [&arr, &attlog](pair<int, int> a, pair<int, int> b){
            int x1 = a.first, y1 = a.second, x2 = b.first, y2 = b.second;
            if(arr[x1][y1] == arr[x2][y2]) {
                if(attlog[x1][y1] == attlog[x2][y2]) {
                    if(x1+y1 == x2+y2) {
                        return y1 < y2;
                    } else return (x1+y1 < x2+y2);
                } else return (attlog[x1][y1] < attlog[x2][y2]);
            } else return (arr[x1][y1] > arr[x2][y2]);
        });

        // 1 & 2
        pair<int, int> attacker = lst.back();
        pair<int, int> damage = lst[0];
        arr[attacker.first][attacker.second] += (n+m);
        int attpower = arr[attacker.first][attacker.second];
        attlog[attacker.first][attacker.second] = cnt;
        // cout << "attacker : " << attacker.first << " " << attacker.second << endl;
        // cout << "damage : " << damage.first << " " << damage.second << endl;

        // 3 : attack
        vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        dist[attacker.first][attacker.second] = 0;
        q.push(attacker);
        while(!q.empty()) {
            pair<int, int> fr = q.front();
            q.pop();

            for(int i = 0; i < 4; i ++) {
                int nx = (fr.first + dx1[i] + n) % n;
                int ny = (fr.second + dy1[i] + m) % m;
                if(arr[nx][ny] > 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[fr.first][fr.second] + 1;
                    prev[nx][ny] = fr;
                    q.push(make_pair(nx, ny));
                }
            }
        }

        if(dist[damage.first][damage.second] != -1) {
            // lazer
            // cout << "LAZER\n";
            arr[damage.first][damage.second] -= attpower;
            dmglog[damage.first][damage.second] = cnt;
            if(arr[damage.first][damage.second] <= 0) {
                lst.erase(remove(lst.begin(), lst.end(), damage));
            }
            pair<int, int> prevnode = prev[damage.first][damage.second];
            while(prevnode != attacker) {
                arr[prevnode.first][prevnode.second] -= (attpower/2);
                dmglog[prevnode.first][prevnode.second] = cnt;
                if(arr[prevnode.first][prevnode.second] <= 0) {
                    lst.erase(remove(lst.begin(), lst.end(), prevnode));
                }
                prevnode = prev[prevnode.first][prevnode.second];
            }
            
        } else {
            // bomb
            // cout << "BOMB\n";
            arr[damage.first][damage.second] -= attpower;
            dmglog[damage.first][damage.second] = cnt;
            if(arr[damage.first][damage.second] <= 0) {
                lst.erase(remove(lst.begin(), lst.end(), damage));
            }
            for(int i = 0; i < 8; i ++) {
                int nx = (damage.first + dx2[i] + n) % n;
                int ny = (damage.second + dy2[i] + m) % m;
                if(arr[nx][ny] > 0) {
                    if(nx == attacker.first && ny == attacker.second) continue;
                    arr[nx][ny] -= (attpower/2);
                    dmglog[nx][ny] = cnt;
                    if(arr[nx][ny] <= 0) {
                        lst.erase(remove(lst.begin(), lst.end(), make_pair(nx, ny)));
                    }
                }
            }
        }

        if(lst.size() == 1) break;

        // 4
        for(auto l : lst) {
            if(l != attacker && dmglog[l.first][l.second] != cnt) {
                arr[l.first][l.second] ++;
            }
        }

        // for(int i = 0; i < n; i ++) {
        //     for(int j = 0; j < m; j ++) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cnt ++;
    }

    int answer = -1;
    for(int i = 0; i < n; i ++) {
        answer = max(answer, *max_element(arr[i].begin(), arr[i].end()));
    }
    cout << answer << "\n";

    return 0;
}