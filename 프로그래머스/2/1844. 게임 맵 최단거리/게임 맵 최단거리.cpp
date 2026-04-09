#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<vector<int> > maps)
{
    const int MAX = 10000;
    int col = maps.size();
    int row = maps[0].size();
    queue <pair<pair<int,int>, int>> q;
    int dx[4] { 1, -1, 0, 0};
    int dy[4] { 0, 0, 1, -1};
    
    q.push({{0, 0}, 1});
    maps[0][0] = 0;
    
    while(q.size())
    {
        int pos[2] = {q.front().first.first, q.front().first.second};
        int dist = q.front().second;
        q.pop();
        
        if (pos[0] == col - 1 && pos[1] == row - 1) return dist;
        
        for(int i = 0; i < 4; ++i)
        {
            int p[2] = {pos[0] + dy[i], pos[1] + dx[i]};
            if (p[0] >= 0 && p[0] < col && p[1] >= 0 && p[1] < row && maps[p[0]][p[1]])
            {
                q.push({{p[0], p[1]}, dist + 1});
                maps[p[0]][p[1]] = 0;
            }
        }
    }

    return -1;
}