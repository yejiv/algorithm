#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int idx = 0;
    int sum = 0;
    
    for(int i = 0; i < bridge_length; ++i) q.push(0);
    
    while(q.size())
    {
        ++ answer;
        
        sum -= q.front();
        q.pop();
        
        if (idx < truck_weights.size() && weight >= sum + truck_weights[idx])
        {
            q.push(truck_weights[idx]);
            sum += truck_weights[idx ++];
        }
        else if (idx < truck_weights.size())
            q.push(0);
    }
    
    return answer;
}