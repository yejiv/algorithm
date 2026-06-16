#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2)
{
    if (v1[0] != v2[0]) return  v1[0] > v2[0];
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    int max_score = 0;
    vector<int> rank;
    int wanho[2] { scores[0][0], scores[0][1] };
    
    sort(scores.begin(), scores.end(), cmp);
    
    for(int i = 0; i < scores.size(); ++i)
    {
        if (scores[i][1] >= max_score)
        {
            max_score = scores[i][1];
            if (wanho[0] + wanho[1] < scores[i][0] + scores[i][1])
                ++ answer;
        }
        else if (wanho[0] == scores[i][0] && wanho[1] == scores[i][1])
            return -1;
    }
    
    return answer + 1;
}