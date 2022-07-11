#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    int T;
    string sentence;

    cin >> T;
    cin.ignore();

    for(int i = 0; i < T; i ++) {
        stack<char> s;

        getline(cin, sentence);
        sentence += "\n";
        
        for(int j = 0; j <= sentence.size(); j ++) {
            if(sentence[j] == '\n') {
                while(!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << endl;
                break;
            } else if(sentence[j] == ' ') {
                while(!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << " ";
            } else {
                s.push(sentence[j]);
            }
        }




    }

    return 0;
}