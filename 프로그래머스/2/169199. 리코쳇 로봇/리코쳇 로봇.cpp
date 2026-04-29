#include <string>
#include <vector>
#include <queue>

using namespace std;

enum class DIR { NON, UP, DOWN, RIGHT, LEFT };

struct Node{
    int i;
    int j;
    DIR dir;
    int depth;
};

int solution(vector<string> board) {
    int answer = -1;
    bool find = false;
    queue<Node> q;
    bool visit[100][100] = { };
    
    for(int p = 0; p < board.size(); ++p)
    {
        for(int k = 0; k < board[0].size(); ++ k)
        {
            if (board[p][k] == 'R')
            {
                q.push(Node{p, k, DIR::NON, 0}); 
                find = true;
                break;
            }
        }
        if (find) break;
    }
    
    while(q.size())
    {
        Node cur = q.front(); q.pop();
        
        if (board[cur.i][cur.j] == 'G' && (answer < 0 || answer > cur.depth))
        { 
            answer = cur.depth; continue; 
        }
        
        if (answer > 0 && cur.depth >= answer) continue;
        
        int move = 0;
        if (cur.dir != DIR::UP)       //내려가기
        {
            while(cur.i + move + 1 < board.size() && board[cur.i + move + 1][cur.j] != 'D')
                ++ move;
            if (move && !visit[cur.i + move][cur.j]) 
            {
                q.push(Node{cur.i + move, cur.j, DIR::DOWN, cur.depth + 1});
                visit[cur.i + move][cur.j] = true;
            }
        }
        
        if (cur.dir != DIR::DOWN)     //올라가기
        {
            move = 0;
            while(cur.i + move - 1 >= 0 && board[cur.i + move - 1][cur.j] != 'D')
                -- move;
            if (move && !visit[cur.i + move][cur.j])
            {
                q.push(Node{cur.i + move, cur.j, DIR::UP, cur.depth + 1});
                visit[cur.i + move][cur.j] = true;
            }
        }
        
        if (cur.dir != DIR::LEFT)     //오른쪽
        {
            move = 0;
            while(cur.j + move + 1 < board[0].size() && board[cur.i][cur.j + move + 1] != 'D')
                ++ move;
            if (move && !visit[cur.i][cur.j + move])
            {
                q.push(Node{cur.i, cur.j + move, DIR::RIGHT, cur.depth + 1});
                visit[cur.i][cur.j + move] = true;
            }
        }
        
        if (cur.dir != DIR::RIGHT)    //왼쪽
        {
            move = 0;
            while(cur.j + move - 1 >= 0 && board[cur.i][cur.j + move - 1] != 'D')
                -- move;
            if (move && !visit[cur.i][cur.j + move])
            {
                q.push(Node{cur.i, cur.j + move, DIR::LEFT, cur.depth + 1});
                visit[cur.i][cur.j + move] = true;
            }
        }
    }

    return answer;
}