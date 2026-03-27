#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); ++i)
    {
        s = s.back() + s; s.pop_back();
        
        vector <char> table;
        bool flag = true;
        for(auto& A : s)
        {
            switch(A)
            {
                case ']' :
                    if (table.empty() || table.back() != '[') flag = false;
                    table.pop_back(); break;
                case ')' :
                    if (table.empty() || table.back() != '(') flag = false;
                    table.pop_back(); break;
                case '}' :
                    if (table.empty() || table.back() != '{') flag = false;
                    table.pop_back(); break;
                default : 
                    table.push_back(A);
            }
            
            if (!flag) break;
        }
        if (flag && table.size() == 0) ++ answer;
    }
    
    return answer;
}