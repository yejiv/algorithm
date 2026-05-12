#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<string>& maps, int y, int x)
{
    queue<pair<int, int>> q;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1};
    int acc = 0;
    
    q.push({y, x}); //i ,j
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        if (maps[cur.first][cur.second] == 'X') continue;
        
        acc += maps[cur.first][cur.second] - '0';
        maps[cur.first][cur.second] = 'X';
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];
            
            if (nx >= 0 && nx < maps[0].size() && ny >= 0 && ny < maps.size())
            {
                if (maps[ny][nx] != 'X') q.push({ny, nx});
            }
        }
        
    }
    return acc;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i = 0; i < maps.size(); ++i)
    {
        for(int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] == 'X') continue;
            
            answer.push_back(bfs(maps, i, j));
        }
    }
    
    if (!answer.size()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    
    return answer;
}