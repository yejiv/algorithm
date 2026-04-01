#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1) ;
    vector<pair<int, int>> stack;
    
    for(int i = 0; i < numbers.size(); ++ i)
    {
        while (!stack.empty() && stack.back().first < numbers[i])
        {
            answer[stack.back().second] = numbers[i];
            stack.pop_back();
        }
        stack.push_back({numbers[i], i});
    }
    
    return answer;
}