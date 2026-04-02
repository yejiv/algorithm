#include <string>
#include <vector>

using namespace std;

static int answer = 0;

void f(vector<int>& numbers, int idx, int curNum, int target)
{
    if (numbers.size() == idx)
    {
        if (curNum == target) ++ answer;
        return;
    }
    
    f(numbers, idx + 1, curNum + numbers[idx], target);
    f(numbers, idx + 1, curNum - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    
    f(numbers, 0, 0, target);
    
    return answer;
}