#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    queue<pair<int, int>> q;
    vector<int> table[20001];
    bool v[20001] = {};
    int deptharr[20001] = {};
    int maxdepth = 0;
    
    for(const auto & A : edge)
    {
        table[A[0]].push_back(A[1]);
        table[A[1]].push_back(A[0]);
    }
    
    q.push({1, 0});
    
    while(!q.empty())
    {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (v[node]) continue;
        
        v[node] = true;
        ++ deptharr[depth];
        if (maxdepth < depth) maxdepth = depth;
        
        for(const auto & A : table[node])
        {
            if (!v[A]) q.push({A, depth + 1});
        }
    }
    return deptharr[maxdepth];
}