#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    string answer = ""; 
    int tmp;
    n %= 26;
    
    for(int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            answer += ' '; continue;
        } 
        
        tmp = (int)s[i] + n;
        
        if ((s[i] >= 'A' && s[i] <= 'Z') && !(tmp >= 'A' && tmp <= 'Z'))
             answer += 'A' + (tmp - 'Z') % 26 - 1;
        else if((s[i] >= 'a' && s[i] <= 'z') && !(tmp >= 'a' && tmp <= 'z'))
             answer += 'a' + (tmp - 'z') % 26 - 1;
        else
             answer += tmp;
    }
    return answer;
}