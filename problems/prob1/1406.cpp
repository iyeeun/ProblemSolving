#include <iostream>
#include <string>

using namespace std;

int main() {

    int n;
    string first;
    string comm;

    getline(cin, first);
    cin >> n;
    cin.ignore();

    int cursor = first.size();

    for(int i = 0; i < n; i ++) {
        cin >> comm;
        cin.ignore();

        if(comm == "L") {
            if( cursor > 0) {
                cursor --;
            }
        } else if(comm == "D") {
            if (cursor != first.size()) {
                cursor ++;
            }
        } else if(comm == "B") {
            if( cursor > 0) {
                // abc|de -> ab|cde -> ab|de
                cursor --;
                for(int j = cursor; j < first.size()-1; j ++) {
                    first[j] = first[j+1];
                }
                first[first.size()-1] = '\0';
            }
        } else if(comm == "P") {
            char c;
            cin >> c;

            // abc|da -> abceda -> abce|da
            first+=" ";
            for(int j = first.size()-2; j >= cursor; j --) {
                    first[j+1] = first[j];
            }      
            first[cursor] = c;   
            cursor ++;

        }

    }

    cout << first << endl;

    return 0;
}