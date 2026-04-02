#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string word) {
    int answer = 0;
    string curword = "";
    unordered_map<char, char> table;
    
    table['A'] = 'E';
    table['E'] = 'I';
    table['I'] = 'O';
    table['O'] = 'U';
    table['U'] = 'A';
    
    while(curword != word)
    {
        if (curword.size() < 5)
            curword += "A";
        else
        {
            curword.back() = table[curword.back()];
            while(curword.back() == 'A')
            {
                curword.pop_back();
                curword.back() = table[curword.back()];
            }   
        }
        ++ answer;
    }
    return answer;
}
