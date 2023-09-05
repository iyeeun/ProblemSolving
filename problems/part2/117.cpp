#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findGcd(vector<int> &arr) {
    int a = arr[0];
    if(arr.size() == 1) return a;
    
    int g, l;
    for(int i = 1; i < arr.size(); i ++) {
        int b = arr[i];
        g = max(a, b);
        l = min(a, b);
        
        while(l > 0) {
            int tmp = g % l;
            g = l;
            l = tmp;
        }
        
        a = g;
    }
    
    return g;
}

int solution(vector<int> arrayA, vector<int> arrayB) {    
    int ares = findGcd(arrayA);
    int bres = findGcd(arrayB);
            
    bool aok = true, bok = true;
    if(ares != 1) {
        for(int b : arrayB) {
            if(b % ares == 0) {
                aok = false;
                break;
            }
        }
    } else aok = false;
    
    if(bres != 1) {
        for(int a : arrayA) {
            if(a % bres == 0) {
                bok = false;
                break;
            }
        }
    } else bok = false;
    
    if(aok && bok) {
        return max(ares, bres);
    } else if(aok) return ares;
    else if(bok) return bres;
    else return 0;
}