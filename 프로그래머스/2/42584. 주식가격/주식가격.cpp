#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<pair<int, int>> table;
        
    for(int i = 0; i < prices.size(); ++i)
    {
         while(!table.empty() && table.back().first > prices[i])
         {
             answer[table.back().second] = i - table.back().second;
             table.pop_back();
         } 
        table.push_back({prices[i], i});
    }
    
    for(auto& A : table)
        answer[A.second] = prices.size() - A.second - 1;
   
    return answer;
}
