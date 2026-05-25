#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool f(const string & skill, int idx, const string & s, int end_idx)
{
    if (idx < 0)
        return true;
    
    const auto it = find(s.begin(), s.begin() + end_idx, skill[idx]);
    
    if (it == s.begin() + end_idx) 
        return false;
    
    return f(skill, idx - 1, s, it - s.begin());
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(const auto & A : skill_trees)
    {
        bool flag = false;
        for(int i = skill.size() - 1; i >= 0; --i)
        {
            const auto it = find(A.begin(), A.end(), skill[i]);
            if (it != A.end())
            {
                answer += f(skill, i - 1, A, it - A.begin());
                flag = true;
                break;
            }
        }
        if (!flag) ++ answer;
    }
    
    return answer;
}