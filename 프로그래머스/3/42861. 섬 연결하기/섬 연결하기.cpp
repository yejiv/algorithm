#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int, int>> table[100];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int count = 0;
    bool v[100] = {};
    
    for(const auto & A : costs)
    {
        table[A[0]].push_back({A[1], A[2]});
        table[A[1]].push_back({A[0], A[2]});
    }
    
    pq.push({0, costs[0][0]});
    
    while(count < n)
    {
        pair<int,int> curnode = pq.top();
        pq.pop();
        
        if (v[curnode.second] == true) continue;
        
        answer += curnode.first;
        v[curnode.second] = true;
        ++count;
        
        for(const auto & A : table[curnode.second])
        {
            if (!v[A.first]) pq.push({A.second, A.first});
        }
    }
    
    return answer;
}