#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    int g = max(a,b);
    int l = min(a,b);
    while(l > 0) {
        int tmp = g % l;
        g = l;
        l = tmp;
    }
    cout << g << endl;
    cout << (a*b / g) << endl;

    return 0;
}