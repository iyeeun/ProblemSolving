#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size()-1; i ++) {
        int len = phone_book[i].length();
        if(phone_book[i].compare(0, len, phone_book[i+1], 0, len) == 0) {
            answer = false;
            break;
        }
    }
    return answer;
}