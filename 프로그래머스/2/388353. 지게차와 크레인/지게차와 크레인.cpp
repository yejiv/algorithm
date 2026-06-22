#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void Crane(vector<string>& board, char target, int& answer) 
{
    int height = board.size();
    int width = board[0].size();
    
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
            if (board[i][j] == target) {
                board[i][j] = '.';
                answer--;
            }
        }
    }
}

void Forklift(vector<string>& board, char target, int& answer) {
    int height = board.size();
    int width = board[0].size();
    
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    queue<pair<int, int>> q;
    vector<pair<int, int>> to_remove; 
    
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) 
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
            if (visited[ny][nx]) continue;
            
            if (board[ny][nx] == '.') 
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            } 
            
            else if (board[ny][nx] == target) 
            {
                // 외부와 맞닿아 있는 타겟을 발! (큐에 넣지는 않고 삭제 목록에만 추가)
                visited[ny][nx] = true; 
                to_remove.push_back({ny, nx});
            }
        }
    }
    
    for (const auto& pos : to_remove) 
    {
        board[pos.first][pos.second] = '.';
        answer--;
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = storage.size() * storage[0].size();
    
    int height = storage.size() + 2;
    int width = storage[0].size() + 2;
    vector<string> board(height, string(width, '.'));
    
    for (int i = 0; i < storage.size(); ++i) 
    {
        for (int j = 0; j < storage[0].size(); ++j) 
        {
            board[i + 1][j + 1] = storage[i][j];
        }
    }
    
    for (const string& req : requests) 
    {
        if (req.size() == 2) 
            Crane(board, req[0], answer);
        else 
            Forklift(board, req[0], answer);
    }
    
    return answer;
}