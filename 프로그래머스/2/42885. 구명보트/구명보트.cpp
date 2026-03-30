#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int start_idx = 0;
    int end_idx = people.size() - 1;
    int answer = 0;
    
    sort(people.begin(), people.end());

    while(start_idx <= end_idx)
    {
        if(people[start_idx] + people[end_idx] <= limit)
            ++ start_idx; 
        -- end_idx;
        ++ answer;
    }
        
    return answer;
}