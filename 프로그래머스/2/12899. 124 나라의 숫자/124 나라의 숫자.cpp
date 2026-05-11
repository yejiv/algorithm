#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n)
    {
        int mod = n % 3;
        n /= 3;
        if (mod == 0)
        {
            mod = 4;
            -- n;
        }
        answer.push_back('0' + mod);
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}