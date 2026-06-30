#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, const vector<vector<int>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int count = 0;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) 
        {
            if (!visited[next]) 
            {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> win_graph(n + 1);
    vector<vector<int>> lose_graph(n + 1);

    for (int i = 0; i < results.size(); ++i) 
    {
        int winner = results[i][0];
        int loser = results[i][1];
        
        win_graph[winner].push_back(loser);
        lose_graph[loser].push_back(winner);
    }

    for (int i = 1; i <= n; ++i) 
    {
        int win_count = bfs(i, win_graph, n);
        int lose_count = bfs(i, lose_graph, n);

        if (win_count + lose_count == n - 1) 
            answer++;
    }

    return answer;
}

/*
1 - 2 
2 - 5
3 - 2
4 - 3, 2
5 -

*/