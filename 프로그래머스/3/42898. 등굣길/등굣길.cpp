#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {    
    
    int map [100][100] = {0};
    
    for(auto & A : puddles) map[A[0] - 1][A[1] - 1] = -1;
    
    map[0][0] = 1;
    
    for(int i = 0; i < m; ++i)
    {
       for(int j = 0; j < n; ++j)
       {
           if (map[i][j] == -1) continue;
           if (i > 0 && map[i - 1][j] != -1) map[i][j] = map[i - 1][j];
           if (j > 0 && map[i][j - 1] != -1) map[i][j] += map[i][j - 1];
           map[i][j] %= 1000000007;
       }
    }
    
    return map[m - 1][n - 1];
}