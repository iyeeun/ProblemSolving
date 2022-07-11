#include <iostream>
#include <vector>

using namespace std;

int main() {

    int a, b;

    cin >> a >> b;

    int num;

    for(int i = min(a, b); i >= 1; i --) {
        if(a % i == 0 && b % i == 0) {
            num = i;
            cout << num << '\n';
            break;
        }
    }
 
    int i = 1;
    while(true) {
        if(num*i % a == 0 && num*i % b == 0) {
            cout << num*i << '\n';
            break;
        }
        i ++;
    }    

}