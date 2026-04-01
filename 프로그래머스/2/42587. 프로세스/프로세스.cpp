#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size();
    deque<int> priorities_deque(size);
    
    for(int i = 0; i < size; ++i)
        priorities_deque[i] = priorities[i];
        
    sort(priorities.begin(), priorities.end(), greater<>());

    while(!priorities_deque.empty())
    {
        while(priorities_deque.front() < priorities[answer])
        {
           priorities_deque.push_back(priorities_deque.front());
           priorities_deque.pop_front(); 
           location = (location > 0) ?  ( location - 1 ) : ( priorities_deque.size() - 1 );
        }
        if (location == 0) break;
        else { ++ answer; priorities_deque.pop_front(); -- location; }
    }
    
    return answer + 1;
}
