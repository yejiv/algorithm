#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string table[] = { "aya", "ye", "woo", "ma"};
    
    for(auto& s : babbling)
    {
        int idx = 0;
        string latestWord = "";
        
        while(true)
        {
            bool flag = false;
            for(int i = 0; i < 4; ++i)
            {
               if (idx == s.find(table[i], idx) && latestWord != table[i])
               {
                   flag = true;
                   latestWord = table[i];
                   idx += latestWord.size();
               }
            }
            if (flag == false)
                break;
            if (idx >= s.size())
            {
                ++answer; break;
            }
        } 
    }
    return answer;
}