#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> table(n);
    const int dx[3] = { 0, 1, -1};
    const int dy[3] = { 1, 0, -1};
    
    for(auto & A : table)
        A = vector<int>(n, 0);
    
    int count = 1;
    int i = 0;
    int j = 0;
    bool flag = true;
    
    table[0][0] = count++;
    
    while(flag)
    {
        flag = false;
        
        for(int k = 0; k < 3; ++k)
        {
            while (i + dy[k] >= 0 && i + dy[k] < n
                && j + dx[k] >= 0 && j + dx[k] < n
                && !table[i + dy[k]][j + dx[k]])
            {
                flag = true;
                i += dy[k];
                j += dx[k];
                table[i][j] = count ++;
            }
            if (!flag) break;
        }
    }
    
    for(const auto & A : table)
        for(const auto & B : A)
            if (B) answer.push_back(B);

    return answer;
}