#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

enum class DIR { LEFT, RIGHT, DOWN, UP, NONE };

struct Node{
    int x;
    int y;
    DIR d;
    int cost;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int dx[4] {-1, 1, 0, 0};
    int dy[4] {0, 0, -1, 1};
    int width = board[0].size();
    int height = board.size();
    int visit[25][25][4] = {};
    
    queue<Node> q;
    q.push({0, 0, DIR::NONE, 0});
    
    while(!q.empty())
    {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        DIR prev_dir = q.front().d;
        int cur_cost = q.front().cost;
        q.pop();
        
        if (cur_x == width - 1 && cur_y == height - 1)
        {
            if (!answer || answer > cur_cost)
                answer = cur_cost;
            continue;
        }
        
        for(int k = 0; k < 4; ++k)
        {
            int nx = cur_x + dx[k];
            int ny = cur_y + dy[k];
            
            if (nx < 0 || nx >= width || ny < 0 || ny >= height || board[ny][nx])
                continue;
            
            int cost = cur_cost;
            cost += (prev_dir == (DIR)k || prev_dir == DIR::NONE) ? 100 : 600;
            
            if (cost < visit[ny][nx][k] || !visit[ny][nx][k])
            {
                visit[ny][nx][k] = cost;
                q.push({nx, ny, (DIR)k, cost});
            }
        }
    }
    
    return answer;
}
