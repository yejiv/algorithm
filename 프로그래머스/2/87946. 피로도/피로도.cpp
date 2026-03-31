#include <string>
#include <vector>
#include <map>
using namespace std;

static int answer = 0;
bool visit[8] { false };

void f(int depth, int k, vector<vector<int>>& dungeons)
{
    for(int i = 0; i < dungeons.size(); ++i)
    {
        if (visit[i] == false && dungeons[i][0] <= k)
        {
            visit[i] = true;
            if (depth > answer) answer = depth;
            if (depth == dungeons.size()) return; 
            else if (depth <  dungeons.size())  f(depth + 1, k - dungeons[i][1], dungeons);
            visit[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    f(1, k, dungeons);
    return answer;
}