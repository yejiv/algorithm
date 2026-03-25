#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int open(0);
    
    for(auto& A : s)
    {
        if (A == '\(')
            ++open;
        else
        {
            if (0 == open) return false;
            else --open;
        }
    }

    return (open > 0) ? false : true;
}