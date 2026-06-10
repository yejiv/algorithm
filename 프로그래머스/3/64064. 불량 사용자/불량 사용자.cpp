#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> answer;

bool check(const string& src, const string& dst)
{
    if (src.size() != dst.size()) return false;
    
    for(int i = 0; i < src.size(); ++i)
        if (dst[i] != '*' && src[i] != dst[i])
            return false;
    
    return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id, int depth, int mask)
{
    if (depth == banned_id.size())
    {
        answer.insert(mask); return;
    }
    
    for(int i = 0; i < user_id.size(); ++i)
    {
        if (!(mask & (1 << i)) && check(user_id[i], banned_id[depth]))
            dfs(user_id, banned_id, depth + 1, mask | (1 << i));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    dfs(user_id, banned_id, 0, 0);
    
    return answer.size();
}