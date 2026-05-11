#include <string>
#include <vector>

int map[12] = {};
int answer = 0;

using namespace std;

bool check(int col, int row)
{
    for(int i = 0; i < col; ++i)
    {
        if (map[i] == row || (col - i) == abs(row - map[i]))
            return false;
    }
    return true;
}

void dfs(int col, int n)
{
    if (col == n) { ++ answer; return; }
    
    for(int i = 0; i < n; ++i)
    {
        if (col == 0 || check(col, i))
        {
            map[col] = i;
            dfs(col + 1, n);
        }
    }
}

int solution(int n) {
    dfs(0, n);
    return answer;
}