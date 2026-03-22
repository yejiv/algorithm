#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int table[10] = {};
    int sizeX = X.size(), sizeY = Y.size();
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    int i = 0, j = 0;
    bool flag = false;
    while(i < sizeX && j < sizeY)
    {
        if (X[i] == Y[j])
        {
            ++ table[X[i] - '0'];
            ++i; ++j;
            flag = true;
        }
        else if (X[i] < Y[j])
            ++ i;
        else
            ++ j;
    }
    
    if (!flag)
        return "-1";
    
    for(int i = 9 ; i >= 0; --i)
    {
        if (i == 0 && !answer.size())
            return "0";
        
        while (table[i] --)
            answer += to_string(i);
    }
    
    return answer;
}