#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>> map(N + 1);
    vector<int> d(N + 1, -1);
    queue<pair<int, int>> q;
    
    for(const auto & A : road)
    {
        map[A[0]].push_back({A[1], A[2]});
        map[A[1]].push_back({A[0], A[2]});
    }
    
    q.push({1,0});

    while(!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (d[node] >= 0 && d[node] < dist) continue;
        
        d[node] = dist;
        
        for(const auto & A : map[node])
        {
            if (d[A.first] < 0 || d[A.first] > A.second + dist)
                q.push({A.first, A.second + dist});
        }
    }
    
    for(int i = 1; i <= N; ++i)
    {
        if (d[i] <= K) ++answer;
    }

    return answer;
}