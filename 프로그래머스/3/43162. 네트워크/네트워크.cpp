#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    queue<int> q;
    
    while(true)
    {
       if (!q.size())
       { 
           auto it = find(visited.begin(), visited.end(), false);
           if (it == visited.end()) break;
           q.push(distance(visited.begin(), it));
           ++ answer;
       }
        
        int target_node = q.front();
        q.pop();
        visited[target_node] = true;
        
        for(int i = 0; i < n; ++ i)
            if (computers[target_node][i] && visited[i] == false)
                q.push(i);
        
    }
    
    return answer;
}