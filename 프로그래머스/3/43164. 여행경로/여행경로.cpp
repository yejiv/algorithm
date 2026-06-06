#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<string>> table;
    stack<string> s;
    
    for(const auto & A : tickets)
        table[A[0]].push_back(A[1]);
    
    for(auto & A : table)
        sort(A.second.begin(), A.second.end(), greater<>());
    
    s.push("ICN");
    
    while(!s.empty())
    {
        string cur = s.top();
        
        if (table[cur].empty())
        {
            answer.push_back(cur);
            s.pop();
        }
        else
        {
            s.push(table[cur].back());
            table[cur].pop_back();
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}