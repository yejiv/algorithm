#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int hight = board.size();
    int width = board[0].size();
    
    for(int k = 0; k < 4; ++k)
    {
        int nx = w + dx[k];
        int ny = h + dy[k];
        
        if (nx < 0 || ny < 0 || nx >= width || ny >= hight) continue;
        if (board[h][w] == board[ny][nx]) ++ answer;
    }
    
    return answer;
}