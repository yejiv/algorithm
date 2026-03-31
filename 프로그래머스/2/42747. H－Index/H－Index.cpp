#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int start_idx = 0;
    int end_idx = 0;
    int size = citations.size();
    
    sort(citations.begin(), citations.end());
    
    for(int i = 0; i < size; ++i)
    {
        if (i >= citations[i]) continue;
    
        int newanswer = (size - i <= citations[i]) ? size - i : citations[i];

        if (newanswer < answer) break;
        answer = newanswer;
    }               
    
    return answer;
}
