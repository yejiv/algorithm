#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    string s = "";    
    string sAnswer = "";

    while(n)
    {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    
    int pos = 0;
    
    if((pos = s.rfind("01")) != string::npos)
    {
        swap(s[pos], s[pos + 1]);
        sAnswer = s.substr(0, pos + 2);
        sAnswer += string(count(s.begin() + pos + 2, s.end(), '0'), '0');
        sAnswer += string(count(s.begin() + pos + 2, s.end(), '1'), '1'); 
    }
    else 
    {
        sAnswer = "10" + string(count(s.begin() + 1, s.end(), '0'), '0');
        sAnswer += string(count(s.begin() + 1, s.end(), '1'), '1'); 
    }
    
    return stoi(sAnswer, nullptr, 2);
}