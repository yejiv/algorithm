#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
using namespace std;

unordered_set <int> table;
unordered_set <int> answer;
bool b[7] = { false };

void f(int goal, int depth, string& numbers, string curNum)
{
    if (goal == depth)
    {
        if (table.end() != table.find(stoi(curNum))) { answer.insert(stoi(curNum)); }
        return;
    }
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        if (b[i] == true) continue;
        if (depth == 0 && numbers[i] == '0') continue;
        b[i] = true;
        f(goal, depth + 1, numbers, curNum + numbers[i]);
        b[i] = false;
    }
}

int solution(string numbers) {
    
    sort(numbers.begin(), numbers.end(), greater<>());
    
    int num = stoi(numbers);
    vector<bool> v(num + 1, false);
    
    for(int i = 2; i <= num; ++i)
    {
        if (v[i] == false)
        {
            table.insert(i);
            for(int j = 1; i * j <= num; ++j)
                v[i * j] = true;
        }
    }
    
    for(int i = 1; i <= numbers.size(); ++i)
        f(i, 0, numbers, "");
    
    return answer.size();
}