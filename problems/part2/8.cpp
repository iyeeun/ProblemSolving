#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    string days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int numdays[] = {4, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int numday = 0;
    for(int i = 0; i < a; i ++) {
        numday += numdays[i];
    }
    numday += b;    
    numday %= 7;
    
    answer = days[numday];
    
    return answer;
}