#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    bool v[100] = {};
    vector<pair<int, int>> table[100];
    int curnode = 0;
    
    for(const auto & A : costs)
    {
        table[A[0]].push_back({A[2], A[1]});
        table[A[1]].push_back({A[2], A[0]});
    }
    
    pq.push({0, 0});
    
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (v[node] == true) continue;
        
        v[node] = true;
        answer += cost;
        
        for(const auto & A : table[node])
        {
            if (!v[A.second])
                pq.push({A.first, A.second});
        }
    }
    
    return answer;
}