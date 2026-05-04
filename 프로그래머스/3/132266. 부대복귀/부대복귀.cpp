#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> m(n + 1);
    vector<int> v (n + 1 , -1);
    queue<pair<int,int>> q;
    
    for(const auto & A : roads)
    {
        m[A[0]].push_back(A[1]);
        m[A[1]].push_back(A[0]);
    }
    
    q.push({destination, 0});
    v[destination] = 0;
    
    while(q.size())
    {
        for(const auto & A : m[q.front().first])
        {
            if (v[A] == -1)
            {
                q.push({A, q.front().second + 1});
                v[A] = q.front().second + 1;
            }
        }
        q.pop();
    }
    
    answer.reserve(sources.size());
    for(const auto & A : sources)
        answer.push_back(v[A]);
    
    return answer;
}