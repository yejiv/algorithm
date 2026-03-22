#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int r[30] = {};
    int lostSize = lost.size();
    
    for(auto & A : reserve)
    {
        if (find(lost.begin(), lost.end(), A) == lost.end())
            r[A - 1] = 1;
        else
            lost[find(lost.begin(), lost.end(), A) - lost.begin()] =  -1;
    }
        
    sort(lost.begin(), lost.end());
        
    for(auto & A : lost)
    {
        if (A == -1)
            continue;
        
        if (A > 1 && r[A - 2])
            r[A - 2] = 0; 
        else if (A < n && r[A])
            r[A] = 0; 
        else
            --answer;
    }
    return answer;
}