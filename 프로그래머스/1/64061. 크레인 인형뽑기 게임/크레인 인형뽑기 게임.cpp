#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector <int> bucket;
    int size = board.size();
    
    for(auto& A : moves)
    {
        for(int i = 0; i < size; ++i)
        {
            if (board[i][A - 1])
            {
                bucket.push_back(board[i][A - 1]);
                board[i][A - 1] = 0;
                break;
            }
        }
        
        if (bucket.size() > 1 && bucket[bucket.size() - 1] == bucket[bucket.size() - 2])
        {
            bucket.pop_back();
            bucket.pop_back();
            answer += 2;
        }
    }
    
    return answer;
}