#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> answer;
unordered_map<string, vector<pair<string, bool>>> table;

bool f(string depart, int size)
{
    if (answer.size() == size) return true;

    for(int i = 0; i < table[depart].size(); ++i)
    {
        if (table[depart][i].second) continue;
        
        table[depart][i].second = true;
        answer.push_back(table[depart][i].first);
        
        if (f(table[depart][i].first, size)) return true;
        
        table[depart][i].second = false;
        answer.pop_back();
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
        
    for(const auto & A : tickets)
        table[A[0]].push_back({A[1], false});
    
    for(auto & A : table)
        sort(A.second.begin(), A.second.end());
    
    answer.push_back("ICN");
    f("ICN", tickets.size() + 1);
    
    return answer;
}