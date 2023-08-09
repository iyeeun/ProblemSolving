#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int now = 0;
    int idx = 0;
    int done = 0;
    
    vector<int> bridge(bridge_length, 0);
    
    while(done < truck_weights.size()) {
        answer ++;
        if(bridge[bridge_length-1] != 0) {
            done ++;
            now -= bridge[bridge_length-1];
        }
        for(int i = bridge_length-1; i > 0; i --) {
            bridge[i] = bridge[i-1]; 
        }
        bridge[0] = 0;
        
        if(now + truck_weights[idx] <= weight) {
            bridge[0] = truck_weights[idx];
            now += truck_weights[idx];
            idx ++;
        }
    }

    return answer;
}