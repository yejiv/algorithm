#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> bucket[101];
bool table[101][101];

int bfs(int start)
{
    priority_queue<int> pq;
    bool v[101] = {};
    int answer = 0;
    
    pq.push(start);
    
    while(!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        
        if(v[node]) continue;

        ++ answer;
        v[node] = true;
        
        for(const auto & A : bucket[node])
        {
            
            if (!v[A] && true == table[A][node])
                pq.push(A);
        }
    }
    
    return answer;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for(const auto & A : wires)
    {
        bucket[A[0]].push_back(A[1]);
        bucket[A[1]].push_back(A[0]);
        table[A[0]][A[1]] = true;
        table[A[1]][A[0]] = true;
    }
    
    for(int i = 0; i <= 100; ++i)
    {
        for(const auto & A : bucket[i])
        {
            table[A][i] = false;
            table[i][A] = false;
            int count = bfs(wires[0][0]);
            answer = min(abs(count * 2 - n), answer);
            table[A][i] = true;
            table[i][A] = true;
        }
    }
    
    return answer;
}