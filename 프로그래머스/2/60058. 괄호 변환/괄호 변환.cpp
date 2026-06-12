#include <string>
#include <vector>
using namespace std;

bool divide (const string& p, string& u, string& v)
{
    bool isRight = true;
    int cal = 0;
    for(int i = 0; i < p.size(); ++i)
    {   
        cal = (p[i] == '(') ? cal + 1 : cal - 1;
        
        if (cal < 0) isRight = false;
        
        u += p[i];
        
        if (!cal) break;
    }
    
    v = p.substr(u.size());
    
    return isRight;
}

string solution(string p) {
    
    if (p.empty()) return "";

    string answer = "";
    int s = 0;
    string u = "";
    string v = "";
    
    bool isRight = divide(p, u, v);
    
    if (isRight)
        return u + solution(v);
    else
    {
        string answer = "(" + solution(v) + ")";
        
        for(int i = 1; i < u.size() - 1; ++i)
            answer += (u[i] == '(') ? ')' : '(';
        
        return answer;
    }
}