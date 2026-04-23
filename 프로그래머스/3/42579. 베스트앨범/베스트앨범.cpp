#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, priority_queue<pair<int, int>>> table;
    unordered_map<string, int> sum;
    vector<pair<int, string>> rank;
    
    for(int i = 0; i < genres.size(); ++i)
    {
        table[genres[i]].push({plays[i], i});
        sum[genres[i]] += plays[i];
    }
    
    for(auto & A : sum) rank.push_back({A.second, A.first});
    
    sort(rank.begin(), rank.end(), greater<>());
    
    for(auto & A : rank)
    {
        if (table[A.second].size() == 1) { answer.push_back(table[A.second].top().second); continue; }
        
        pair<int,int> t[2];
        t[0] = table[A.second].top(); table[A.second].pop();
        t[1] = table[A.second].top();
        if (t[0].first == t[1].first && t[0].second > t[1].second) swap(t[0], t[1]);
        answer.push_back(t[0].second);
        answer.push_back(t[1].second);
    }
    
    return answer;
}