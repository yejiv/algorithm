#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    int start_idx = 1;
    int end_idx = 1;
    int curN = 1;
    
    while(end_idx <= n)
    {
        if (curN < n)  curN += ++ end_idx; 
        else if (curN > n) curN -= start_idx ++; 
        else
        {
            ++answer; curN += ++ end_idx; 
        }
    }
    
    return answer;
}