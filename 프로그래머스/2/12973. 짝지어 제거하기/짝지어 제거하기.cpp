#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{    
    //bool flag = true;
    
    //while (flag && s.size() >= 2)
    //{
    //    flag = false;
    //    
    //    for(int i = 0; i < s.size() - 1; ++i)
    //    {
    //        if (s[i] == s[i + 1])
    //        {
    //            size_t pos;
    //            while ((pos = s.find(string(2, s[i]))) != string::npos) 
    //                s.replace(pos, 2, "");  
    //            flag = true;
    //            break;
    //        }
    //    }
    //}
    
    string temp = "";
    
    for(auto& C : s)
    {
        if (temp.size() && temp.back() == C) temp.pop_back();
        else temp += C;
    }
    
    return temp.size() ? 0 : 1;
}