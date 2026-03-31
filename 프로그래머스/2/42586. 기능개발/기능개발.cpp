#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    
    for(int i = 0; i < progresses.size(); ++ i)
        days.push(((100 - progresses[i]) + speeds[i] - 1) / speeds[i]);

    int count = 1;
    int target = days.front();
    days.pop();
    
    while(!days.empty())
    { 
        if (target < days.front())
        {
            answer.push_back(count);
            count = 1;
            target = days.front();
        }
        else ++ count;
        days.pop();
    }
    answer.push_back(count);
    return answer;
}
