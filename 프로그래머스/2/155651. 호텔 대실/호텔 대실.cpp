#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(vector<vector<string>> book_time) {
    multimap<int, int> table;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < book_time.size(); ++i)
    {
        int s = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3));
        int e = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3));
        table.insert({s, e});
    }
    
    for(auto& A : table)
    {
        if (pq.size() && pq.top() + 10 <= A.first)
            pq.pop();
        pq.push(A.second);
    }
    
    return pq.size();
}