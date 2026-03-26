#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 1;
    int memo[2];
    
    memo[0] = 1;
    memo[1] = 1;
    
    for(int i = 2; i < n + 1; ++i)
    {
        answer = (memo[0] + memo[1])% 1234567;
        memo[0] = memo[1];
        memo[1] = answer;
    }
    
    return answer;
}