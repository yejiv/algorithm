#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

struct Node{
    int y;
    int x;
    int d;
};

int solution(vector<string> maps) {
    int answer = 0;
    bool leverOn = false;
    bool find = false;
    queue<Node> q;
    bool visit[100][100] = { false };
    int w = maps[0].size();
    int h = maps.size();
    
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            if (maps[i][j] == 'S') { q.push(Node{i, j, 0}) ; break;}

    while(q.size())
    {   
        Node n = q.front(); q.pop();
        
        if (!leverOn && maps[n.y][n.x] == 'L') 
        {
            answer += n.d; leverOn = true; n.d = 0; q = queue<Node>(); memset(visit, false, sizeof(visit));
        }
        else if (leverOn && maps[n.y][n.x] == 'E')
        {
            answer += n.d; find = true; break;
        }

        if (n.y - 1 >= 0 && maps[n.y - 1][n.x] != 'X' && !visit[n.y - 1][n.x])
        {
            q.push(Node{n.y - 1, n.x, n.d + 1});
            visit[n.y - 1][n.x] = true;
        }
        
        if (n.y + 1 < h && maps[n.y + 1][n.x] != 'X' && !visit[n.y + 1][n.x])
        {
            q.push(Node{n.y + 1, n.x, n.d + 1});
            visit[n.y + 1][n.x] = true;
        }
        
        if (n.x - 1 >= 0 && maps[n.y][n.x - 1] != 'X' && !visit[n.y][n.x - 1])
        {
            q.push(Node{n.y, n.x - 1, n.d + 1});
            visit[n.y][n.x - 1] = true;
        }
        
        if (n.x + 1 < w && maps[n.y][n.x + 1] != 'X' && !visit[n.y][n.x + 1])
        {
            q.push(Node{n.y, n.x + 1, n.d + 1});
            visit[n.y][n.x + 1] = true;
        }
    }
    
    return (leverOn == true && find == true) ? answer : -1;
}