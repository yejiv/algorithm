#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool check(const string & s1, const string & s2)
{
    int count = 0;
    
    for(int i = 0 ; i < s1.size(); ++i)
        if (s1[i] != s2[i]) ++ count;

    return count == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<vector<int>> table(words.size() + 1);
    bool v[51] = {};
    queue<pair<int, int>> q;
    int target_idx = 0;
    
    for(int i = 0; i < words.size(); ++i)
    {
        if (check(begin, words[i]) == true)
            table[0].push_back(i + 1);
        if (words[i] == target)
            target_idx = i + 1;
    }
       
    for(int i = 0; i < words.size(); ++i)
        for(int j = 0; j < words.size(); ++j)
            if (check(words[i], words[j]) == true)
                table[i + 1].push_back(j + 1);
    
    q.push({0, 0});
    
    while(!q.empty())
    {
        int idx = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (idx == target_idx)
        {
            answer = depth; break;
        }
        
        if (v[idx]) continue;
        
        v[idx] = true;
        
        for(int i = 0; i < table[idx].size(); ++i)
            if (!v[table[idx][i]])
                q.push({table[idx][i], depth + 1});
            
    }
    
    return answer;
}