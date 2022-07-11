#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int T;
    string word;
    string sentence;

    int cut = 0;
    
    cin >> T;
    cin.ignore();

    for(int i = 0; i < T; i ++) {
        getline(cin, sentence); 
        sentence += "\n";
        for(int j = 0; j < sentence.size(); j ++) {
            char c = sentence[j];
            if(c == ' ' || c == '\n') {
                for(int i = word.size()-1; i >= 0; i --) {
                    cout << word[i];
                }
                cout << " ";
                word = "";
            } else {
                word+=c;
            } 
        }
        cout << endl;
    } 

    return 0;
}