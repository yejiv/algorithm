#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<char>> table(n, vector<char>(m));
    set<pair<int,int>> rm;
    bool flag = true;
    
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) 
            table[i][m - j - 1] = board[j][i];

    while(flag)
    {
        flag = false;
        rm.clear();
        
        for(int i = 0; i < n - 1; ++i)
        {
            for(int j = 0; j < m - 1; ++j)
            {
                if (table[i][j] != '*'
                    && table[i][j] == table[i][j + 1]
                    && table[i][j] == table[i + 1][j]
                    && table[i][j] == table[i + 1][j + 1])
                {
                    rm.insert({i, j});
                    rm.insert({i + 1, j});
                    rm.insert({i, j + 1});
                    rm.insert({i + 1, j + 1}); 
                }
            }
        }

        for(auto & A : rm)
        {
            flag = true;
            table[A.first][A.second] = '*';
            ++answer;
        }

        for(auto & A : table) 
            stable_partition(A.begin(), A.end(), [](char c) { return c != '*'; }); 

    }

    return answer;
}