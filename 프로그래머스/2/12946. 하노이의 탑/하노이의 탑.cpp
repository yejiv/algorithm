#include <string>
#include <vector>

using namespace std;

void f(vector<vector<int>>& answer, int n, int start, int target, int other)
{
    if (n == 0) return;
    f(answer, n - 1, start, other, target);
    answer.push_back({start, target});
    f(answer, n - 1, other, target, start);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    f(answer, n, 1, 3, 2);
    
    return answer;
}