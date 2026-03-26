#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> number_table;

    for(int i = 0; i < 9; ++i)
        number_table[discount[i]]++;
    
    for(int i = 0; i < discount.size() - 9; ++i)
    {
        number_table[discount[i + 9]]++;
        bool flag = true;
        for(int j = 0; j < want.size(); ++j)
        {
            if (number_table[want[j]] < number[j])
            { flag = false; break; }
        }
        
        if (flag) ++ answer;
        number_table[discount[i]]--;
    }
    
    return answer;
}