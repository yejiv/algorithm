#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int i = 0, j = 0;
    
    for(auto& goalWord : goal)
    {
        if (cards1[i] == goalWord)
            ++i;
        else if (cards2[j] == goalWord)
            ++j;
        else
            return "No";
    }
    
    return "Yes";
}