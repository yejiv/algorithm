#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool check(string& s1, string& s2)
{
    int count = 0;
    
    for(int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]) ++ count;
    
    return (count > 1) ? false : true;
}

int solution(string begin, string target, vector<string> words) {
    unordered_map<string, vector<string>> table;
    queue<pair<string, int>> q;
    unordered_set<string> v;
    
    words.push_back(begin);
    
    for(int i = 0; i < words.size() - 1; ++i)
    {
        for(int j = i + 1; j < words.size(); ++j)
        {
            if (check(words[i], words[j]))
            {
                table[words[i]].push_back(words[j]);
                table[words[j]].push_back(words[i]);
            }
        }
    }
    
    q.push({begin, 0});

    while(!q.empty())
    {
        string s = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (s == target) return depth;
        if (v.find(s) != v.end()) continue; //있다. 이미 방문.
        
        v.insert(s);
        
        for(const auto & A : table[s])
            if (v.find(A) == v.end()) 
                q.push({A, depth + 1});
    }

    return 0;
}