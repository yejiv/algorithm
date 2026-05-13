#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = *max_element(board[0].begin(), board[0].end());
    
    for(int i = 1; i < board.size(); ++i)
    {
        for(int j = 1; j < board[0].size(); ++j)
        {
            if (!board[i][j]) continue;
            board[i][j] += (min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1])));
            if (answer < board[i][j]) answer = board[i][j];
        }
    }
    
    return answer * answer;
}