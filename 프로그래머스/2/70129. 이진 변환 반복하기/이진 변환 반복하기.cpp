#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    
    while(s != "1")
    {
        int cnt = std::count(s.begin(), s.end(), '0');
        s.erase(remove(s.begin(),s.end(),'0'),s.end());
        answer[1] += cnt;
        
        int num = s.size();
        s = "";
        while(num)
        {
            s = to_string(num % 2) + s;
            num /= 2;
        }
        
        ++ answer[0];
    }
    
    return answer;
}