#include <iostream>
#include <queue>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    cin.ignore();

    queue<int> result;
    int *people = new int[n]{0, };

    int cnt = 0;
    int index = 0;
    while(result.size() != n) {
        
        if(people[index%n] == 0) {
            cnt ++;
            if(cnt == k) {
                result.push(index%n);
                people[index%n] = 1;
                cnt = 0;
            }
        }
        index ++;
    }

    cout << "<";
    while(result.size() != 1) {
        cout << result.front()+1 << ", ";
        result.pop();
    }
    cout << result.front()+1 << ">\n";

    return 0;
}