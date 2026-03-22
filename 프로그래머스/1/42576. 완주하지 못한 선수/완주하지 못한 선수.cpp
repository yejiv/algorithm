#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int num = participant.size();
    
    sort(participant.begin(), participant.end());    
    sort(completion.begin(), completion.end());

    for (int i = 0; i < num - 1; ++i)
    {
        if (participant[i] != completion[i])
            return participant[i];
    }
    
    return participant[num - 1];
}