#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    unordered_map<string, int> table;
    
    for(const auto & A : gems)
        table[A] = 0;
    
    int num = table.size();
    int idx = 0;
    
    for(int i = 0; i < gems.size(); ++i)
    {
        if (table[gems[i]] == 0) -- num;
        
        ++ table[gems[i]];
        
        if (num == 0)
        {
            while(idx <= i)
            {
                -- table[gems[idx]];
                if (table[gems[idx]] == 0)
                {
                    if (!answer[1] || answer[1] - answer[0] > i - idx)
                    {
                        answer[0] = idx + 1;
                        answer[1] = i + 1;
                    }
                    ++ num;
                    ++idx;
                    break;
                }
                ++idx;
            }
        }
    }
    
    return answer;
}