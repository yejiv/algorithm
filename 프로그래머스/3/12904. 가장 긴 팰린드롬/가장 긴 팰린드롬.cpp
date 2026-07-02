#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int solution(string s)
{
    int answer=0;
    int m = 0;
    vector<int> dp(s.size(), 1);

    //홀수
    for(int length = 1; length <= s.size() >> 1; ++length)
    {
        for(int i = length; i < s.size() - length; ++i)
        {
            if (s[i - length] == s[i + length] && dp[i] + 2 == length * 2 + 1)
                dp[i] += 2;
        }
    }
    
    m = *max_element(dp.begin(), dp.end());
    fill(dp.begin(), dp.end(), 0);
    
    //짝수
    for(int length = 1; length <= s.size() >> 1; ++length)
    {
        for(int i = length - 1; i < s.size() - length; ++i)
        {
            if (s[i - (length - 1)] == s[i + length] && dp[i] + 2 == length * 2)
                dp[i] += 2;
        }
    }

    return max(m, *max_element(dp.begin(), dp.end()));
}