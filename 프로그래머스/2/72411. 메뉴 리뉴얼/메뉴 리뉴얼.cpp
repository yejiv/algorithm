#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

void f(vector<string>& orders, int r)
{
    unordered_map<string, int> table;
    int max_value = 0;
    
    for(auto & o : orders)
    {
        if (o.size() < r) continue;
        
        sort(o.begin(), o.end());
        vector<int> mask(o.size(), 1);
        fill(mask.begin(), mask.begin() + r, 0);
        
        do {
            string com = "";
            
            for (int i = 0; i < o.size(); i++)
                if (mask[i] == 0) 
                    com += o[i];
            
            table[com] ++;
            max_value = (table[com] > max_value) ? table[com] : max_value;
            
        } while (next_permutation(mask.begin(), mask.end()));
    }
    
    if (max_value < 2) return;
    
    for(const auto & A : table)
        if (A.second == max_value) answer.push_back(A.first);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(const auto & r : course)
        f(orders, r);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}