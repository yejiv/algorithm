#include <string>
#include <vector>

using namespace std;

int check(const vector<string>& place)
{
    int dx[12] { 1, -1, 0, 0, 1, 1, -1, -1, 2, -2, 0, 0};
    int dy[12] { 0, 0, 1, -1, 1, -1, 1, -1, 0, 0, 2, -2};
    
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)  
        {
            if (place[i][j] != 'P')
                continue;
            
            for(int k = 0; k < 12; ++k)
            {
                int nx = j + dx[k];
                int ny = i + dy[k];
                
                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || place[ny][nx] != 'P') 
                    continue;
                
                if (k < 4) return 0;
                else if (k < 8)
                {
                    if (place[ny][j] != 'X' || place[i][nx] != 'X')
                        return 0;
                }
                else
                {
                    if (place[i + dy[k - 8]][j + dx[k - 8]] != 'X')
                        return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(const auto & place : places)
        answer.push_back(check(place));
    
    return answer;
}