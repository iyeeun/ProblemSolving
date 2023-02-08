#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    string input;
    string output = "";
    cin >> input;
    string arr[] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    if(input == "0") {
        cout << "0\n";
        return 0;
    }

    for(int i = 0; i < input.length(); i ++) {
        output += arr[input[i]-'0'];
    }

    int idx = 0;
    while(true) {
        if (output[idx] == '1') break;
        output = output.substr(idx+1, output.length()-idx-1);
    }

    cout << output << endl;

    return 0;
}